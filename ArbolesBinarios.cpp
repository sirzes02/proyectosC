#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	
	Nodo *padre;
	Nodo *derecha;
	Nodo *izquierda;
};

Nodo *crear(int, Nodo *);
Nodo *busquedaNodo(Nodo *, int);
//bool comparar(Nodo *, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarNodo(Nodo *, int);
void eliminarNodo(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void menu();

int main(void){
	menu();
	return EXIT_SUCCESS;
}

void menu(){
	Nodo *raiz = NULL;
	bool bandera;
	short opc;
	int dato;
	
	do{
		printf("Menu\n");
		printf("1. Insertar nuevo nodo.\n");
		printf("2. Mostrar arbol.\n");
		printf("3. Buscar elementos.\n");
		printf("4. Eliminar nodos.\n");
		printf("5. Recorrido pre-orden.\n");
		printf("6. Recorrido in-orden.\n");
		printf("7. Recorrido post-orden.\n");
		printf("8. Salir.\n");
		printf("Escoja:\n");
		scanf("%hi", &opc);
		
		switch(opc){
			case 1:
				do{
					printf("\nIngrese nuevo elemento:\n");
					scanf("%d", &dato);
					bandera = busquedaNodo(raiz, dato);
					if(bandera){
						printf("Error, este elemento ya existe.\n\n");
						system("PAUSE");
						printf("\n\n");
					}
				}while(bandera);
				insertarNodo(raiz, dato, NULL);
				break;
			case 2:
				mostrarNodo(raiz, 0);
				break;
			case 3:
				printf("\nIngrese elemento a buscar:\n");
				scanf("%d", &dato);
				
				if(busquedaNodo(raiz, dato))
					printf("ELEMENTO %d ENCONTRADO.\n", dato);
				else
					printf("ELEMENTO NO ENCONTRADO.\n");
				break;
			case 4:
				do{
					printf("\nIngrese nuevo elemento:\n");
					scanf("%d", &dato);
					bandera = busquedaNodo(raiz, dato);
					if(!bandera){
						printf("Error, este elemento NO existe.\n\n");
						system("PAUSE");
						printf("\n\n");
					}
				}while(!bandera);
				eliminarNodo(raiz, dato);
				break;
			case 5:
				preOrden(raiz);
				break;
			case 6:
				inOrden(raiz);
				break;
			case 7:
				postOrden(raiz);
				break;
			case 8:
				return;
				break;
			default:
				printf("\nERROR...");
		}
		printf("\n");
		system("PAUSE");
		system("cls");
	}while(true);
}

void insertarNodo(Nodo *&raiz, int dato, Nodo *padre){
	if(!raiz)
		raiz = crear(dato, padre);
	else {
		int valorRaiz = raiz->dato;
		if(dato < valorRaiz)
			insertarNodo(raiz->izquierda, dato, raiz);
		else
			insertarNodo(raiz->derecha, dato, raiz);
	}
}

Nodo *crear(int dato, Nodo *padre){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = dato;
	nuevoNodo->padre = padre;
	nuevoNodo->derecha = NULL;
	nuevoNodo->izquierda = NULL;
	
	return nuevoNodo;
}

void mostrarNodo(Nodo *raiz, int contador){
	if(!raiz)
		return;
	else {
		mostrarNodo(raiz->derecha, contador + 1);
		
		for(int i = 0; i < contador; i++)
			printf("   ");
			
		printf("%d\n", raiz->dato);
		mostrarNodo(raiz->izquierda, contador + 1);
	}
}

Nodo *busquedaNodo(Nodo *raiz, int dato){
	if(!raiz)
		return NULL;
	else if(raiz->dato == dato)
		return raiz;
	else if(dato < raiz->dato)
		return busquedaNodo(raiz->izquierda, dato);
	else
		return busquedaNodo(raiz->derecha, dato);
}

void eliminarNodo(Nodo *raiz, int dato){
	Nodo *encontrado;
	Nodo *padre;
	Nodo *derecha;
	Nodo *izquierda;
	
	encontrado = busquedaNodo(raiz, dato);
	
	if(!encontrado->derecha && !encontrado->izquierda){
		padre = encontrado->padre;
		if(padre->derecha == encontrado){
			padre->derecha = NULL;
			free(encontrado);
		} else {
			padre->izquierda = NULL;
			free(encontrado);
		}
	} else
		if(encontrado->derecha && encontrado->izquierda)
			padre = encontrado->padre;
		else
			if(encontrado->derecha){
				derecha = encontrado->derecha;
				padre = encontrado->padre;
				if(padre->derecha == encontrado){
					padre->derecha = derecha;
					free(encontrado);
				} else {
					padre->izquierda = derecha;
					free(encontrado);
				}
			} else {
				izquierda = encontrado->izquierda;
				padre = encontrado->padre;
				if(padre->derecha == encontrado){
					padre->derecha = izquierda;
					free(encontrado);
				} else {
					padre->izquierda = izquierda;
					free(encontrado);
				}
			}
}

void preOrden(Nodo *raiz){
	if(!raiz)
		return;
	else{
		printf("%d\t<< - >>\t");
		preOrden(raiz->izquierda);
		preOrden(raiz->derecha);
	}
}

void inOrden(Nodo *raiz){
	if(!raiz)
		return;
	else{
		preOrden(raiz->izquierda);
		printf("%d\t<< - >>\t");
		preOrden(raiz->derecha);
	}
}

void postOrden(Nodo *raiz){
	if(!raiz)
		return;
	else{
		preOrden(raiz->izquierda);
		preOrden(raiz->derecha);
		printf("%d\t<< - >>\t");
	}
}

/*
bool comparar(Nodo *raiz_1, Nodo *raiz_2){
	if(raiz_1 == raiz_2)
		return true;
	if(raiz_1 == NULL || raiz_2 == NULL)
		return false;
	return (raiz_1->dato == raiz_2->dato && comparar(raiz_1->derecha, raiz_2->derecha) && comparar(raiz_1->izquierda, raiz_2->izquierda));
}
*/

