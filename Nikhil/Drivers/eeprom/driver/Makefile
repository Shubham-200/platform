obj-m:= eeprom.o

KDIR:=/home/nikhil/Downloads/kernel_porting/linux-4.15.9
ARCH:=arm
PWD:= $(shell pwd)
CROSS_COMPILE:=/opt/gcc-arm-linux/bin/arm-linux-gnueabihf-

all:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers 
