CC=gcc
CFLAGS=-std=c99
OBJECTS=test.o
LIB_DIR=./lib

default:test

test:${OBJECTS} library
	${CC} -o $@ ${OBJECTS} -L${LIB_DIR} -lrsa
		
library:
	${MAKE} -C ${LIB_DIR}

.PHONY:clean
clean:
	${MAKE} -C ${LIB_DIR} clean
	-rm ${OBJECTS} test
