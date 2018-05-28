obj-m:= mpu.o

KDIR:=/home/jyothi/BeagleBone/linux
ARCH:=arm
PWD:= $(shell pwd)
CROSS_COMPILE:=/home/jyothi/BeagleBone/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-

all:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers 
	rm app_mpu	
