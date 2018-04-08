#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	unsigned int buf[6];	
	int index;
	char axis[3] = {'X', 'Y', 'Z'};

	fd = open("/dev/mpu6050", O_RDWR);

	if(fd < 0)
		perror("Unable to open the device \n");
	else
	{
		printf("file opened successfully\n");
		if(read(fd, buf, 24) < 0)
		{
			perror("Read failed in user application\n");
			exit(EXIT_FAILURE);
		}

		for(index = 0; index < 6; index++)	
		{
			if(index >= 0 && index < 3)
			{	
/*				if(buf[index] <= -131 ||  buf[index] >= 131)
				{
					perror("Gyrometer reading out of range\n");
					exit(EXIT_FAILURE);
				}
				else*/
					printf("buf[%d] -> %x\n", index, buf[index]);
					printf("Accelerometer = %c --> %f\n", axis[index], buf[index]/16384.0);
			}
			else
			{
			/*	if(buf[index] <= -16384 || buf[index] >= 16384)
				{
					perror("Accelerometer reading out of range\n");
					exit(EXIT_FAILURE);
				}
				else*/
					printf("buf[%d] -> %x\n", index, buf[index]);
					printf("Gyrometer = %c --> %f\n", axis[index - 3], buf[index]/131.0);
			}
		}	
}
//	write(fd,buf,1);
//	close(fd);
	
//	fd = open("/dev/mpu6050", O_RDWR);
/*
		printf("file opened successfully\n");
		printf("Actual values\n");
		if(read(fd, buf, NULL) < 0)
		{
			perror("Read failed in user application\n");
			exit(EXIT_FAILURE);
		}

		for(index = 0; index <= 6; index++)	
		{
			if(index >= 0 && index <= 3)
			{	
					printf("Gyro = %c --> %f\n", axis[index], buf[index]/131.0);
			}
				else
					printf("Acc = %c --> %f\n", axis[index - 3], buf[index]/16384.0);
		}
	}*/
	return 0;
}
