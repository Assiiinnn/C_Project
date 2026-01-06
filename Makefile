CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc
SRC = src
TEST = tests

all: test_lru

test_lru: test_lru.o LRU_Cache.o
	$(CC) $(CFLAGS) -o test_lru test_lru.o LRU_Cache.o

test_lru.o: $(TEST)/test_lru.c $(SRC)/LRU_Cache.h
	$(CC) $(CFLAGS) -c $(TEST)/test_lru.c

LRU_Cache.o: $(SRC)/LRU_Cache.c $(SRC)/LRU_Cache.h
	$(CC) $(CFLAGS) -c $(SRC)/LRU_Cache.c

test: test_lru
	./test_lru

clean:
	rm -f *.o test_lru
