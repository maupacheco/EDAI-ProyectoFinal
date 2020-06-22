#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "librero.h"


//crea libreria
librero *crear(){
    librero *s = (librero*)malloc(sizeof(librero));
    s->head = NULL;
    s->tail = NULL;
    s->num = 0;
    return s;
}

void vaciar(librero *s){
	if(vacio(s)) return;
    nodo *t = s->head;
    while(remover1(s));
}

bool eliminarL(librero *s){
    if(!vacio(o)) vaciar(s);
    free(s);
    return true;
}


//Se crea un menu de busqueda para los libro 
nodo* serch(librero *l){		

    int opc;
    int k=0; 
    int halla_libro[l->num];
    int ISBN;
    bool op=true;
    char c[50];
    nodo *t;
    do{
        printf("\nSeleccione metodo de busqueda:\n");
        printf("1. Titulo\n");
        printf("2. Autor\n");
        printf("3. ISBN\n");
        printf("¿Como desea buscar? ");
        scanf("%d",&opc);
        switch (opc){ 
            case 1: 
                t = l->head;
                printf("\nEscriba el titulo del libro: ");
                getchar();        
                gets(c);
                printf("Buscando nombre del libro %s ....\n",c);          
                for(int i= 0; i<l->num; i++){
                    if(strncmp(c, t->libro.titulo, 50)==0){
                        halla_libro[k]=i;
                        k++;
                    }
                    t = t->sig;                 //For anidados
                    }               
                    op=true; 
            break;
            case 2:
                t = l->head;
                printf("\nEscriba el nombre del autor: ");
                getchar();        
                gets(c);
                printf("Buscando nombre del autor%s ....\n",c);
                for(int i= 0; i<l->num; i++){
                    if(strncmp(c, t->libro.autor,4)==0){
                    halla_libro[k]=i;
                    k++;
                    }
                    t = t->sig;
                }
                op=true;
            break;            
            case 3:
                t = l->head;
                printf("\nColoque el ISBN del libro: ");
                scanf("%d", &ISBN);
                for(int i= 0; i <l->num; i++){
                    if(ISBN==t->libro.ISBN){                    
                    halla_libro[k]=i;
                    k++;
                    }
                t = t->sig;
                }
                op = true;
            break;    
            default:
                printf("\nHUBO UN ERROR,\n");
                printf("\nVuelva a ingresar mas tarde\n");
                op = false;            
        }
    }while(op==false);    
        
        if(k>1){
            printf("Se ha encontrado varios resultados: \n");

            int x;
            for(j=0; j<k; j++){
				t = buscaNodo(l, halla_libro[x]);

                printf("%i. Titulo: %s\n Autor: %s\n", x+1, t->libro.titulo, t->libro.autor);
			}
            printf("\n¿Cual es el libro que buscaba? : ");
			scanf("%i", &x);  
            t = buscaNodo(l, halla_libro[x-1]);  

            printf("\nTitulo: %s\n", t->libro.titulo);

            printf("Autor: %s\n", t->libro.autor);

            printf("ISBN: %d \n", t->libro.ISBN);

            printf("Existencias: %d \n", t->libro.existencia);
            return t;
        //No se encontro el libro//
        }else if(k==0){
            printf("\nLo siento no se encontro el libro\n");
            return NULL;
        } else {
        //Se encontro uno//
            t = buscaNodo(l, halla_libro[0]);

            printf("\nTitulo: %s\n", t->libro.titulo);

            printf("Autor: %s\n", t->libro.autor);

            printf("ISBN: %d \n", t->libro.ISBN);

            printf("Existencias: %d \n", t->libro.existencia);
            return t;
        }            
}


nodo* buscaNodo(librero *l, int q){
    if(q == 0) return l->head;
    else if(q == l->num-1) return l->tail;
    else if(q >0 && q < l->num-1){
        nodo *t = l->head->sig;
        for(int i=1; i<l->num-1; i++){
            if(i==q) return t;
            t = t->sig;
        }
    }
    return NULL;
}

//inserta el libro al inicio
bool insert1(librero *s, libro l){
    if(s == NULL) return false;
    nodo *n = crear_nodo(l);
    if(vacioL(s)){        
        s->head = n;
        s->tail = n;
        s->head->sig = e->head->prev=e->tail;
        s->tail->sig = e->tail->prev=e->head;
        s->num =1;
        return true;
    }
    n->sig = s->head;
    n->prev = s->tail;
    s->head->prev = n;
    s->tail->sig = n;
    s->head = n;
    s->num++;
    return true;
}


