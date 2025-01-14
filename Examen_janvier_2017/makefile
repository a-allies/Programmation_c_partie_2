CC=gcc
CFLAGS= -Wall -Wextra -MMD
LD=gcc
LDFLAGS= -L/usr/local/lib
LIB= 

DEBUG= no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif

exam: main.o file.o list.o crypto.o
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@

exam-ref: main.o file.o list-ref.o crypto.o
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.d
	rm main.o file.o list.o crypto.o
	rm exam*

include $(wildcard .d)
