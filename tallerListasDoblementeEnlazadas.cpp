#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo{
	char codigoPaciente[24];
	char nombrePaciente[24];
	char apellidoPaciente[24];
	char direccionPaciente[24];
	char telefonoPaciente[24];
	short edadPaciente;
	
	Nodo *siguiente;
	Nodo *anterior;
}*cola, *cabeza;

void menu();
void insertar();
void mostrar(short opc);
void actualizar();
void buscar();
void eliminar();
void error();
Nodo* buscarCodigo(char auxCodigo[24]);

int main(void){
	short opc;
	
	do{
		system("CLS");
		
		printf("Menu:\n");
		printf("1. Insertar Paciente.\n");
		printf("2. Mostrar Pacientes ASC.\n");
		printf("3. Mostrar Pacientes DSC.\n");
		printf("4. Actualizar Paciente.\n");
		printf("5. Buscar Paciente por edad.\n");
		printf("6. Eliminar Paciente.\n");
		printf("7. Salir.\n");
		printf("Ingrese una opcion:\n");
		scanf("%hi", &opc);
		
		opc == 1 ? insertar(): opc == 2 ? mostrar(0) : opc == 3 ? mostrar(1) : opc == 4 ? actualizar() : opc == 5 ? buscar() : opc == 6 ? eliminar() : opc == 7 ? exit(0) : error();
	}while(true);
	
	return EXIT_SUCCESS;
}

void insertar(){
	system("CLS");
		
	char auxCodigo[24];
	
	printf("Ingrese el codigo del paciente:\n");
	fflush(stdin);
	gets(auxCodigo);
	
	if(buscarCodigo(auxCodigo) == NULL){
		Nodo *nuevo = new Nodo;
			
		strcpy(nuevo->codigoPaciente, auxCodigo);
		printf("Ingrese el nombre del paciente:\n");
		fflush(stdin);
		gets(nuevo->nombrePaciente);
		printf("Ingrese el apellido del paciente:\n");
		fflush(stdin);
		gets(nuevo->apellidoPaciente);
		printf("Ingrese la direccion del paciente:\n");
		fflush(stdin);
		gets(nuevo->direccionPaciente);
		printf("Ingrese el telefono del paciente:\n");
		fflush(stdin);
		gets(nuevo->telefonoPaciente);
		do{
			printf("Ingrese la edad del paciente:\n");
			scanf("%hi", &nuevo->edadPaciente);
			if(nuevo->edadPaciente < 0 || nuevo->edadPaciente > 100) error(); else break;
		}while(true);
		
		if(cabeza == NULL){
			cabeza = nuevo;
			cabeza->siguiente = NULL;
			cabeza->anterior = NULL;
			cola = cabeza;
		} else {
			cola->siguiente = nuevo;
			nuevo->siguiente = NULL;
			nuevo->anterior = cola;
			cola = nuevo;
		}
	} else printf("Este codigo ya existe.\n\n");
	
	system("PAUSE");
}

void mostrar(short opc){
	system("CLS");
	
	Nodo *actual = new Nodo();
	
	// SI SE ENVIA 0 SE IMPRIMIRA ASC SINO DSC.
	opc == 0 ? actual = cabeza : actual = cola;

	if(cabeza != NULL) 
		while(actual != NULL){
			printf("El codigo del paciente: %s.\n", actual->codigoPaciente);
			printf("El nombre del paciente: %s.\n", actual->nombrePaciente);
			printf("El apellido del paciente: %s.\n", actual->apellidoPaciente);
			printf("La direccion del paciente: %s.\n", actual->direccionPaciente);
			printf("El telefono del paciente: %s.\n", actual->telefonoPaciente);
			printf("La edad del paciente: %hi.\n\n\n", actual->edadPaciente);
			
			opc == 0 ? actual = actual->siguiente : actual = actual->anterior;
		}
	else printf("La lista se encuentra vacia.\n\n");

	system("PAUSE");
}

