CC = gcc
.PHONY = all clean
# make file for fnloc and lloc.

all : fnloc lloc

fnloc : fnloc.o lstates.o
	$(CC) fnloc.o lstates.o -o fnloc

fnloc.o : fnloc.c fnloc.h lstates.h
	$(CC) -c fnloc.c

lstates.o : lstates.c lstates.h
	$(CC) -c lstates.c

lloc : lloc.o lstates.o
	$(CC) lloc.o lstates.o -o lloc

lloc.o : lloc.c lloc.h lstates.h
	$(CC) -c lloc.c

clean :
	rm -f *.o fnloc lloc *~
