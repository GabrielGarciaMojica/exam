#ifndef INVENTARIO_H
#define INVENTARIO_H

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} producto_t;

typedef struct {
    producto_t* productos;
    int tamano;   // Capacidad total del inventario
    int ocupado;  // Número actual de productos
} inventario_t;

// Declaración de funciones || TODO: Declarar el resto de funciones
inventario_t* crearInventario();

void agregarProducto(inventario_t *inventario,const char *nombre,int cantidad,float precio);
void imprimirInventario(const inventario_t *inventario);
void eliminarProducto(inventario_t *inventario, const char *nombre);
void vaciarInventario(inventario_t *inventario);

#endif // INVENTARIO_H