void actualizar(){
	system("CLS");
	
	if(cabeza != NULL){	
		short opc;
		char aux[24];
		
		printf("Ingrese el codigo del paciente al que desea actualizar.\n");
		fflush(stdin);
		gets(aux);
		
		Nodo *busqueda = buscarCodigo(aux);
		
		if(busqueda == NULL) printf("No se encontro un paciente con el codigo %s.\n\n", aux); 
		else
			do{
				system("CLS");
				
				printf("Menu de actualizacion:\n");
				printf("1. Nombre.\n");
				printf("2. Apellido.\n");
				printf("3. Direccion.\n");
				printf("4. Telefono.\n");
				printf("5. Edad.\n");
				printf("6. Salir.\n");
				scanf("%hi", &opc);
				
				switch(opc){
					case 1:
						printf("\n\nIngrese el nuevo nombre.\n");
						fflush(stdin);
						gets(busqueda->nombrePaciente);
						break;
					case 2:
						printf("\n\nIngrese el nuevo apellido.\n");
						fflush(stdin);
						gets(busqueda->apellidoPaciente);
						break;
					case 3:
						printf("\n\nIngrese la nueva direccion.\n");
						fflush(stdin);
						gets(busqueda->direccionPaciente);
						break;
					case 4:
						printf("\n\nIngrese el nuevo telefono.\n");
						fflush(stdin);
						gets(busqueda->telefonoPaciente);
						break;
					case 5:
						do{
							printf("\n\nIngrese la nueva edad.\n");
							scanf("%hi", &busqueda->edadPaciente);
							if(busqueda->edadPaciente < 0 || busqueda->edadPaciente > 100) error(); else break;
						}while(true);
						break;
					case 6:
						return;
					default:
						error();
				}
				printf("\n");
				system("PAUSE");
			}while(true);
	} else printf("La lista se encuentra vacia.\n\n");
	
	system("PAUSE");
}

void buscar(){
	system("CLS");
	if(cabeza != NULL){
		Nodo *actual = new Nodo();
		short edad;
		bool bandera = false;
		
		do{
			printf("Ingrese la edad a buscar:\n");
			scanf("%hi", &edad);
			if(edad < 0 || edad > 100) error(); else break;
		}while(true);
		
		actual = cabeza;
		
		system("CLS");
		printf("Los pacientes con una edad de %hi son:\n\n", edad);
		while(actual != NULL){
			if(actual->edadPaciente == edad){
				printf("El codigo del paciente: %s.\n", actual->codigoPaciente);
				printf("El nombre del paciente: %s.\n", actual->nombrePaciente);
				printf("El apellido del paciente: %s.\n", actual->apellidoPaciente);
				printf("La direccion del paciente: %s.\n", actual->direccionPaciente);
				printf("El telefono del paciente: %s.\n", actual->telefonoPaciente);
				printf("La edad del paciente: %hi.\n\n\n", actual->edadPaciente);
				
				bandera = true;	
			}			
			actual = actual->siguiente;
		}
		
		if(!bandera) printf("0.\n\n");
		
	} else printf("La lista se encuentra vacia.\n\n");

	system("PAUSE");
}

void eliminar(){
	system("CLS");
	if(cabeza != NULL){	
		char aux[24];
		
		printf("Ingrese el codigo del paciente al que desea actualizar.\n");
		fflush(stdin);
		gets(aux);
		
		Nodo *busqueda = buscarCodigo(aux);
		
		if(busqueda == NULL) printf("No se encontro un paciente con el codigo %s.\n\n", aux); else {
			// SI EL NODO ES EL UNICO EN LA LISTA
			if(busqueda->anterior == NULL && busqueda->siguiente == NULL)
				cabeza = NULL;
			// SI ES EL PRIMERO 
			else if(busqueda->siguiente != NULL && busqueda->anterior == NULL){
				busqueda->siguiente = cabeza;
				busqueda->siguiente->anterior = NULL;
			// SI ES EL ULTIMO
			} else if(busqueda->siguiente == NULL && busqueda->anterior != NULL){
				busqueda->anterior = cola;
				busqueda->anterior->siguiente = NULL;
			// SI ESTA EN EL MEDIO
			} else {
				busqueda->anterior->siguiente = busqueda->siguiente;
				busqueda->siguiente->anterior = busqueda->anterior;
			}
			free(busqueda);
		}
	} else printf("La lista se encuentra vacia.\n\n");
	system("PAUSE");
}

void error(){
	printf("\nDato incorrecto, por favor vuelva a intentar.\n");
	system("PAUSE");
	system("CLS");
}


Nodo* buscarCodigo(char auxCodigo[24]){
	Nodo *actual = new Nodo();
	
	actual = cabeza;
	while(actual != NULL){
		if(strcmp(auxCodigo, actual->codigoPaciente) == 0){
			return actual;
		}
		actual = actual->siguiente;
	}
	return NULL;
}

