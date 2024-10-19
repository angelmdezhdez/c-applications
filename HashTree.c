/**********************************************************
Implementacion de una tabla de Hash para busqueda haciendo
uso de arboles binarios

By
Angel Antonio Mendez Hernandez
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{
    int id;
    struct nodo *izq;
    struct nodo *der;
};

//creamos nodo dando valor a id y mandando hijos a NULL
struct nodo* crearNodo(int val){
    struct nodo *pos;
    pos=(struct nodo*)malloc(sizeof(struct nodo));
    pos->id=val;
    pos->der=NULL;
    pos->izq=NULL;
    return pos;
};

/*insertamos un nodo en el arbol, si la id ya existe no inserta nada
y no cambia la estructura del arbol*/
struct nodo *insertar(struct nodo *r, int val){
    if(r==NULL)
        return (crearNodo(val));
    if(r->id<val)
        r->der=insertar(r->der, val);
    else if(r->id>val)
        r->izq=insertar(r->izq, val);
    return r;
};

//creamos la tabla insertando nodos en el arbol correspondiente
struct nodo **crearTabla(int key, int n){
    struct nodo **roots;
    int i, res, val;
    roots=(struct nodo**)malloc(key*sizeof(struct nodo*));
    //iniciamos las raices en NULL
    for(i=0; i<key; i++)
        roots[i]=NULL;
    for(i=0; i<n; i++){
        val=rand()%100 +1;
        res=val%key;
        roots[res]=insertar(roots[res], val);
    }
    return roots;
};

//impresion en orden
void imprimirArbol(struct nodo *r){
    if(r!=NULL){
        imprimirArbol(r->der);
        printf("%d, ", r->id);
        imprimirArbol(r->izq);
    }
}

void imprimirTabla(struct nodo **roots, int key){
    for(int i=0; i<key; i++){
        printf("Arbol %d: ", i+1);
        imprimirArbol(roots[i]);
        printf("\n");
    }
}

int max(int a, int b){
    return (a > b) ? a : b;
}

//contamos la profundidad de izquierdos y derechos y devolvemos el max + 1
int profundidad(struct nodo *raiz){
    int pIzq, pDer;
    if(raiz==NULL)
        return 0;
    else{
        pIzq = profundidad(raiz->izq);
        pDer = profundidad(raiz->der);
        return 1 + max(pIzq, pDer);
    }
}

//revisamos todas las profundidades de todos los arboles y nos quedamos con
//la mayor y a que arbol pertenece
void maxProfundidad(struct nodo **roots, int key, int *pos, int *prof){
    int p0=0,p1, i=0;
    for(int j=0; j<key; j++){
        p1=profundidad(roots[j]);
        if(p1>p0){
            p0=p1;
            i=j;
        }
    }
    *pos=i;
    *prof=p0;
}

void liberarArbol(struct nodo *raiz){
    if(raiz!=NULL){
        liberarArbol(raiz->izq);
        liberarArbol(raiz->der);
        free(raiz);
    }
}

void liberarTabla(struct nodo **tabla, int key){
    for(int i=0; i<key; i++){
        if(tabla[i]!=NULL)
            liberarArbol(tabla[i]);
    }
    free(tabla);
}

int main(){
    int key, n, bandera=1, val=0, opc, pos, prof;
    struct nodo **raices;
    printf("Ingrese la key que desea usar: ");
    scanf("%d", &key);
    srand(time(NULL));
    printf("Vamos a generar aleatorios (1-100) para llenar la tabla, \
ingrese la cantidad de aleatorios que desea: ");
    scanf("%d", &n);
    raices=crearTabla(key, n);
    while(bandera){
        printf("1. Ingresar nodo\n2. Imprimir tabla\n3. Indice y mayor profundidad en tabla\n4. Fin\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                printf("Ingrese la nueva ID: ");
                scanf("%d", &val);
                raices[val%key]=insertar(raices[val%key], val);
                break;
            case 2:
                imprimirTabla(raices, key);
                break;
            case 3:
                maxProfundidad(raices, key, &pos, &prof);
                printf("El arbol con mayor profundidad es el %d y tiene profundidad %d.\nEl contenido de arbol es: ", pos+1, prof);
                imprimirArbol(raices[pos]);
                printf("\n");
                break;
            case 4:
                printf("Esta es la tabla final:\n");
                imprimirTabla(raices, key);
                bandera=0;
                break;
        }
    }
    liberarTabla(raices, key);
    return 0;
}
