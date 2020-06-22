#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "node.h"
#include "canasta.h"
#include "librero.h"

//PROYECTO FINAL EDA I
//PACHECO SALGADO MAURICIO
//PEREZ VARGAS OSCAR

int v = 0; //verificar

//EMPLEADO
void empleado(librero *x){
    int opc; 
    int back;
    bool y;
    do{
        system("cls");
        printf("\n\n\n\t\t\t EMPLEADO \n\n\n");
        printf("\t\n\t1) Agregar un libro \n\t2) Quitar uno \n\t3) Agregar existencias \n\t4) Salir ");
        printf("\n\n\tOpcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                system("cls");
                pedir_libro(x);
                getchar();
                break;
            case 2:
                do{
                    system("cls");
                    y = eliminar_libro(x);
                    printf("\n\t¿Seguir eliminando? (1 = si / 2 = no): ");
                    scanf("%d", &back);
                }while(back==1);
            break;
            case 3:
                system("cls");
                y = existencias(x);
                if(b==false) printf("\n\tERROR");
            break;
            case 4:
            break;
            default:
                system("cls");
                printf("\nOpcion invalida\n");
        }
    }while(opc!=4);
}

//CLIENTE
void cliente(librero *x, canasta c){
    int opc;
    bool y;
    do{
        getchar();
        system("cls");
        printf("\n\n\n\t\t\t CLIENTE \n\n\n");
        printf("\t ¿Qué desea hacer? \n\n\t1) Ver libros en venta \n\t2) Buscar libros\n\t3) Ver carrito \n\t4) Salir");
        printf("\n\n\tOpcion: ");
        scanf("%d",&opc);
        system("cls");
        switch(opc){
            case 1:
                system("cls");
                y = recorrer_librero(x);
            break;
            case 2:
                getchar();
                system("cls");
                y = buscar_canasta(c,x);                        
            break;
            case 3:
                system ("cls");
                ver_canasta(c, &v);
                if(v == 1) return;
            break;
            case 4:
            break;
            default:
                system ("cls");
                printf("\nOpcion invalida\n");
        }
    } while(opc!=4);
}

//FUNCION PRICIPAL
int main(){
    int respuesta;
    librero *l = crear_librero();
    download(l);
    canasta c = crear_librero();
    system("cls");
    printf("\n\n\n\n\t\t\t Pulse para continuar... ");
    getchar();
    do{
        system("cls");
        printf("\n\n\n\t\t\t BIENVENIDO\n\n\n");
        printf("\t1) Empleado \n\t2) Cliente \n\t3) Salir");
        printf("\n\tOpcion: ");
        scanf("%d",&respuesta);
        switch(respuesta){
            case 1:
                system("cls");
                empleado(l);
            break;
            case 2:
                system("cls");
                cliente(l,c);
                if (v == 1){
                    upload(l);
                    eliminar_librero(l);
                    return 0;
                }
            break;
            case 3:
            break;
            default:
                printf("\nOpcion invalida\n");
        }
    } while(respuesta != 3);
    system("cls");
    printf("\n\n\n\n\t\t\t Muchas gracias, vuelva pronto\n\n\n\n\t\t\t");
    eliminar_librero(l);
    eliminar_librero(c);
    return 0;
}