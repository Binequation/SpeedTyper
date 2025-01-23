# Compiler to use
CC = gcc

# Compiler flags (optimize for speed and warnings)
CFLAGS = -Wall -O2 -Wextra -std=c99

# Source files
SOURCE = src/*.c

# Output file
OUTPUT = keyboard-typer

# Header files
INCLUDE = include/*.h

# Compile and build
all:
	$(CC) $(SOURCE) $(CFLAGS) -I$(INCLUDE) -o $(OUTPUT)

# Clean up the build directory
clean:
	rm -f $(OUTPUT)
