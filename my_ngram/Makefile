# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Target executable
TARGET = my_ngram

# Source files
SRC = my_ngram.c

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Compile target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile object files (optimized)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean all generated files
fclean: clean
	rm -f $(TARGET)

# Recompile everything
re: fclean all
