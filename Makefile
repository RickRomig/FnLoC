CC = gcc
.PHONY = all clean
# make lloc to compile lloc.

all : fnloc lloc

fnloc : fnloc.o
	$(CC) -o fnloc fnloc.o

fnloc.o : fnloc.c fnloc.h
	$(CC) -c fnloc.c

lloc : lloc.o
	$(CC) -o lloc lloc.o

lloc.o : lloc.c fnloc.h
	$(CC) -c lloc.c

clean :
	rm -v *~
	rm -v *.o

