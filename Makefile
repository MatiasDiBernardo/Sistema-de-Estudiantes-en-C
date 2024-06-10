# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRCS = main.c ll_estudiantes.c CLI.c ll_materias.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = Sistema_de_Estudiantes

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(EXEC)

# Rebuild
rebuild: clean all
