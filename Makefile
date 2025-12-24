CC = gcc
CFLAGS = -Wall -Wextra -g

all: lru_app

lru_app: main.o LRU_Cache.o
	$(CC) $(CFLAGS) -o lru_app main.o LRU_Cache.o

main.o: main.c LRU_Cache.h
	$(CC) $(CFLAGS) -c main.c

LRU_Cache.o: LRU_Cache.c LRU_Cache.h
	$(CC) $(CFLAGS) -c LRU_Cache.c

clean:
	rm -f *.o lru_app
