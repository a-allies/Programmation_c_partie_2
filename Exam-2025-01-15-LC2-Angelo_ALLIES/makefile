CC=gcc
CFLAGS= -Wall -Wextra -MMD
LD=gcc
LDFLAGS= -L/usr/local/lib
LIB= 

DEBUG= no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif

all: decisionTree_teacher decisionTree

decisionTree_teacher: main_teacher.o decisionTree.o test.o decisionTree_teacher.o 
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@

decisionTree: main.o decisionTree.o test.o decisionTree_teacher.o
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.d
	rm main_teacher.o decisionTree.o test.o main.o
	rm decisionTree_teacher decisionTree

include $(wildcard .d)
