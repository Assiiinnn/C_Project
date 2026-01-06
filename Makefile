CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc
SRC_DIR = src
TEST_DIR = tests

# Liste des fichiers sources (adaptation automatique si tu ajoutes d'autres fichiers .c)
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/LRU_Cache.c
OBJS = $(SRCS:.c=.o)

# Nom de l'exécutable final
TARGET = lru_app

# Règle par défaut (ce qui se lance quand tu tapes juste "make")
all: $(TARGET)

# Édition de liens (Linking) : Crée l'exécutable à partir des .o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation : Crée les .o à partir des .c
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour lancer les tests (Python + JSON)
test: $(TARGET)
	@echo "--------------------------------------"
	@echo "🚀 Lancement des tests automatisés..."
	@echo "--------------------------------------"
	python3 $(TEST_DIR)/test_runner.py

# Nettoyage des fichiers générés
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET) $(TARGET).exe

.PHONY: all test clean
