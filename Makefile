CC=g++
VER=-std=c++11
CFLAGS=-Wall -W -s
OUPUT=-o fcm_algorithm

all: 
	${CC} ${VER} ${CFLAGS} ${OUPUT} src/main.cpp src/fcm.cpp 

clean:
	rm -rf fcm_algorithm
