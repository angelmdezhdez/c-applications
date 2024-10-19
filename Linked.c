/************************************************************************
Listas ligadas, un ejemplo muy sencillo

By
Angel Antonio Mendez Hernandez
************************************************************************/
#include <stdio.h>
#include<stdlib.h>

//Definimos nodo
struct nodo{
    int id;
    struct nodo *sig;
};


struct nodo* crearnodo(){
    struct nodo *pos;
    int val;
    printf("Ingrese la id: ");
    if(scanf("%d", &val)==0){
        //limpiamos bufer
        int c;
        while((c=getchar())!='\n'&&c!=EOF){}
        return NULL;
    }
    pos=(struct nodo*)malloc(sizeof(struct nodo));
    pos->id=val;
    pos->sig=NULL;
    return pos;
};

struct nodo* ingresarnodo(struct nodo* inicio) {
    struct nodo* temp, * pos = inicio;
    //Creamos nodo si la lista es vacia
    if(pos==NULL)
        return crearnodo();
    //Llegamos al ultimo nodo
    while(pos->sig!=NULL)
        pos=pos->sig;
    //Creamos un nuevo nodo y lo ananidimos al final
    temp=crearnodo();
    if(temp==NULL)
        return inicio; //En caso de que no haya cambios
    pos->sig = temp;
    return inicio; 
}

struct nodo* eliminarnodo(struct nodo* inicio){
    int val;
    printf("Ingrese el valor que desea eliminar de la lista: ");
    scanf("%d", &val);
    struct nodo *anterior=NULL, *pos=inicio;
    //buscamos el nodo donde se encuentre el valor
    while(pos!=NULL && pos->id!=val){
        anterior=pos;
        pos=pos->sig;
    }
    //en caso de que el nodo no se encuentre
    if(pos==NULL)
        return inicio; 
    //si el nodo a eliminar es el primero
    if (anterior==NULL){
        inicio=pos->sig;
    }
    else{
        //si el nodo a eliminar no es el primero
        anterior->sig=pos->sig;
    }
    //limpiamos
    free(pos);
    return inicio;
};

void mostrarlista(struct nodo *pos){
    //recorremos e imprimimos
    while(pos!=NULL){
        printf("La id es: %d\n",pos->id);
        pos=pos->sig;
    }
}

void contar(struct nodo *pos){
    //recorremos y contamos
    int contador=0;
    while(pos!=NULL){
    	contador++;
    	pos=pos->sig;
    }
    printf("Hay %d nodos en total.\n", contador);
}

void buscar(struct nodo *pos){
    int valor, contador=0, bandera=0;
    printf("Ingrese el valor que desea buscar en la lista: ");
    scanf("%d",&valor);
    //buscamos el valor
    while(pos!=NULL){
    	contador++;
    	if(pos->id==valor){
    	     printf("El valor existe en la lista en la posicion %d\n", contador);
    	     bandera=1;
    	}
    	     
    	pos=pos->sig;
    }
    //en caso de que la id no exista en la lista
    if(bandera==0)
    	printf("No existe el valor en la lista\n");
}

struct nodo* invertir(struct nodo* pos){
    struct nodo* actual=pos;
    struct nodo* anterior=NULL;
    struct nodo* siguiente=NULL;
    //movemos las ligas para que apunten de regreso
    while(actual!=NULL){
    	siguiente=actual->sig;
    	actual->sig=anterior;
    	anterior=actual;
    	actual=siguiente;
    }
    pos=anterior;
    printf("La lista fue invertida!\n");
    return pos;
}

void ordenar(struct nodo* pos){
    struct nodo* actual=pos;
    struct nodo* siguiente=NULL;
    int temp;
    //ordenamiento burbuja, si algun elemento esta desordenado
    //cambia las ids solamente
    while(actual!=NULL){
    	siguiente=actual->sig;
    	while(siguiente!=NULL){
    	     if(actual->id < siguiente->id){
    	          temp=actual->id;
    	          actual->id=siguiente->id;
    	          siguiente->id=temp;
    	     }
    	     siguiente=siguiente->sig;
    	}
    	actual=actual->sig;
    }
    printf("La lista fue ordenada!\n");
}

int main() {
    struct nodo* inicio = NULL;
    struct nodo* ptr=NULL;
    int n, bandera=1, opcion;
    printf("Vamos a crear una lista inicial para trabajar.\nIngrese el numero de IDs que desea agregar a la lista: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        inicio=ingresarnodo(inicio);
    while(bandera==1){
    	printf("Ingrese un valor segun la opcion que desea:\n1. Insertar nodo\n2. Eliminar nodo\n3. Num. de nodos\n4. Buscar valor\n5. Invertir orden\n6. Ordenar lista\n7. Mostrar lista\n8. Finalizar programa\n");
    	scanf("%d", &opcion);
    	switch(opcion){
    	    case 1:
    	    	inicio=ingresarnodo(inicio);
    	    	break;
    	    case 2:
    	    	inicio=eliminarnodo(inicio);
    	    	break;
    	    case 3:
    	    	ptr=inicio;
    	    	contar(ptr);
    	    	break;
    	    case 4:
    	        ptr=inicio;
    	        buscar(ptr);
    	     	break;
    	    case 5:
    	     	inicio=invertir(inicio);
    	     	break;
    	    case 6:
    	    	ordenar(inicio);
    	    	break;
    	    case 7:
    	    	ptr=inicio;
    	    	mostrarlista(ptr);
    	    	break;
    	    case 8:
    	    	bandera=0;
    	    	break;
    	}
    }

    // Liberar la memoria
    while (inicio != NULL) {
        struct nodo* temp = inicio;
        inicio = inicio->sig;
        free(temp);
    }
    return 0;
}
