#ifndef CANASTA_H
#define CANASTA_H
#include "node.h"
#include "librero.h"
#include <stdbool.h>

typedef librero* canasta;

// pila//
bool agregarCanasta(canasta c, libro l); //insertar
bool borraCanasta(canasta c); //eliminar

//Funciones de la compra//
bool confirma(canasta c); //TRUE compra EXITOSA
bool serchCanasta(canasta c, estante *s); //busca en la canasta
bool imprimeCanasta(canasta s);
bool estadoCanasta(canasta s, int *c);

#endif
