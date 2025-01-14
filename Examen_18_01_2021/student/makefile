CC=gcc
CFLAGS= -Wall -Wextra -MMD
LD=gcc
LDFLAGS= -L/usr/local/lib
LIB= 

DEBUG= no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif
#permet de construire l'executabel network en tapant "make" au lieu de "make network"
all: network
#permet de construite l'executable network
network: main.o line.o line_ref.o
	$(CC) $(LDFLAGS) $^ $(LIB) -o $@
#pour chaque fichier .c génére son .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#permet de supprimer tout les fichiers crées lors de la compilation sauf le fichier line_ref.o fournit
clean:
	rm *.d
	rm main.o line.o
	rm network
#calcul des dépendances entre les différents modules du projet
include $(wildcard .d)
