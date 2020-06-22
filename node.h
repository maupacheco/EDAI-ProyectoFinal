#ifndef NODO_H
#define NODO_H

#include <stdbool.h>

typedef struct _libro libro;
struct _libro{
    char titulo[50];
    char autor[50];
    char editorial[50];  
    int ISBN;
    bool formato;
    int existencia;
    int precio;
    tnodo *sig;
    tnodo *prev;
};

//Funcion para crear un libro
libro *crea_libro(char titulo[], char autor[], char editorial[], int ISBN, bool formato, int existencia, int precio);

tnodo *crear_tnodo(libro l);
bool borrar_tnodo(tnodo *n);

#endif