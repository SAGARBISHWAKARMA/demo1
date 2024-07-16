
#obj-m += 6.o
#obj-m += 4.o
#obj-m += 1.o
#obj-m += 2.o
#obj-m += 5.o
#obj-m += 3.o
#obj-m += 7.o
#obj-m += prat.o
#obj-m +=11.o
#obj-m +=81.o
#obj-m +=811.o
#obj-m +=14.o
#obj-m +=17.o
#obj-m +=10.o
obj-m +=9.o
#obj-m +=16.o
#obj-m +=13.o
#obj-m += hello.o
#obj-m += 111.o
#obj-m += 11a.o

DIR ?= /lib/modules/$(shell uname -r)/build

PWD := $(shell pwd)

all:
	$(MAKE) -C $(DIR) M=$(PWD) modules


clean:
	$(MAKE) -C $(DIR) M=$(PWD) clean
