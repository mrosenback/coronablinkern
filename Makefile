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

datetest.o: datetest.c date.o
	gcc $(CFLAGS) -c datetest.c -o datetest.o

listtest.o: listtest.c list.o date.o
	gcc $(CFLAGS) -c listtest.c -o listtest.o

coronablinker: date.o list.o coronablinker.o
	gcc $(CFLAGS) $(OBJ) -o coronablinker

test: datetest.o listtest.o
	gcc $(CFLAGS) datetest.o date.o -o datetest
	gcc $(CFLAGS) listtest.o list.o date.o -o listtest