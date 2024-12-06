# Nombre del ejecutable y biblioteca
EXEC = programa
LIB = libinventario.a

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -g
AR = ar
ARFLAGS = rcs

# Archivos fuente y objetos
SRC = main.c inventario.c
OBJ = main.o inventario.o
HEADERS = inventario.h

# Target por defecto
all: $(EXEC)

# Generar el ejecutable
$(EXEC): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $(EXEC) main.o -L. -linventario

# Generar la biblioteca estática
lib: inventario.o
	$(AR) $(ARFLAGS) $(LIB) inventario.o

# Compilar archivos objeto
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos temporales y ejecutables generados
clean:
	rm -f $(OBJ) $(LIB) $(EXEC)

# Ejecutar el programa
run: $(EXEC)
	./$(EXEC)