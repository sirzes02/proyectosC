#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define CANTESTUDIANTES 5

int cantActualEstudiantes;

struct fecha{
	short dia;
	short mes;
	short anio;
};

struct estudiante{
	char codigo[24];
	char nombre[24];
	short edad;
	struct fecha miFecha;
	char ciudad[24];
}miEstudiante[CANTESTUDIANTES];

void lecturaArreglo();
void impresionArreglo();
void buscarEstudiantePosicion();
void buscarEstudianteEdad();
void menu();
void error(short min, short max);

int main(void){
	cantActualEstudiantes = 0;
	
	menu();
	
	return 0;
}

void menu(){
	short opc;
	
	do{
		printf("Bienvenido al menu principal.\n\n");
		printf("Seleccione un valor:\n");
		printf("1. Ingresar un nuevo alumno.\n");
		printf("2. Imprimir alumnos.\n");
		printf("3. Buscar estudiante por posicion de ingreso.\n");
		printf("4. Buscar estudiante por edad.\n");
		printf("5. Buscar estudiante por mes de nacimiento.\n");
		printf("6. Salir.\n");
		scanf("%hi", &opc);

		switch(opc){
			case 1:
				lecturaArreglo();
				error(-2, 0);
				break;
			case 2:
				if(cantActualEstudiantes > 0){
					impresionArreglo();
				} else {
					error(-1, 0);
				}
				error(-2, 0);
				break;
			case 3:
				if(cantActualEstudiantes > 0){
					buscarEstudiantePosicion();
				} else {
					error(-1, 0);
				}
				error(-2, 0);
				break;
			case 4:
				if(cantActualEstudiantes > 0){
					buscarEstudianteEdad();
				} else {
					error(-1, 0);
				}
				error(-2, 0);
				break;
			case 5:
				if(cantActualEstudiantes > 0){
					buscarEstudianteMes();
				} else {
					error(-1, 0);
				}
				error(-2, 0);
				break;
			case 6:
				return;
				break;
			default:
				error(1, 6);
		}
	}while(true);
}

void buscarEstudianteMes(){
	int i;
	short auxMes;
	bool bandera = false;
	
	do{
		printf("\n\nPor favor ingrese la edad de estudiante a buscar:\n");
		scanf("%hi", &auxMes);
		if(auxMes < 1 || auxMes > 12){
			error(1, 12);
		} else {
			break;
		}
	}while(true);
	
	printf("\n\nSu(s) estudiante(s) es(son):");
	
	for(i = 0; i < cantActualEstudiantes; i++){
		if(miEstudiante[0].miFecha.mes == auxMes){
			printf("\n\nPara el estudiante %i, el codigo: %s.\n", (i + 1), miEstudiante[i].codigo);
			printf("\nPara el estudiante %i, el nombre: %s.\n", (i + 1), miEstudiante[i].nombre);
			printf("\nPara el estudiante %i, la edad: %hi.\n", (i + 1), miEstudiante[i].edad);
			printf("\nPara el estudiante %i, el dia de nacimiento: %hi.\n", (i + 1), miEstudiante[i].miFecha.dia);
			printf("\nPara el estudiante %i, el mes de nacimiento: %hi.\n", (i + 1), miEstudiante[i].miFecha.mes);
			printf("\nPara el estudiante %i, el anio de nacimiento: %hi.\n", (i + 1), miEstudiante[i].miFecha.anio);
			printf("\nPara el estudiante %i, la ciudad: %s.\n", (i + 1), miEstudiante[i].ciudad);
			bandera = true;
		}
	}
	
	if(!bandera){
		printf("\n\nNo hubo ningun estudiante con mes de nacimiento de %hi.\n", auxMes);
	}
}

void buscarEstudianteEdad(){
	int i;
	short auxEdad;
	bool bandera = false;
	
	do{
		printf("\n\nPor favor ingrese la edad de estudiante a buscar:\n");
		scanf("%hi", &auxEdad);
		if(auxEdad < 1 || auxEdad > 100){
			error(1, 100);
		} else {
			break;
		}
	}while(true);
	
	printf("\n\nSu(s) estudiante(s) es(son):");
	
	for(i = 0; i < cantActualEstudiantes; i++){
		if(miEstudiante[0].edad == auxEdad){
			printf("\n\nPara el estudiante %i, el codigo: %s.\n", (i + 1), miEstudiante[i].codigo);
			printf("\nPara el estudiante %i, el nombre: %s.\n", (i + 1), miEstudiante[i].nombre);
			printf("\nPara el estudiante %i, la edad: %hi.\n", (i + 1), miEstudiante[i].edad);
			printf("\nPara el estudiante %i, el dia de nacimiento: %hi.\n", (i + 1), miEstudiante[i].miFecha.dia);
			printf("\nPara el estudiante %i, el mes de nacimiento: %hi.\n", (i + 1), miEstudiante[i].miFecha.mes);
			printf("\nPara el estudiante %i, el anio de nacimiento: %hi.\n", (i + 1), miEstudiante[i].miFecha.anio);
			printf("\nPara el estudiante %i, la ciudad: %s.\n", (i + 1), miEstudiante[i].ciudad);
			bandera = true;
		}
	}
	
	if(!bandera){
		printf("\n\nNo hubo ningun estudiante con edad de %hi.\n", auxEdad);
	}
}

