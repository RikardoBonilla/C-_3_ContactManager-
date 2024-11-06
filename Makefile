# Makefile for Contact Manager project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories and target
SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/contact_manager

# Source and object files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/contact.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to compile each .c file into a .o file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build files
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

.PHONY: clean