CC=gcc
FLAGS=-Wall -g
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o
AR=ar



progmain: main.o myBank.o 
	$(CC) $(FLAGS) -o main.o myBank.o

main.o: main.c myBank.c
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

libmyBank.a: $(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)

progmaind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) libmyBank.a 


.PHONY: clean all

all: libmyBank.a progmaind 

clean: 
	rm -f progmain *.o *.a progmains 