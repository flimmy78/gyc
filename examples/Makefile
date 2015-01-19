DIR_INC = ../include
DIR_NET = ../network
DIR_LIB = ../lib

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o,$(notdir ${SRC}))
EXE = $(patsubst %.c, %.exe,$(notdir ${SRC}))

CC = gcc
INC = -I${DIR_INC} -I${DIR_NET}
CFLAGS = -std=gnu99 -D_GNU_SOURCE ${INC}
LIB = -L${DIR_LIB} -L/usr/local/lib
LFLAGS = ${LIB} -lgycgraph -lgyc -lm

all: ${EXE}

%.exe:%.o
	$(CC) $< $(LFLAGS) -o $@

%.o:%.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

clean:
	-rm ${TARGET}
	-rm *~ *.o *.exe *.ct
