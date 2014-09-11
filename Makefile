CC = gcc
CFLAGS = $(WARNINGS) $(DEBUG) $(DEFINE)
DEBUG = -g
#DEFINE = -DHASH_TABLE_SIZE=$(SIZE)
WARNINGS = -ansi -pedantic -Wall -Wextra -D__USE_FIXED_PROTOTYPES__ --std=c89
OBJ = main.o makearg.o
#LIBS = -lncurses
APPLICATION_NAME = tok

.PHONY : all rebuild clean

all : $(APPLICATION_NAME)

rebuild :
	make clean
	make all

$(APPLICATION_NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(APPLICATION_NAME) $(LIBS)

main.o : main.c makearg.h
	$(CC) $(CFLAGS) -c main.c $(LIBS)

makearg.o : makearg.h
	$(CC) $(CFLAGS) -c makearg.c $(LIBS)

clean :
	rm -f $(APPLICATION_NAME) $(OBJ)
