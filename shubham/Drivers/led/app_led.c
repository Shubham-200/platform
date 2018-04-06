#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;

	fd = open("/dev/Led", O_RDWR);	

	if(fd)
		printf("File opened succesfully\n");
	else
		printf("Unable to open the device\n");

	char data1 = 0x0f;
	char data2 = 0xf0;
	
	write(fd, &data1, 0);
	write(fd, &data2, 0);

	close(fd);

	return 0;
}
