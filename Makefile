CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc
SRC = src

all: lru_app

lru_app: main.o LRU_Cache.o
	$(CC) $(CFLAGS) -o lru_app main.o LRU_Cache.o

main.o: $(SRC)/main.c $(SRC)/LRU_Cache.h
	$(CC) $(CFLAGS) -c $(SRC)/main.c

LRU_Cache.o: $(SRC)/LRU_Cache.c $(SRC)/LRU_Cache.h
	$(CC) $(CFLAGS) -c $(SRC)/LRU_Cache.c

clean:
	rm -f *.o lru_app
