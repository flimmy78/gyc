DIR_LAB = ../lib
DIR_INC = ../include
DIR_BIN = ../bin

CC = gcc
SRC = ${wildcard *.c}
OBJ = $(patsubst %.c, %.o,$(notdir ${SRC}))
EXE = $(patsubst %.c, %.exe,$(notdir ${SRC}))
LAB = -L${DIR_LAB}
INC = -I${DIR_INC}
LFLAGS = ${LAB} -lgycgraph -lgycparser -lgyc -lm
CFLAGS = -std=gnu99 -D_GNU_SOURCE ${INC}

all: $(EXE)
	mv *.exe ${DIR_BIN}

%.exe:%.o
	$(CC) $< $(LFLAGS) -o $@

%.o:%.c
	gcc $(CFLAGS) $(DEBUG) -c $< -o $@

clean:
	-rm *~ *.o *.exe *.ct
