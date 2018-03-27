
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


int byte_read(int fd, unsigned char addr, unsigned char *data)
{
    unsigned char buf[2];

    buf[0] = addr;
    if (write(fd, buf, 1) < 0) {
            printf("Error:In calling Write\n");
            return -1;
    }

    if (( read(fd, &buf[1], 1)) != 1) {
        printf("Error:Read failed \n");
        return -1;
    }

    *data = buf[1];
    return 1;
}


int byte_write(int fd, unsigned char addr, unsigned char data)
{
    unsigned char buf[2];

    buf[0] = addr;
    buf[1] = data;
    if (write(fd, buf, 2) < 0) {
            printf("Error:In calling Write\n");
            return -1;
    }

    return 1;
}

int main(void)
{
	unsigned char addr, data, rdata;
    unsigned char buf2[256];
	unsigned char buf3[1] = { 0x00 };

	char *ptr = NULL;
	int fd, count, i;

    if ((fd = open(FILE_NAME, O_RDWR)) < 0) {
        perror("open");
        printf("Error:Failed open %s\n", FILE_NAME);
        exit(1);
    }

    printf("file opened successfully\n");

	
	ptr = (char *) malloc(sizeof(char) * 5);
	if( ptr == NULL){
		perror("Malloc error");
		return 0;
	}

	addr = 0;
	data = 0;
	
	printf("Enter the address := ");
	if( NULL == fgets( ptr, 5, stdin)) {
		perror("fgets error");
		return 0;
	}


	
	addr = atoi(ptr);
	
	printf("Enter the data(1 byte ) to be placed on %x:= ", addr);	
		if( NULL == fgets( ptr, 5, stdin)) {
		perror("fgets error");
		return 0;
	}


	data = atoi(ptr);
    if( byte_write(fd, addr, data) < 0  ) {
        printf("Byte write failed \n");
    }

    if(byte_read(fd, addr, &rdata) < 0) {
        printf("Byte read failed \n");
    }

    printf(" One byte read for %x := %x", addr, rdata);
	
	printf("\n");

    printf(" Printing Recieved data\n");
	write(fd, buf3, 1);

    if ((count = read(fd, buf2, 256)) <= 0) {
        printf("Error:Read failed \n");
        return 0;
    }
    for (i = 0; i < count; i++) {
        if (!(i % 16))
            printf("\n");
        printf("%02x  ", buf2[i]);
    }	

    close(fd);
	free(ptr);
    printf("\n close completed\n");

    return 0;
}

