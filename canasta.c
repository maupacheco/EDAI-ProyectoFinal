#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librero.h"
#include "canasta.h"

float tot=0;


//busca y agrega libro

bool serchCanasta(canasta c, librero *s){
	int op;
	nodo *n = buscar(s);
	if(n == NULL) return false;
	printf("\n¿Desea agregarlo al carrito? (1 = si, 2= no): ");
	scanf("%d", &op);
	if(op==1){
		//n->libro.existencia--;
		bool b = agregarCanasta(c, n->libro);
		if(b==false) return false;
		printf("\nAgregado \n");
	}
	return true;
}


//Agrega ala canasta el libro
bool agregarCanasta(canasta c, libro l){
	bool b = insert1(c,l);	
	if(b==false) return false;
	int precio = l.precio;
	tot += precio;	
	return true;
}


//elimina un libro del carrito 
//elimina el libro de la canasta

bool borraCanasta(canasta c){
	int precio = c->tail->libro.precio;
	bool b = remover1(c);
	if(b==false) return false;
	tot = tot -precio;
	return true;

}
bool confirma(canasta c){
	int op;	
	canasta r = crea();
	printf("\n¿Desea confirmar su compra? (1 = si /2 = no): ");
	scanf("%d",&op);
	switch (op){
		case 1:						
			r = generaR(c);				
			printf("\nCOMPRA REALIZADA EXITOSAMENTE\n");
			printf("\nRecibo de compra: \n");									
			bool b = imprimeCanasta(r);
			if(b==false) return false;
			return true;
		case 2:
			return false;
		default:
			printf("\n Entrada no valida\n");
			return false;


//genera un recibo
canasta generaR(canasta c){	
	canasta nuevo = crea();
	nodo *n = c->head;
	for(int i=0; i<c->num; i++){
		insert1(nuevo, n->libro);
		n = n->sig;
	}	
	return nuevo;
}


//imprime la canasta
bool imprimeCanasta(canasta s){
	if(s == NULL) return false;
	if(librero_vacio(s)) return false;
	nodo *t = s->head;
    printf("\n\tCANASTA:\n");
    printf("\nHay %d libro(s).\n", s->num);

    for(int i=0; i <= s->num-1; i++){
		printf("\t****Libro %d ****\n", i+1);
        printf("Titulo: %s \n", t->libro.titulo);
        printf("Autor: %s \n", t->libro.autor);
        printf("Editorial: %s \n", t->libro.editorial);
        if(t->libro.formato) 
		printf("Formato: Tapa gruesa\n");
        else 
		printf("Foramto: Tapa delgada\n");
        printf("ISBN: %d \n", t->libro.ISBN);        
        printf("Precio: %d \n", t->libro.precio);
        t = t->sig;
    }
    printf("\n\tFIN CANASTA\n");
	printf("\nSubtotal: %.2f\n", tot);
	return true;
}


bool estadoCanasta(canasta s, int *c){
	if(s == NULL) return false;
	if(librero_vacio(s)) return false;
	nodo *t = s->head;
	int op;
    printf("\n\tCANASTA:\n");
    printf("\nHay %d libro(s).\n", s->num);
    for(int i=0; i <= s->num-1; i++){
		printf("\t---Libro %d---\n", i+1);
        printf("Titulo: %s \n", t->libro.titulo);        
        printf("Precio: %d \n", t->libro.precio);
        t = t->sig;
    }
	printf("Subtotal: %.2f\n", tot);
	printf("\n¿Qué desa hacer?");
	printf("\n1) Seguir comprando");
	printf("\n2) Concluir compra");
	printf("\n3) Eliminar último libro comprado del carrito");	
	printf("\nOpcion: ");
	scanf("%d", &op);
	if(op==2){
		bool b = confirma(S);
		*c = 1;
		if(b==false) return false;
	}
	if(op==3){
		bool b = borraCanasta(s);
		if(b==false) return false;
	}
	return true;
}