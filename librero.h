#ifndef LIBRERO_H
#define LIBRERO_H

#include "node.h"
#include <stdbool.h>

//Lista doblemente ligada circular
typedef struct _librero librero;
struct _librero{
	nodo *head;
	nodo *tail;
	int num;
};

//funciones del librero//
librero *crear();
void vaciar(librero *s);
bool eliminarL(librero *s); //Borra el librero Actual

//busqueda//
nodo* search(librero *s);
nodo* buscarNodo(librero *l, int q);


//Insertar por ambos lados
bool insert1(librero *s, libro l); //inicio
bool insert2(librero *s, libro l);	//final


//Remover-eliminar -libro// 
bool remover1(librero *s ); //inicio	
bool remover2(librero *s);	//final
// bool eliminar_libro(librero *o);
//exitencias falta bool exitencias/librero *o);

//Librero
bool vacioL(librero *s);
void imprimirL(librero *s);
void pedir(librero *s);


#endif