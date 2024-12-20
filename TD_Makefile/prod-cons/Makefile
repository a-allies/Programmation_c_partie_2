CC=gcc -c
CFLAGS= -Wall -Wextra -MMD
LD=gcc
LDFLAGS=
LDLIBS=

all : prod_cons

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

prod_cons: producer.o consumer.o main.o init_conso_prod.o
	gcc producer.o consumer.o main.o init_conso_prod.o -o prod_cons

include $(wildcard *.d)

clean:
	rm *.d *.o prod_cons
