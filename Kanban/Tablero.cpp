#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tarea.cpp"
#define FILAS 5
#define COLUMNAS 5

using namespace std;

class Tablero{
	private:
		const char * RUTALECTURA = "./data/lectura.txt";
		const char * RUTAESCRITURA = "./data/escritura.txt";
		short cantTareas;
		Tarea miTarea[0][0];
		
	public:
		Tablero(char ruta[30]);
		
		short getCantTareas(void);
		Tarea getMiTarea(short num);
		short getFILAS(void);
		short getCOLUMNAS(void);
		void crearTarea(char nombre[30], char estado[12], char prioridad[12]);
		void borrarTarea(char nombre[30]);
		void modificarTarea(char nombreViejo[30], char nombre[30], char estado[12], char prioridad[12]);
		void lecturaDatos(char ruta[30]);
		void escrituraDatos(void);
		void reporte(void);
};

Tablero::Tablero(char ruta[30]){
	cantTareas = 0;
	miTarea[FILAS][COLUMNAS];
	Tablero::lecturaDatos(ruta);
}

short Tablero::getCantTareas(void){
	return cantTareas;
}

Tarea Tablero::getMiTarea(short num){
	return miTarea[num / COLUMNAS][num % COLUMNAS];
}

short Tablero::getFILAS(void){
	return FILAS;
}

short Tablero::getCOLUMNAS(void){
	return COLUMNAS;
}

void Tablero::crearTarea(char nombre[30], char estado[12], char prioridad[12]){	
	for(int i = 0; i < cantTareas; i++){
		if(strcmp(getMiTarea(i).getNombre(), nombre) == 0){
			printf("\nError, este nombre ya existe.\n");
			return;
		}
	}
	
	if(cantTareas < FILAS * COLUMNAS){
		for(int i = 0; i < cantTareas; i++){
			if(strcmp(getMiTarea(i).getNombre(), "") == 0){
				miTarea[i / COLUMNAS][i % COLUMNAS].setNombre(nombre);
				miTarea[i / COLUMNAS][i % COLUMNAS].setEstado(estado);
				miTarea[i / COLUMNAS][i % COLUMNAS].setPrioridad(prioridad);
				//escrituraDatos();
				return;
			}
		}
		miTarea[cantTareas / COLUMNAS][cantTareas % COLUMNAS].setNombre(nombre);
		miTarea[cantTareas / COLUMNAS][cantTareas % COLUMNAS].setEstado(estado);
		miTarea[cantTareas / COLUMNAS][cantTareas % COLUMNAS].setPrioridad(prioridad);
		cantTareas++;
		//escrituraDatos();
	} else printf("\nError, matriz llena.\n");
}

void Tablero::borrarTarea(char nombre[30]){
	for(int i = 0; i < cantTareas; i++){
		if(strcmp(getMiTarea(i).getNombre(), nombre) == 0){
			miTarea[i / COLUMNAS][i % COLUMNAS].setNombre("");
			escrituraDatos();
			return;
		}
	}
}

void Tablero::modificarTarea(char nombreViejo[30], char nombre[30], char estado[12], char prioridad[12]){
	for(int i = 0; i < cantTareas; i++){
		if(strcmp(getMiTarea(i).getNombre(), nombreViejo) == 0){
			miTarea[i / COLUMNAS][i % COLUMNAS].setNombre(nombre);
			miTarea[i / COLUMNAS][i % COLUMNAS].setEstado(estado);
			miTarea[i / COLUMNAS][i % COLUMNAS].setPrioridad(prioridad);
			escrituraDatos();
			return;
		}
	}
}

void Tablero::lecturaDatos(char ruta[30]){
	FILE *archivo;
	char nombre[30], estado[12], prioridad[12], cant[2];
		
	archivo = fopen(RUTALECTURA, "r");
	
	if(archivo == NULL){
		printf("No existe el archivo.\n");
		exit(0);
	} else {
		rewind(archivo);
		fscanf(archivo, "%s", &cant);
		for(int i = 0; i < atoi(cant); i++){
			fscanf(archivo, " %[^\n]", nombre);
			fscanf(archivo, " %[^\n]", estado);
			fscanf(archivo, " %[^\n]", prioridad);
			crearTarea(nombre, estado, prioridad);
			printf(getMiTarea(i).getNombre());
		}
	}
	fclose(archivo);
}

void Tablero::escrituraDatos(void){
	short cont = 0;
	for(int i = 0; i < cantTareas; i++){
		if(strcmp(getMiTarea(i).getNombre(), "") == 0){
			cont++;
		}
	}
	printf("num: %hi", cont);
}

void Tablero::reporte(void){
	
}

int main(int argc, char **argv){
	Tablero prueba("");
	prueba.escrituraDatos();
}

