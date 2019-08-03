//Laboratorio #1 Arreglos y Strucks by Bryan Díaz

//Autor del codigo:
	//Bryan Andrey Díaz Barrientos
	//Carnet: 2019264426
	//Curso: Estructuras de Datos
	//Profesora: MSc.Samanta Ramijan Carmion


// Primero importo las bibliotecas a utilizar
// la clasica stdio y para poder manejar todo lo
// relacionado a los Strings string.h

#include <stdio.h>
#include <string.h>

// Segundo se crea la estructura del estudiante
// que tiene un carnet que solo va a guardar numeros
// y una cadena de caracteres que guardara el nombre


struct estudiante{
	int carnet;
	char nombre[20];
};

// Se crean la funcion principal

int main(){

//Se declaran las variables
	int posicion;
	int indice;
	int opcion;
	int nuevo_carnet;
	char nuevo_nombre[20];
	
// Se crea el arreglo utilazando el struct
// es decir un arreglo de 10 estudiantes
// que poseen la estructura del struct "estudiante"


	struct estudiante estudiantes[9];

// Se forma un mecanismo que da al usuario la posibilidad
// de añadir diez estudiantes

	for (indice=0; indice<=9; ++indice){
		printf("Por favor digite el nombre del estudiante\n");
		scanf("%s", nuevo_nombre);
        strcpy(estudiantes[indice].nombre, nuevo_nombre );
		printf("Por favor digite el carnet del estudiante\n");
		printf("Recuerde usar numeros sino, no funcionara\n");
		scanf("%d", &nuevo_carnet);
		estudiantes[indice].carnet= nuevo_carnet;
	}

// En este punto ya definido el arreglo con sus integrentes
// se procede a incitar al usuario a verificar los carnets
// mas es opcional y si no se requiere el programa se cierra


	printf("¿Desea verificar los carnets?\n");
	printf("Por favor seleccione usando 1 y 2\n");
	printf("1.Sí o 2.No\n");
	scanf("%d",&opcion);
	if (opcion== 1){

		for (indice=0; indice<=9; ++indice){

			printf("¿Qué posición de carnet desea validar?\n");
			printf("Recuerde usar numeros sino, no funcionara\n");
			scanf("%d", &posicion);
			printf("¿Cuál es el carnet del estudiante?\n");
			printf("Recuerde usar numeros sino, no funcionara\n");
			scanf("%d", &nuevo_carnet);
			if (estudiantes[posicion].carnet== nuevo_carnet){
				printf("El carnet ingresado es correcto\n");
				printf("Siguiente posicion\n");

				}
				else{
					printf("El carnet ingresado no corresponde con la posición\n");
					printf("Siguiente posicion\n");

					}
			}
			}
			else{
				printf("Gracias por utilizar\n");
				system("PAUSE");
				exit(-1);

			}
	printf("Todas las posiciones han sido verificadas\n");
	printf("Gracias por utilizar\n");
    system("PAUSE");
};


