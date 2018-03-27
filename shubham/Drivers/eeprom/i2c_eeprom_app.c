#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_NAME "/dev/eeprom"

int main(void) 
{
	int fd, count, i,k=0,j=0x10;
	unsigned char buf[9];
        unsigned char buf2[256];
        unsigned char buf3[1]={0x00};
	printf(" %s Opened \n", FILE_NAME);
        if ((fd= open(FILE_NAME, O_RDWR)) < 0) {
		perror("open");
		printf("Error:Failed open %s\n", FILE_NAME);
				exit(1);
	}
        printf("Invoking Write\n");
 
        while (k<256)
        {
           for(i=0;i<9;i++) 
           {
	 	if(i==0)
                buf[i]=k;
               	else
              	buf[i]=j++;
      
            }  
	if (write(fd,buf,9)<0)
        printf("Error:In calling Write\n");
	// sleep(1);
        k=k+8;     
        }  
        
	printf(" Writing offset \n");
        write(fd,buf3,1);

/*     for (i = 0; i < 256; i++)
       {
       buf[i] = j+200;
       j++;
       }
       for (i = 0; i < 256; i++)
       {
       if (!(i % 16))
       printf("\n");
       printf("%x\t", buf[i]);
       }
*/
	
/*     if (write(fd,buf,9) > 0) 
       {
       //sleep(1);
       printf(" Writing EEPROM offset \n");	
	//write(fd, buf, 2);
	// for (i = 0; i < 256; i++)
	//	buf[i] = 0;
	} else {
		printf("error: Failed write \n");

	} */
	printf("Invoking Read \n");
                    
        sleep(1);
	if ((count = read(fd, buf2, 256)) <= 0) {
	printf("Error:Read failed \n");
	return 0;
	}
        printf(" Printing Recieved data\n");

	for (i = 0; i < count; i++)
	{
	if (!(i % 16))
		printf("\n");
	printf("%x  ", buf2[i]);
	}

        close(fd);
        printf("\n close completed\n");

   return 0;
}