void buscarEstudiantePosicion(){
	short auxPosicion;
	
	do{
		printf("\n\nPor favor ingrese la posicion del estudiante a buscar:\n");
		scanf("%hi", &auxPosicion);
		if(auxPosicion < 1 || auxPosicion > cantActualEstudiantes){
			error(1, cantActualEstudiantes);
		} else {
			break;
		}
	}while(true);
	
	printf("\n\nSu estudiante es:");
	printf("\nPara el estudiante %i, el codigo: %s.\n", auxPosicion, miEstudiante[auxPosicion - 1].codigo);
	printf("\nPara el estudiante %i, el nombre: %s.\n", auxPosicion, miEstudiante[auxPosicion - 1].nombre);
	printf("\nPara el estudiante %i, la edad: %hi.\n", auxPosicion, miEstudiante[auxPosicion - 1].edad);
	printf("\nPara el estudiante %i, el dia de nacimiento: %hi.\n", auxPosicion, miEstudiante[auxPosicion - 1].miFecha.dia);
	printf("\nPara el estudiante %i, el mes de nacimiento: %hi.\n", auxPosicion, miEstudiante[auxPosicion - 1].miFecha.mes);
	printf("\nPara el estudiante %i, el anio de nacimiento: %hi.\n", auxPosicion, miEstudiante[auxPosicion - 1].miFecha.anio);
	printf("\nPara el estudiante %i, la ciudad: %s.\n", auxPosicion, miEstudiante[auxPosicion - 1].ciudad);
}

void impresionArreglo(){
	int i;
	
	for(i = 0; i < cantActualEstudiantes; i++){
		printf("\n\nPara el estudiante %i, el codigo: %s.\n", (i + 1), miEstudiante[i].codigo);
		printf("\nPara el estudiante %i, el nombre: %s.\n", (i + 1), miEstudiante[i].nombre);
		printf("\nPara el estudiante %i, la edad: %hi.\n", (i + 1), miEstudiante[i].edad);
		printf("\nPara el estudiante %i, el dia de nacimiento: %hi.\n", (i + 1), miEstudiante[i].miFecha.dia);
		printf("\nPara el estudiante %i, el mes de nacimiento: %hi.\n", (i + 1), miEstudiante[i].miFecha.mes);
		printf("\nPara el estudiante %i, el anio de nacimiento: %hi.\n", (i + 1), miEstudiante[i].miFecha.anio);
		printf("\nPara el estudiante %i, la ciudad: %s.\n", (i + 1), miEstudiante[i].ciudad);
	}
}

void lecturaArreglo(){
	if(cantActualEstudiantes < CANTESTUDIANTES){
		printf("\n\nPara el estudiante %i, ingrese el codigo:\n", (cantActualEstudiantes + 1));
		fflush(stdin);
		gets(miEstudiante[cantActualEstudiantes].codigo);
		
		printf("\nPara el estudiante %i, ingrese el nombre:\n", (cantActualEstudiantes + 1));
		fflush(stdin);
		gets(miEstudiante[cantActualEstudiantes].nombre);
		
		do{
			printf("\nPara el estudiante %i, ingrese la edad:\n", (cantActualEstudiantes + 1));
			scanf("%hi", &miEstudiante[cantActualEstudiantes].edad);
			if(miEstudiante[cantActualEstudiantes].edad < 1 || miEstudiante[cantActualEstudiantes].edad > 100){
				error(1, 100);
			} else {
				break;
			}
		}while(true);
		
		do{
			printf("\nPara el estudiante %i, ingrese el dia de nacimiento:\n", (cantActualEstudiantes + 1));
			scanf("%hi", &miEstudiante[cantActualEstudiantes].miFecha.dia);
			if(miEstudiante[cantActualEstudiantes].miFecha.dia < 1 || miEstudiante[cantActualEstudiantes].miFecha.dia > 31){
				error(1, 31);
			} else {
				break;
			}
		}while(true);
		
		do{
			printf("\nPara el estudiante %i, ingrese el mes de nacimiento:\n", (cantActualEstudiantes + 1));
			scanf("%hi", &miEstudiante[cantActualEstudiantes].miFecha.mes);
			if(miEstudiante[cantActualEstudiantes].miFecha.mes < 1 || miEstudiante[cantActualEstudiantes].miFecha.mes > 12){
				error(1, 12);
			} else {
				break;
			}
		}while(true);
		
		do{
			printf("\nPara el estudiante %i, ingrese el anio de nacimiento:\n", (cantActualEstudiantes + 1));
			scanf("%hi", &miEstudiante[cantActualEstudiantes].miFecha.anio);
			if(miEstudiante[cantActualEstudiantes].miFecha.anio < 1 || miEstudiante[cantActualEstudiantes].miFecha.anio > 2019){
				error(1, 2019);
			} else {
				break;
			}
		}while(true);
		
		printf("\nPara el estudiante %i, ingrese la ciudad:\n", (cantActualEstudiantes + 1));
		fflush(stdin);
		gets(miEstudiante[cantActualEstudiantes].ciudad);
		
		cantActualEstudiantes += 1;
	} else {
		printf("\n\nTamanio maximo completo.\n");
		system("PAUSE");
		system("CLS");
	}
}

/*
	SI SE ENVIA -1 SIGNIFICA QUE EL ERROR ES POR NO HABER INGRESADO POR LO MENOS UN ESTUDIANTES ANTES DE PEDIR ALGUNA OTRA OPCION.
	SI SE ENVIA -2 SIGNIFICA QUE SOLO SE USARA EL PAUSE Y EL CLS POR CUESTION DE ORDEN.
	SI SE ENVIA CUALQUIER OTRO VALOR SE IMPRIMIRA EL RANGO.
*/
void error(short min, short max){
	if(min != -2){
		if(min != -1){
			printf("\nHa ocurrido un error, ingrese un dato valido entre %hi y %hi.\n", min, max);
		} else {
			printf("\nHa ocurrido un error, debe ingresar por lo menos un estudiante.\n");
		}
	}
	printf("\n");
	system("PAUSE");
	system("CLS");
}

