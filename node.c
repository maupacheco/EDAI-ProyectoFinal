#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Crea un nodo(libro) y lo retorna
libro *crea_libro(char titulo[], char autor[], char editorial[], int ISBN, bool formato, int existencia, int precio){
    libro *p;
    p=(node*)malloc(sizeof(node));
    p->next=NULL;
    p->prev=NULL;
    strcpy(p->titulo, titulo);
    strcpy(p->autor, autor);
    strcpy(p->editorial, editorial);
    strcpy(p->ISBN = ISBN);
    strcpy(p->formato = formato);
    strcpy(p->existencia = existencia);
    strcpy(p->precio = precio);
	return p;
}

tnodo *crear_tnodo(libro l){
    tnodo *a;
    a = (tnodo*)malloc(sizeof(tnodo));
    a->libro = l;
    a->sig = NULL;
    a->prev = NULL;
    return a;
}

bool borrar_tnodo(tnodo *n){
    if (n->prev == NULL && e->next == NULL){	    
		free(e);
        return true;
    }
    return false;
}