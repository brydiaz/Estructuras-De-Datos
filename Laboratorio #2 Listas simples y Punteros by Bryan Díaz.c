#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//Laboratorio #2 Listas simples y punteros by Bryan DÌaz

//Autor del codigo:
	//Bryan Andrey DÌaz Barrientos
	//Carnet: 2019264426
	//Curso: Estructuras de Datos
	//Profesora: MSc.Samanta Ramijan Carmion


//Se crea una estructura que me permita acceder
//a los estudiantes, adem·s debe contener un puntero
//que me lleve a la siguiente

typedef struct estudiante{
	int *carnet;
	char *nombre;
	struct estudiante *siguiente;
}estudiante;

//con estas variables manejo donde apunta
// el ultimo dato de la lista y el primero

estudiante *primero= NULL;
estudiante *ultimo= NULL;

// Manejar funciones

void NuevoEstudiante();

void validar();

//Esta estructura genera un nuevo estudiante
// y lo logra aÒadir a la lista *NOTA: NO HE LOGRADO
//HACER QUE FUNCIONE CON M¡S DE UN USO*

void NuevoEstudiante() {
	int opcion;
	estudiante *nuevo= (estudiante*) malloc	(sizeof(estudiante));
	printf("Ingrese el carnet del estudiante\n");
	scanf("%d",&nuevo->carnet);
	printf("Ingrese el nombre del estudiante\n");
	scanf("%s",nuevo->nombre);

	if (primero== NULL){
		primero= nuevo;
		primero->siguiente= NULL;
		ultimo= nuevo;
	}else{
		ultimo->siguiente= nuevo;
		nuevo->siguiente= NULL;
		ultimo= nuevo;
	}
	printf("Estudiante ingresado con exito\n");
	printf("Desea a√±adir otro?\n");
	printf("Por favor solo use 1 para S√ç y 2 para NO\n");
	scanf("%d", &opcion);
	if (opcion== 1){
		NuevoEstudiante();
	}else{

		printf("Desea validar una posicion?\n");
		printf("Por favor solo use 1 para S√ç y 2 para NO\n" );
		scanf("%d", &opcion);
		if (opcion== 1){
			validar();
	}else{
		printf("Gracias\n");
		system("PAUSE");
		exit(-1);
	}
}
}


//Esta funcion funciona para poder validar que el dato
//sea el mismo que su antecesor, al no poder en NuevoEstudiante
// poder hacer que funcione m·s de un uso no puedo verificar
// como aplicar la recursividad

void validar(){
	estudiante *actual=(estudiante*)malloc(sizeof(estudiante));
	int posicion;
	posicion=0;
	actual= primero;
	int *carnet_validar;
	if (primero!= NULL){
		printf("Por favor digite el carnet en %d\n", posicion);
		scanf("%d", &carnet_validar);
		if (carnet_validar!= actual->carnet){
			printf("No son iguales\n");
			printf("Siguente posicion\n");
			posicion++;
			actual=actual->siguiente;

		}else{
			printf("El carnet es correcto\n");
			printf("Siguiente posicion\n");
			posicion++;
			actual=actual->siguiente;
		}


	}else{
		printf("Todas han sido validadas o la lista est√° vac√≠a\n");
		printf("Gracias por usar\n");
		exit(-1);
		system("PAUSE");


	}
}

//Funcion de main la cual llama a sus otras funciones

int main(){
	int opcion;
	printf("Bienvenido\n");
	printf("Desea a√±adir un estudiante?\n");
	printf("Por favor solo use 1 para S√ç y 2 para NO\n");
	scanf("%d", &opcion);
	if (opcion==1){
		NuevoEstudiante();

	}else{
		printf("Gracias\n");
		system("PAUSE");
		exit(-1);

	}
	return 0;
}
