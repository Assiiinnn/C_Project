CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc
SRC_DIR = src
TEST_DIR = tests

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/LRU_Cache.c
OBJS = $(SRCS:.c=.o)

TARGET = lru_app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	python3 $(TEST_DIR)/test_runner.py

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET) $(TARGET).exe

.PHONY: all test clean
