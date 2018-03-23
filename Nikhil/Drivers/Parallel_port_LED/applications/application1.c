#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main( void )
{
	int fd ;
	char data = 0x00;
	int res = 0;
	unsigned char s1;
	signed char s2;
	int i = 0;
	fd = open( "/dev/LED_driver",  O_RDWR );

	if( fd < 0 ) 
	{	
		printf(" Cannot open file\n");
		return 0;
	}

//********right to left moving************	
	s1 = 0x01;
	while( s1)
	{
		write(fd, &s1, 0);
		s1 = s1 << 1;
		sleep(1);
		
	}
	
//********left to right moving************	
	s1 = 0x80;	
	while( s1)
	{
		write(fd, &s1, 0);
		s1 = s1 >> 1;
		sleep(1);
		
	}
	
//**********alternative led blinking***********
	while( i < 5) {
		s1 = 0xaa;
		write( fd,&s1, 0);
		sleep(1);
		s1 = 0x55;
		write(fd, &s1,0); 
		sleep(1);
		i++;
	}
	s1 = 0;
	write(fd, &s1,0);

//**********led glows from left to right*******	
	s2 = 0x80;
	while ( s2 != 0xff)
	{	
		write(fd, &s2, 0);	
		sleep(1);
		s2 = s2 >>1;
	}
	
//**********Blinking**************
	i = 0;
	while( i < 2) {
		data = 0xff;		
		write( fd, &data, 0);
		sleep(1);
		data = 0x00;
		write(fd, &data,  0);	
		sleep(1);
		i++;
	}

	close(fd);
	return 0;
}

