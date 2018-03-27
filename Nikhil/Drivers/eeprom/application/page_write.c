
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
    int fd, count, i, k = 0, j = 0x00;
    unsigned char buf[9];
    unsigned char buf2[256];
    unsigned char buf3[1] = { 0x00 };

    unsigned char addr;
    unsigned char data;
    unsigned char rdata = 0x00;

    if ((fd = open(FILE_NAME, O_RDWR)) < 0) {
        perror("open");
        printf("Error:Failed open %s\n", FILE_NAME);
        exit(1);
    }

    printf("file opened successfully\n");

    printf("Invoking Write\n");


	printf("Writing 32 page of data(i.e, 256 bytes )\n");
	
    while (k < 256) {
        for (i = 0; i < 9; i++) {
            if (i == 0)
                buf[i] = k;
            else
                buf[i] = j++;

        }
        if (write(fd, buf, 9) < 0)
            printf("Error:In calling Write\n");
        k = k + 8;
    }

    printf(" Writing offset \n");
    write(fd, buf3, 1);

    printf("Invoking Read \n");

    if ((count = read(fd, buf2, 256)) <= 0) {
        printf("Error:Read failed \n");
        return 0;
    }
    printf(" Printing data written\n");

    for (i = 0; i < count; i++) {
        if (!(i % 16))
            printf("\n");
        printf("%02x  ", buf2[i]);
    }

    close(fd);
    printf("\n close completed\n");

    return 0;
}

