#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct parentesis{
    char *parentesis;
    struct parentesis *siguiente;
};

typedef struct parentesis Nodo;

Nodo *cabeza = NULL;
Nodo *actual = NULL;

void pushAP();
void pushAC();
void pushAL();
void pop();
void ImprimirPila();


int main(){
    char nombre[200], unaLinea[1024];
    FILE *archivo;
    printf("Nombre del archivo? ");
    fgets(nombre,200,stdin);
    fflush(stdin);

    nombre[strlen(nombre)-1] = '\0';

    archivo = fopen(nombre,"rt");
    if (archivo==NULL) {
        printf("No existe el archivo [%s]\n",nombre);
        exit(1000);
    }
    while(!feof(archivo)){
        size_t k;
        while(fgets(unaLinea,1024,archivo)) {
        //Si no funciona borrar desde aqui

        for(k=0;k<strlen(unaLinea);k++){
            if(unaLinea[k] == '('){
                pushAP();
                }
            else if(unaLinea[k] == ')'){
                    pop();
                    }
            else if(unaLinea[k] == '{'){
                pushAL();
                }
            else if(unaLinea[k] == '}'){
                    pop();
                    }
            else if(unaLinea[k] == '['){
                pushAL();
                }
            else if(unaLinea[k] == ']'){
                    pop();
                    }
            }
        }
        if (cabeza == NULL){
            printf("No hay ningun problema\n");
        }else if(cabeza != NULL){
                printf("Hay un problema con algun parentesis\n");
                }
                ImprimirPila();
    }
    fclose(archivo);
    return(0);
}
void pushAP(){

    Nodo *nodo = (struct parentesis*)malloc(sizeof(struct parentesis));
    if(NULL == nodo){
        printf("\n Error en creacion de nodo \n");
    }

    nodo->parentesis = "(";
    nodo->siguiente = cabeza;
    cabeza = nodo;

}
void pushAC(){

    Nodo *nodo = (struct parentesis*)malloc(sizeof(struct parentesis));
    if(NULL == nodo){
        printf("\n Error en creacion de nodo \n");
    }

    nodo->parentesis = "[";
    nodo->siguiente = cabeza;
    cabeza = nodo;

}
void pushAL(){

    Nodo *nodo = (struct parentesis*)malloc(sizeof(struct parentesis));
    if(NULL == nodo){
        printf("\n Error en creacion de nodo \n");
    }

    nodo->parentesis = "{";
    nodo->siguiente = cabeza;
    cabeza = nodo;

}
void pop(){
    if(NULL == cabeza){
            printf("La pila esta vacia \n");
    }else{
        printf("\n -------Elemento Top Removido------- \n");
        Nodo *nodo = cabeza;
        printf("Nombre: %s\n", nodo->parentesis);

        cabeza=nodo->siguiente;
        free(nodo);
    }

}

void ImprimirPila(){

    if(NULL == cabeza){
        printf("La pila esta vacia \n");
    }else{
        Nodo *nodo = cabeza;
        printf("\n -------Inicio de la Pila------- \n");

        while(nodo != NULL)
        {
            printf("Nombre: %s\n", nodo->parentesis);
            nodo = nodo->siguiente;
        }

        printf("\n -------Final de la Pila------- \n");

    }

}

void ContarNodos(){
    Nodo *nodo = cabeza;
    int i=0;

    while(nodo != NULL){
        i++;
        nodo = nodo->siguiente;
    }

    printf("\n Cantidad de nodos: %d\n", i);

    return;
}
