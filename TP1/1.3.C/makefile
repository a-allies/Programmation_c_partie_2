CC=gcc
CFLAGS= -Wall -Wextra -MMD
LD=gcc
LDFLAGS= -L/usr/local/lib
LIB= 

DEBUG= no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif

all: program

program: main-exprString.o stack.o test.o evaluation.o evaluationString.o
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.d
	rm *.o
	rm program

include $(wildcard .d)
