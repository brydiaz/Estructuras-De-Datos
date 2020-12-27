#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//Laboratorio #3 Listas simples by Bryan Diaz

//Autor del codigo:
	//Bryan Andrey Diaz Barrientos
	//Carnet: 2019264426
	//Curso: Estructuras de Datos
	//Profesora: MSc.Samanta Ramijan Carmion


//Se crea una estructura que me permita acceder
//a los estudiantes, ademas debe contener un puntero
//que me lleve al siguiente estudiante

typedef struct estudiante{
	int carnet;
	char *nombre;
	struct estudiante *siguiente;
}estudiante;

//con estas variables manejo donde apunta
// el ultimo dato de la lista y el primero

estudiante *primero= NULL;
estudiante *ultimo= NULL;

// Manejar funciones

void NuevoEstudianteAlFinal();
void NuevoEstudianteAlInicio();
void opciones_menu();
void validar();
void EliminarEstudiante();
void volverAmenu();
//Esta estructura genera un nuevo estudiante
// y lo agrega al final de la lista

void NuevoEstudianteAlFinal() {
	char nuevo_nombre[20];
	int opcion;
	estudiante *nuevo= (estudiante*) malloc	(sizeof(estudiante));
	printf("Ingrese el carnet del estudiante\n");
	scanf("%d",&nuevo->carnet);
	printf("Ingrese el nombre del estudiante\n");
	scanf("%s",nuevo_nombre);
	strcpy(nuevo_nombre, nuevo->nombre);

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
	printf("Desea incluir otro?\n");
	printf("Por favor solo use 1 para Si y 2 para NO\n");
	scanf("%d", &opcion);
	if (opcion== 1){
		NuevoEstudianteAlFinal();
	}else{
		volverAmenu(opcion);
	}
}

//Esta funcion genera un estudiante y lo a�ade
//al inicio de la lista

void NuevoEstudianteAlInicio(){
	char nuevo_nombre[20];
	int opcion;
	estudiante *nuevo= (estudiante*) malloc	(sizeof(estudiante));
	printf("Ingrese el carnet del estudiante\n");
	scanf("%d",&nuevo->carnet);
	printf("Ingrese el nombre del estudiante\n");
	scanf("%s",nuevo_nombre);
	strcpy(nuevo_nombre, nuevo->nombre);

	if (primero== NULL){
		primero= nuevo;
		primero->siguiente= NULL;
		ultimo= nuevo;
	}else{
		ultimo->siguiente= NULL;
		nuevo->siguiente= primero;
		primero= nuevo;
	}
	printf("Estudiante ingresado con exito\n");
	printf("Desea incluir otro?\n");
	printf("Por favor solo use 1 para Si y 2 para NO\n");
	scanf("%d", &opcion);
	if (opcion== 1){
		NuevoEstudianteAlInicio();
	}else{
		volverAmenu(opcion);
	}
}

//Esta funcion pregunta por la posicion que se desea validar
//despues de encontrar el archivo que si quiere validar
//compara y determina si son iguales.
void validar(){
	estudiante *actual=(estudiante*)malloc(sizeof(estudiante));
	int posicion;
	int opcion;
	int nuevo_carnet;
	actual= primero;
	printf("Por favor digite la posicion\n");
	printf("Recuerde solo usar numeros enteros\n");
	scanf("%d", &posicion);
	int largo;
	largo= 0;
	while(posicion!=largo){
		actual= actual->siguiente;
		largo++;
	}
	printf("Digite el nuevo carnet\n");
	scanf("%d", &nuevo_carnet);
	if (nuevo_carnet!= actual->carnet){
		printf("No son iguales\n");
		printf("Desea verificar otra posicion?\n");
		printf("Por favor solo use 1 para Si y 2 para NO\n" );
		scanf("%d", &opcion);
		if (opcion == 1){
			validar();
		}else{
			volverAmenu(opcion);
		}
	}else{
		printf("Los carnets son iguales\n");
		printf("Desea verificar otra posicion\n");
		printf("Por favor solo use 1 para Si y 2 para NO\n" );
		scanf("%d", &opcion);
		if (opcion == 1){
			validar();
		}else{
			volverAmenu(opcion);
		}

	}
}
//Funcion que pregunta cual posicion que hace referencia
//a un estudiante lo encuentra hace que su anterior apunte
//a su siguiente y libera la memoria usada por el actual

void EliminarEstudiante(){
	estudiante *actual=(estudiante*)malloc(sizeof(estudiante));
	estudiante *anterior=(estudiante*)malloc(sizeof(estudiante));
	int posicion;
	int opcion;
	int largo;
	actual= primero;
	anterior= actual;
	printf("Por favor digite la posicion que desea eliminar\n");
	printf("Recuerde solo usar numeros enteros\n");
	scanf("%d", &posicion);
	largo=0;
	while(posicion!=largo){
		anterior= actual;
		actual= actual->siguiente;
		largo++;
	}
	anterior= actual->siguiente;
	free(actual);
	printf("El estudiante fue eliminado con exito\n");
	printf("Desea eliminar otro? 1.Si o 2.No\n");
	printf("Recuerde solo usar numeros enteros\n");
	scanf("%d",&opcion);
	if (opcion== 1){
		EliminarEstudiante();
	}else{
		volverAmenu(opcion);

	}
}

//Funcion que pregunta si quiere volver al menu
//y lo retorna a este

void volverAmenu(int opcion){
	printf("Desea volver a menu?\n");
	printf("Por favor solo use 1 para Si y 2 para NO\n" );
	scanf("%d", &opcion);
	if (opcion== 1){
		opciones_menu();
		}else{
			printf("Gracias\n");
			system("PAUSE");
			exit(-1);
		}
}

//Esta funcion crea el menu y admemas da acceso
//en base a la desicion del usuario para llamar
//a cada metodo del programa

void opciones_menu(){
	int opcion;
	printf("1. Insertar un estudiante al final de la lista\n");
	printf("2. Insertar un estudiante al inicio de la lista\n");
	printf("3. Verificar el carnet de un estudiante en una posicion dada\n");
	printf("4. Eliminar de la lista a un estudiante en una posicion dada\n");
	printf("5. Salir\n");
	printf("\n");
	printf("Cual opcion desea ejecutar?\n");
	scanf("%d",&opcion);

	switch(opcion){
		case 1:
			NuevoEstudianteAlFinal();
			break;
		case 2:
			NuevoEstudianteAlInicio();
			break;
		case 3:
			validar();
			break;
		case 4:
			EliminarEstudiante();
			break;
		case 5:
			printf("Gracias por utilizar\n");
			exit(-1);
		default:
			printf("No selecciono una opcion valida, vuelva a intentar\n");
	}; opciones_menu();
	system("PAUSE");
};


//Main que llama al menu y de alli empieza todo el programa

int main(){
	printf("Bienvenid@\n");
	opciones_menu();
	return 0;
}
