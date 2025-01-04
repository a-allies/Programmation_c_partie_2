CC=gcc
CFLAGS= -Wall -Wextra -MMD
LD=gcc
LDFLAGS= -L/usr/local/lib
LIB= 

DEBUG= no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

programHuffman: LIB+= -lm
programHuffman: main-Huffman.o binary_tree.o huffman_method-teacher.o list-teacher.o image-proba.o image.o
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@

cleanHuffman:
	rm *.d
	rm main-Huffman.o binary_tree.o image-proba.o image.o
	rm programHuffman

program: mainBTree.o binary_tree.o
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@

clean:
	rm *.d
	rm mainBTree.o binary_tree.o
	rm program


include $(wildcard .d)
