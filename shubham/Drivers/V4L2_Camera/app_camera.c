// An application code to capture real-time image using USB Creative VF0520 live camera

#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <linux/videodev2.h>

#define CLEAR(x) memset(&(x), 0, sizeof(x))

struct buffer {
    void *start;
    size_t length;
};

struct v4l2_capability caps = {0};
struct v4l2_format format = {0};
struct v4l2_requestbuffers req = {0};
struct v4l2_buffer buf = {0};
struct buffer *buffers;
int index1; 
int index2;
fd_set fds;
char out_name[256];
FILE *fout;

int capabilities( int fd)
{

    if(( ioctl( fd, VIDIOC_QUERYCAP, &caps)) < 0) {
            perror("VIDIOC_QUERYCAP: \n");
            return 1;
        }
    printf("Driver caps:\n"
            "Driver: %s"
            "Card: %s\n"
            "Bus: %s\n"
            "Capabilities: %08x\n",
            caps.driver,
            caps.card,
            caps.bus_info,
            caps.capabilities);

    CLEAR(format);
    format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    format.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
    format.fmt.pix.width = 640;
    format.fmt.pix.height = 480;
    if((ioctl( fd, VIDIOC_S_FMT, &format)) < 0) {
        perror("VIDIOC_S_FMT");
        return 1;
    }

    return 0;
}


int req_buffer( int fd)
{
    req.count = 500;
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_MMAP;
    if((ioctl( fd, VIDIOC_REQBUFS, &req)) < 0) {
        perror("VIDIOC_REQBUFS: \n");
        return 1;
    }
    
    buffers = calloc(req.count, sizeof(*buffers));
    for (index1 = 0; index1 < req.count; index1++){
        CLEAR(buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = index1;
        if((ioctl( fd, VIDIOC_QUERYBUF, &buf)) < 0) {
            perror("VIDIOC_QUERYBUF: \n");
            return 1;
        }

        buffers[index1].length = buf.length;
        buffers[index1].start = mmap(NULL, buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, buf.m.offset);
    }
    printf("Length: %d \n",
            buf.length);
    printf("Image length = %d\n", buf.bytesused);

    return 0;
}


int capture_image( int fd)
{
    //int flag = 1;
    int r;

    for(index2 = 0; index2 < index1; index2++){
        CLEAR(buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = index2;
        if ((ioctl( fd, VIDIOC_QBUF, &buf)) < 0) {  
            perror("VIDIOC_QBUF:\n");
            return 1;
        }
    }

    if ((ioctl( fd, VIDIOC_STREAMON, &buf.type)) < 0) {
        perror("VIDIOC_STREAMON: \n");
        return 1;
    }

    for (index2 = 0; index2 < 2; index2++) {
        do{
            FD_ZERO( &fds);
            FD_SET(fd, &fds);

            struct timeval tv = {0};
            tv.tv_sec = 2;
            tv.tv_usec = 0;
            r = select(fd+1, &fds, NULL, NULL, &tv);
        }while(r == -1);
   
        if( r == -1){
            perror("Select failed: \n");
            return 1;
        }

        CLEAR(buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;

        if((ioctl(fd, VIDIOC_DQBUF, &buf)) < 0) {
            perror("VIDIOC_DQBUF failed: \n");
            return 1;
        }
        
        printf("Saving Image \n");

        sprintf(out_name, "out%d.jpg", index2);
        fout = fopen(out_name, "w");
        if(fout < 0){
            perror("file opening for .jpg failed: \n");
            return 1;
        }

        printf("Buf.index = %d\n", buf.index);
        if((fwrite(buffers[buf.index].start, buf.bytesused, 1, fout)) < 0) {
            perror(" Writing in buffer failed: \n ");
            return 1;
        }
        
        fclose(fout);

        if((ioctl( fd, VIDIOC_QBUF, &buf)) < 0) {
            perror("VIDIOC_QBUF failed at end: \n");
            return 1;
        }
    }

    if((ioctl( fd, VIDIOC_STREAMOFF, &buf.type)) < 0) {
        perror("VIDIOC_STREAMOFF failed; \n");
        return 1;
    }

    for (index2 = 0; index2 < index1; index2++)
      munmap(buffers[index2].start, buffers[index2].length);

    return 0;
}

int main(int argc, char *argv[])
{
    int fd;
    int index;
    char *devname = "/dev/video0";

    fd = open( devname, O_RDWR);
    if (fd == -1) {
        perror("File descriptor error: \n");
        return 1;
    }

    if (capabilities( fd)) {
        printf("Capabilities failed: \n");
        return 1;
    }

    if (req_buffer( fd)) {
        printf("Buffer failed: \n");
        return 1;
    }

/*    
    for (index = 0; ; index++) {
        if (!(capture_image( fd))) {
            printf("Capture success: \n");
            break;
        }
*/

    if(capture_image( fd)) {
        printf("Capture Image failed: \n");
        return 1;
    }
   
    if((close(fd)) < 0)
            printf("Device closed: \n");

    return 0;
}
