
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>

#define BLINK   _IOW('a','a',int32_t*)
#define ON_ALL  _IOW('a','b',int32_t*)
#define OFF_ALL _IOW('a','c',int32_t*)
#define A5A5   _IOW('a','d',int32_t*)

int main( void )
{
	int fd ;
	char data = 0x00;
	int res = 0;
	int i = 10;
	fd = open( "/dev/LED_driver",  O_RDWR );

	if( fd < 0 ) 
	{	
		printf(" Cannot open file\n");
		return 0;
	}
	
   	ioctl(fd, A5A5, &i); 

	
	close(fd);
	return 0;
}

