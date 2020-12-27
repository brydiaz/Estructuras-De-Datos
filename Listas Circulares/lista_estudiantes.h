/**********************************************************************
    Instituto Tecnológico de Costa Rica
    Estructuras de Datos IC-2001
    II Semestre 2019
    Profesora: Samanta Ramijan Carmiol
    Ejemplos Prácticos: Lista de Estudiantes
    Estudiante: Bryan Díaz Barrientos 2019264426
**********************************************************************/
//Definición de Macros
#define LONGITUD_MAXIMA_NOMBRE 50
#define LONGITUD_MAXIMA_CARNET 12

//Definición de Estructuras
typedef struct nodo_estudiante
{
	int carnet;
	char *nombre;

	struct nodo_estudiante *ref_siguiente;
}nodo_estudiante;

typedef struct lista_estudiantes
{
	nodo_estudiante *ref_inicio;
	int cantidad;
}lista_estudiantes;

//Definición de Funciones
/*-----------------------------------------------------------------------
	crear_nodo
	Entradas: No recibe parámetros
	Salidas: Retorna un puntero de tipo nodo_estudiante al nodo creado
	Funcionamiento:
		- Solicita al usuario ingresar Nombre y Carnet.
		- Crea un puntero de tipo nodo_estudiante
		- Le asigna al nodo el nombre y carnet ingresados.
		- El nodo apunta a NULL.
		- retorna el puntero al nuevo nodo.
-----------------------------------------------------------------------*/
nodo_estudiante* crear_nodo();
/*-----------------------------------------------------------------------
	inicializar_lista
	Entradas: No recibe nada
	Salidas: Un nodo de tipo estudiante
	Funcionamiento: Primero lo que hace es obtener el nombre
									por medio del usuario, y verificar que tenga
									el largo definido anteriormente, despues lo que
									hace es crear memoria para un estudiante y prosigue
									a crearlo.
-----------------------------------------------------------------------*/
void inicializar_lista();
/*-----------------------------------------------------------------------
	insertar_inicio
	Entradas: No recibe nada
	Salidas: No regresa nada
	Funcionamiento: Primero pide memoria para una lista de estudiantes
									y la crea donde su elmento que es el siguiente apunta
									al NULL
-----------------------------------------------------------------------*/
void insertar_inicio(nodo_estudiante* nuevo);
/*-----------------------------------------------------------------------
	insertar_final
	Entradas: Recibe un nodo de tipo estudiante
	Salidas: No regresa nada
	Funcionamiento: Primero revisa si hay una lista creada
									si no hay, llama a la funcion que la crea
									si esta creada le dice verifica si la lista
									esta vacia en ese caso solo añade al estudiante
									sino cambia que este estudiante apunte al que haya
									ya en la lista y que el que esta en el inicio de la lista
									apunte a su siguiente
-----------------------------------------------------------------------*/
void insertar_final(nodo_estudiante* nuevo);
/*-----------------------------------------------------------------------
	borrar_por_indice
	Entradas: Recibe un nodo de tipo estudiante
	Salidas: No regresa nada
	Funcionamiento: Primero revisa si hay una lista creada
									si no hay, llama a la funcion que la crea
									si esta creada le dice verifica si la lista
									esta vacia en ese caso solo añade al estudiante
									sino crea un estudiante temporal que recorra la lista
									hasta topar con el NULL y una vez allí cambia el temporal
									por el nuevo
-----------------------------------------------------------------------*/
void borrar_por_indice(int indice);
 /*-----------------------------------------------------------------------
	buscar_por_indice
	Entradas: Recinbe un numero de tipo int
	Salidas: No retorna nada
	Funcionamiento: Crea un estudiante temporal para poder
									movernos por la lista primero pregunta si la lista
									esta vacia y si lo esta PUES PARA QUE VA A BORRAR xD
									y crea una variable cont de tipo int que se usará adelante,
									despues de este verifica en la lista si el indice resulta
									ser más grande que el largo de la lista entonces la posicion
									esta fuera del rango si paso estas pruebas entonces busca
									si el indice es igual a 0 entonces borra lo que que haya en
									posicion sino hará un ciclo hasta igualar el indice y
									una variable cont (esta será la que se vaya actualizando)
									y cuando la encuntra primero le dice a la lista que el
									elemento que haya antes de ese apunte al siguiente del que se
									va a borrar y despues libera memoria.
-----------------------------------------------------------------------*/
nodo_estudiante* buscar_por_indice(int indice);

 /*-----------------------------------------------------------------------
	validar_carnets
	Entradas: Recibe un numero de tipo int
	Salidas:	Nodo de tipo estudiante llamado temporal
	Funcionamiento: Crea un estudiante temporal para poder
									movernos por la lista primero pregunta si la lista
									esta vacia y si lo esta PUES PARA QUE VA A BORRAR xD
									y crea una variable cont de tipo int que se usará adelante,
									despues de este verifica en la lista si el indice resulta
									ser más grande que el largo de la lista entonces la posicion
									esta fuera del rango si paso estas pruebas entonces mientras
									el siguiente de nuestro temporal sea distinto del NULL
									preguntara si el indice y el cont son igual sino lo son
									aumenta el cont en uno y vuelve a hacer y si son iguales
									retorna nuestro temporal
-----------------------------------------------------------------------*/
void validar_carnets(int carnet_almacenado, int carnet_ingresado);
 /*-----------------------------------------------------------------------
	menu
	Entradas: Recibe dos carnets ambos de tipo int
	Salidas: No retorna nada
	Funcionamiento: Compara ambos carnets y si son iguales retorna que son iguales
									hace lo mismo en caso contrario solo que dice que no son
									iguales
-----------------------------------------------------------------------*/
void menu();
 /*-----------------------------------------------------------------------
	main
	Entradas: No recibe nada
	Salidas: No retorna nada
	Funcionamiento: Primero define el tamaño maximo para cada variable
									luego hace muchas impresiones xD, hace un switch que es una
									funcion que permite evaluar casos simples y dependiendo de una
									opcion mandará a llamar a la funcion que corresponde
-----------------------------------------------------------------------*/
int main();
 /*-----------------------------------------------------------------------
	get_user_input
	Entradas: No recibe nda
	Salidas: Retorna un 0
	Funcionamiento: Llama al menu
-----------------------------------------------------------------------*/
char* get_user_input(size_t max_size);
 /*-----------------------------------------------------------------------
	get_user_numerical_input
	Entradas: Recibe una variable de tipo size_t que fue previamente definida
	Salidas: retorna un char llamado buffer
	Funcionamiento: Primero pide memoria y verifica si si pudo obtenerla
									sino informará del error en memoria si sí pudo entonces
									obtendra del usuario el input la cual modificara para que
									su ultima posicion sea 0 y luego lo retorna
-----------------------------------------------------------------------*/
int get_user_numerical_input(size_t max_size);
