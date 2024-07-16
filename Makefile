#obj-m +=hello.o

#obj-m += hello1.o
#obj-m += p5.o
#obj-m += p5.o
#obj-m +=prat.o
#obj-m +=try.o
#obj-m += user.o

#obj-m +=hello1.o
#obj-m +=hello2.o
#obj-m += hello3.o
#obj-m += hello4.o
#obj-m += hello5.o
#obj-m +=hello6.o
#obj-m +=hello6a.o
#obj-m +=hello6b.o
#obj-m += fop1.o
#obj-m += fop4.o
#obj-m +=fop5.o
#obj-m += fop6.o
#obj-m += fop7.o
#obj-m +=fop8.o
#obj-m +=fop9.o
#obj-m += fop9.o
#obj-m +=fop10.o
#obj-m +=fop11.o
#obj-m +=fop12.o


#obj-m += hello20.o
#obj-m += hello21.o
#obj-m +=hello22.o
#obj-m += hello23.o
#obj-m +=hello24.o
#obj-m +=hello26.o
#obj-m += hello27.o
obj-m +=hello28.o
PWD:= $(CURDIR)

all:
		make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)  clean 
