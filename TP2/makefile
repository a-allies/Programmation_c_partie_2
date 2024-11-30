CC=gcc
CFLAGS= -Wall -Wextra -MMD
LD=gcc
LDFLAGS= -L/usr/local/lib
LIB= -lm

DEBUG= no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif

all: program

program: main.o test.o image.o image-proba.o
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.d
	rm *.o
	rm program

include $(wildcard .d)