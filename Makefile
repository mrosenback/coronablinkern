# Variables
OBJ = date.o list.o coronablinker.o
CFLAGS = -Wall -pedantic

# Target
#%.o: %.c
	#gcc $(CFLAGS) -c $< -o $@

date.o: date.c date.h list.h
	gcc $(CFLAGS) -c date.c -o date.o

list.o: list.c list.h
	gcc $(CFLAGS) -c list.c -o list.o

coronablinker.o: coronablinker.c date.h list.h
	gcc $(CFLAGS) -c coronablinker.c -o coronablinker.o

coronablinker: date.o list.o coronablinker.o
	gcc $(CFLAGS) $(OBJ) -o coronablinker