//inserta el libro al final
bool insert2(librero *s, libro l){
	if(e == NULL) return false;
 	nodo *n = crear_nodo(l);
	if(vacioL(s)){
		s->head = n;
        s->tail = n;
        s->head->sig = s->head->prev = s->tail;
        s->tail->sig = s->tail->prev = s->head;
        s->num = 1;
        return true;
    }
    n->prev = s->tail;
    n->sig = s->head;
    s->head->prev = n;
    s->tail->sig = n;
    s->tail = n;
    s->num++;
    return true;
}



//elimina el libro al inicio
bool remover1(librero *s){
    if(s == NULL || vacioL(s)) return false;
    if(s->head == s->tail){
        borrar_nodo(s->head);
		s->head = s->tail = NULL;
        s->num = 0;
        return true;
    }
    nodo *t = s->head->sig;
    s->head->sig= NULL;
    t->prev = s->tail;
	s->head->prev = NULL;
    borrar_nodo(s->head);
    s->head = t;
    s->num--;
    return true;
}



//Elimina el libro al final
bool remover2(librero *s){
	if(s == NULL || vacioL(s)) return false;
    if(s->head == s->tail){
        borrar_nodo(s->head);
		s->head = s->tail = NULL;
        s->num = 0;
        return true;
    }
    nodo *t = s->tail->prev;
	s->tail->sig= NULL;
    t->sig = s->head;
	s->tail->prev = NULL;
	s->head->prev = t;
    borrar_nodo(s->tail);
    s->tail = t;
    s->num--;
    return true;
}



/*bool existencias(librero *s){	
	int op;
	int existencias;
	printf("\t Existencias de libros\n");	

	printf("1) Agregar \n");

	printf("2) Quitar \n");

	printf("¿Que desea hacer?\n");

    scanf("%d", &op);

    setbuf(stdin, NULL);
	if (op!=2 && op!=1) return false;	
//////////////////////////////////////////////////FALTA	
}*/


bool vacioL(librero *s){
	if((s->head == NULL) && (s->tail == NULL)) return true;
    return false;
}


//Muestra el libro en existencia
void imprimirL(librero *s){	
	if(s == NULL) return;
	if(vacioL(e)) return;
	nodo *t = s->head;
    printf("\n\tESTANTE\n");

    printf("\nHay %d libros.\n", s->num);

    for(int i=0; i <= s->num-1; i++){
		printf("\t---Libro %d---\n", i+1);

        printf("Titulo: %s \n", t->libro.titulo);

        printf("Autor: %s \n", t->libro.autor);

        printf("Editorial: %s \n", t->libro.editorial);

        if(t->libro.formato) printf("Formato: Tapa Gruesa\n");
        else 
        printf("Foramto: Tapa Delgada\n");
        printf("ISBN: %d \n", t->libro.ISBN);

        printf("Precio: %d \n", t->libro.precio);
        t = t->sig;
    }
    printf("\n\tFin librero\n");
}


//Le permite al empleado crear un libro//
void pedir(librero *s){
    char titulo[50];
    char autor[50];
    char editorial[50];
    int ISBN;
    int formato_num;
    bool formato;
    //int existencia; 
    int precio;    
    printf("\tAGREGAR UN LIBRO");
    printf("\nTitulo: ");
    getchar();
    gets(titulo);

    printf("\nAutor: ");    
    gets(autor);

    printf("\nEditorial: ");
    gets(editorial);

    printf("\nISBN: ");
    scanf("%d", &ISBN);

    printf("\nFormato (1 = Tapa delgada, 2  = Tapa gruesa): ");
    scanf("%d", &tipo);

    printf("\nExistencias: ");
    scanf("%d", &existencia);

    printf("\nPrecio: ");
    scanf("%d", &precio);

    if (tipo-1){
        formato = true; //Tapa delgada
    } else {
        formato = false; //Tapa Gruesa
    }

    libro b = crear_libro(titulo, autor, editorial, ISBN, formato, existencia, precio);    
    insertar_final(e, b);
    printf("\n%s Se agrego correctamente\n", e->tail->libro.titulo);        
}


