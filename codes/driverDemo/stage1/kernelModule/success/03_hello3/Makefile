obj-m += hello3.o
default:
	make -C /usr/src/linux-headers-`uname -r` SUBDIRS=$(PWD) modules
