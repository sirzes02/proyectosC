#include <stdio.h>
#include <string.h>

class Tarea{
	private:
		char nombre[100];
		char estado[12];
		char prioridad[12];
	
	public:	
		Tarea(char nombre[100], char estado[12], char prioridad[12]);
				
		const char * getNombre(void);
		void setNombre(char nombre[100]);
		const char * getEstado(void);
		void setEstado(char estado[12]);
		const char * getPrioridad(void);
		void setPrioridad(char prioridad[12]);		
};

Tarea::Tarea(char nombre[100], char estado[12], char prioridad[12]){
	strcpy(Tarea::nombre, nombre);
	strcpy(Tarea::estado, estado);
	strcpy(Tarea::prioridad, prioridad);
}

const char * Tarea::getNombre(void){
	return nombre;
}

void Tarea::setNombre(char nombre[100]){
	strcpy(Tarea::nombre, nombre);
}

const char * Tarea::getEstado(void){
	return estado;
}

void Tarea::setEstado(char estado[12]){
	strcpy(Tarea::estado, estado);
}

const char * Tarea::getPrioridad(void){
	return prioridad;
}

void Tarea::setPrioridad(char prioridad[12]){
	strcpy(Tarea::prioridad, prioridad);
}

