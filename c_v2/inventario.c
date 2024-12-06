#include "inventario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementación de funciones

// Crear el inventario (deben usar malloc para la memoria dinámica) || TODO: Implementar esta función
inventario_t* crearInventario() {
    //pointer inventario reserva memoria para inventario_t
    inventario_t *inventario = (inventario_t*)malloc(sizeof(inventario_t));
    //Reserva memoria para producto_t en productos en inventario
    inventario->productos = (producto_t*)malloc(10*sizeof(producto_t));
    //valores iniciales de ocupado & tamaño
    inventario->tamano = 10;
    inventario->ocupado = 0;
    return inventario;
}

// Agregar un producto al inventario (usar realloc si se llena la capacidad) || TODO: Implementar esta función
void agregarProducto(inventario_t *inventario, const char *nombre, int cantidad, float precio) {
    
    //Ampliar caundo ocupado = tamano
    if (inventario->ocupado == inventario->tamano){

        int nuevo_tamano = inventario->tamano*2;
        producto_t *ampliacion = (producto_t*)realloc(inventario->productos,nuevo_tamano* sizeof(producto_t));
        return;
    
        //actulizar valores de productos y tamano
        inventario->tamano = nuevo_tamano;
        inventario->productos = ampliacion;
    }
    //Añade nuevo producto
    producto_t *nuevo_producto = &inventario->productos[inventario->ocupado];
    strncpy(nuevo_producto->nombre, nombre, sizeof(nuevo_producto->nombre) - 1);
    //nuevo_producto->nombre[sizeof(nuevo_producto->nombre)- 1 ] = '\0';
    nuevo_producto->cantidad = cantidad;
    nuevo_producto->precio = precio;
    //suma a ocupado
    inventario->ocupado++;
}

//Imprime inventario || TODO:Implementar la función imprimirInventario
void imprimirInventario(const inventario_t *inventario){
    int p = 1;
    for (int i = 0; i < inventario->ocupado; i++){
        const producto_t *producto = &inventario->productos[i];
        printf("%d.%s - Cantidad: %d - Precio: ₡%.2f\n",p,producto->nombre,producto->cantidad,producto->precio);
        p = p+1;
    }
}

//Eliminar producto || TODO: Implementar la función eliminarProducto
void eliminarProducto(inventario_t *inventario, const char*nombre){
    //variabkle par aguardar el indice de el producto a eliminar
    int i_a_eliminar = -1;
    //Para buscar el producto en la lista
    for (int i = 0; i < inventario->ocupado; i++){
        if (strcmp(inventario->productos[i].nombre,nombre)==0){
            i_a_eliminar = i;
            break;
        }
    }
    //si el producto no se encontro
    if (i_a_eliminar == -1)
    {
        printf("No se encontro el producto");
        return;
    }
    //Elimina y organiza
    for (int i = i_a_eliminar; i < inventario->ocupado-1; i++){
        inventario->productos[i] = inventario->productos[i+1];
    }
    //reducir ocupado
    inventario->ocupado--;
}

//Vaciar inventario || TODO: Implementar la función vaciarInventario
void vaciarInventario(inventario_t *inventario){
    free(inventario->productos);
    free(inventario);
    printf("Inventario vaciado\n");
}
