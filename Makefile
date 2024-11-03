# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -I include

# Target executable
TARGET = test

# Source files
SRCS = test/test.c src/vector.c

# Object files (derived from source files)
OBJS = $(SRCS:.c=.o)

# Default target: Build the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Pattern rule to compile each .c file into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: Remove all compiled files
clean:
	rm -f $(TARGET) $(OBJS)