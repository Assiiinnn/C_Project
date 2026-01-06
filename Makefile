CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc
SRC = src
TEST = tests

all: lru_app

lru_app: test_lru.o LRU_Cache.o
	$(CC) $(CFLAGS) -o lru_app test_lru.o LRU_Cache.o

test_lru.o: $(TEST)/test_lru.c $(SRC)/LRU_Cache.h
	$(CC) $(CFLAGS) -c $(TEST)/test_lru.c

LRU_Cache.o: $(SRC)/LRU_Cache.c $(SRC)/LRU_Cache.h
	$(CC) $(CFLAGS) -c $(SRC)/LRU_Cache.c

test: lru_app
	./lru_app

clean:
	rm -f *.o lru_app
