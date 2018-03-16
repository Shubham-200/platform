#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main( void )
{
	int fd ;
	char wbuf[10] = "nikhilvg";
	char rbuf[1024 * 1024];
	int res = 0;

	fd = open( "/dev/simple_driver",  O_RDWR );

	if( fd < 0 ) 
	{	
		printf(" Cannot open file\n");
		return 0;
	}
	
	res = write(fd, wbuf, 8);
	
	if(!res){
		printf("Write failure\n");
	} 
	else {
		printf("%7s written\n",wbuf);
	}
	res = 0;
	if( (res = lseek(fd, 0, SEEK_SET)) < 0) {
		printf("ERROR : lseek error\n");
	}
	res = 0;
	res = read(fd, rbuf, 100);
	if( !res) {
		printf("Read failure\n");
	}	
	else { 
		printf("%d bytes read \"%s\"\n",res,rbuf);
	}
	close(fd);
	return 0;
}

