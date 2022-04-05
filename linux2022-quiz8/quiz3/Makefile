obj-m += dont_trace.o

KERNELDIR ?= /lib/modules/`uname -r`/build
PWD := $(shell pwd)

all:
		$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
		$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

load:
		sudo insmod dont_trace.ko

unload:
		sudo rmmod dont_trace
