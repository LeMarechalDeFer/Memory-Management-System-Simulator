CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -Wconversion -Wpointer-arith -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -O0 -std=c11
LDFLAGS = -fsanitize=address -fsanitize=undefined -g

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include
TARGET = $(BIN_DIR)/memory_simulator

# Fichiers sources et objets
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

# Règle par défaut : compilation de l'exécutable
all: $(TARGET)

# Lier les fichiers objets pour créer l'exécutable
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) $(OBJ) -o $(TARGET)

# Compilation des fichiers objets
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Exécuter les tests (optionnel)
test: $(TARGET)
	./tests/run_tests.sh