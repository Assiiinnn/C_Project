CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc
SRC = src
TEST = tests

all: lru_app test_lru

lru_app: main.o LRU_Cache.o
	$(CC) $(CFLAGS) -o lru_app main.o LRU_Cache.o

test_lru: test_lru.o LRU_Cache.o
	$(CC) $(CFLAGS) -o test_lru test_lru.o LRU_Cache.o

main.o: $(SRC)/main.c $(SRC)/LRU_Cache.h
	$(CC) $(CFLAGS) -c $(SRC)/main.c

test_lru.o: $(TEST)/test_lru.c $(SRC)/LRU_Cache.h
	$(CC) $(CFLAGS) -c $(TEST)/test_lru.c

LRU_Cache.o: $(SRC)/LRU_Cache.c $(SRC)/LRU_Cache.h
	$(CC) $(CFLAGS) -c $(SRC)/LRU_Cache.c

test: test_lru
	./test_lru

clean:
	rm -f *.o lru_app test_lru
