obj-m := plp_kmem.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

# Comment/uncomment the following line to disable/enable debugging
DEBUG = y
# Add your debugging flag (or not) to CFLAGS
ifeq ($(DEBUG),y)
DEBFLAGS = -O -g -DPLP_DEBUG # "-O" is needed to expand inlines
else
DEBFLAGS = -O2
endif
ccflags-$(DEBUG) += $(DEBFLAGS)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean :
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_plp_kmem
