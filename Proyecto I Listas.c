#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct Carta{

  char *familia;
  int valor;
  int valorReal;
  struct Carta *siguiente;
  struct Carta *anterior;

}Carta;

Carta *primera = NULL;
Carta *ultima = NULL;
Carta *actual= NULL;

Carta *primeraDes = NULL;
Carta *ultimaDes = NULL;
Carta *actualDes= NULL;



int espadas= 0;
int corazones= 13;
int diamantes= 26;
int treboles= 39;
int listaBaraja[52];

char familiaEspada[20]= "E";
char familiaCorazones[20]="C";
char familiaDiamantes[20]="D";
char familiaTreboles[20]="T";

void opcionesMenu();
void crearBaraja();
void imprimirBaraja();
void cartaSiguiente();
void cartaAnterior();
void ordenar();
void barajar();
void mostrarActual();
int aleatorio();
int lenLista();

void crearBaraja(){
	int cont= 1;
	int valorCarta=2;
	while(cont!=54){
		Carta *nueva= (Carta*)malloc(sizeof(Carta));
		if (primera==NULL){
			nueva->valor= 1;
			nueva->valorReal= cont;
			primera= nueva;
			ultima= nueva;
			ultima->siguiente=NULL;
			ultima->anterior= NULL;
			actual= primera;
			cont++;

		}else{
			if (valorCarta >= 14){
				valorCarta= valorCarta-13;
			}
			nueva->valor= valorCarta;
			nueva->valorReal= cont;
			
			ultima->siguiente= nueva;
			nueva->anterior= ultima;
			
			ultima= nueva;
			ultima->siguiente= NULL;


			valorCarta++;
			cont++;
			}

	}

}
		
void imprimirCarta(Carta *t){
		if(t->valorReal<=13){
   			imprimirHeader(t->valor);
            printf("        |     E     |\n");
            printf("        |           |\n");
            printf("        |           |\n");
			imprimirPie(t->valor);
            
		}
		else if(t->valorReal<=26){
			imprimirHeader(t->valor);
            printf("        |     C     |\n");
            printf("        |           |\n");
            printf("        |           |\n");
			imprimirPie(t->valor);


		}
		else if(t->valorReal<=39){
            imprimirHeader(t->valor);
            printf("        |     D     |\n");
            printf("        |           |\n");
            printf("        |           |\n");
			imprimirPie(t->valor);


		}

		else if(t->valorReal<=52){
   			imprimirHeader(t->valor);
            printf("        |     T     |\n");
            printf("        |           |\n");
            printf("        |           |\n");
			imprimirPie(t->valor);

		}
}

int imprimirHeader(int valor){
	if (valor== 13){
    	printf("        -----------\n");
   		printf("        |K          |\n");
    	printf("        |           |\n");
    	printf("        |           |\n");
		}
    else if (valor== 1){
			printf("         -----------\n");
   			printf("        |A          |\n");
    		printf("        |           |\n");
    		printf("        |           |\n");
			}
	
 	else if (valor== 12){
			printf("         -----------\n");
   			printf("        |Q          |\n");
    		printf("        |           |\n");
    		printf("        |           |\n");
			}

    else if (valor== 11){
			printf("         -----------\n");
   			printf("        |J          |\n");
    		printf("        |           |\n");
    		printf("        |           |\n");
		}

    else if (valor== 10){
			printf("         -----------\n");
   			printf("        |10         |\n");
    		printf("        |           |\n");
    		printf("        |           |\n");
			}
	else{
				printf("         -----------\n");
   				printf("       	|%i          |\n", valor);
    			printf("        |           |\n");
    			printf("        |           |\n");
		}

	return 0;
}

int imprimirPie(int valor){
	if(valor==13){
        printf("        |         K |\n");
        printf("         -----------\n");
	}
	else if(valor==1){
        printf("        |         A |\n");
        printf("         -----------\n");
	}
	else if(valor==12){
        printf("        |         Q |\n");
        printf("         -----------\n");
	}
	else if(valor==11){
        printf("        |         J |\n");
        printf("         -----------\n");
	}
	else if(valor==10){
        printf("        |        10 |\n");
        printf("         -----------\n");
	}
	else{
        printf("        |         %i |\n",valor);
        printf("         -----------\n");
	}
	return 0;
}
void imprimirBaraja(){
	Carta *temp= (Carta*)malloc(sizeof(Carta));
	temp= primera;
	int cont=0;
	while(temp->siguiente!= NULL){
		printf("%d", cont);
		imprimirCarta(temp);
		temp= temp->siguiente;
		cont++;
	}
	printf("%d", cont);
	imprimirCarta(temp);
	opcionesMenu();
}


void mostrarActual(){
    Carta *temp= (Carta*)malloc(sizeof(Carta));
	temp= actual;
	imprimirCarta(temp);

}

void mostrarSiguiente(){
	if (actual->siguiente== NULL){
		actual=primera;
		imprimirCarta(actual);
	}else{
		actual= actual->siguiente;
		imprimirCarta(actual);
	}
}

void mostrarAnterior(){
    if (actual->anterior== NULL){
		actual=ultima;
		imprimirCarta(actual);
	}else{
		actual= actual->anterior;
		imprimirCarta(actual);
	}
}

		
void opcionesMenu(){
	int opcion;
	int ciclo =1;
	while(ciclo){
		printf("\n---------------------------------------------------------------------");
		printf("\n(1) Mostrar Carta Actual");
		printf("\n(2) Mostrar siguente carta");
		printf("\n(3) Mostrar carta anterior");
		printf("\n(4) Mostrar Toda la baraja");
		printf("\n(5) Ordenar");
		printf("\n(6) Barajar");
		printf("\n(7) Salir");
		printf("\n---------------------------------------------------------------------");
		printf("\n>> Opcion deseada: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				mostrarActual();
				break;

			case 2:
				mostrarSiguiente();
				break;
			case 3:
				mostrarAnterior();
				break;

			case 4:
				imprimirBaraja();
				
				break;
			case 5:
				if(primera->valorReal==1){
					printf("\nPrimero desordena la baraja");
					break;
				}else{
					ordenar();
				}
				break;
			case 6:
				barajar();
				break;

			case 7:
				exit(-1);
				break;
			default: opcionesMenu();
		}
	}
}

int lenLista(){
    Carta *temp= (Carta*)malloc(sizeof(Carta));
    temp= primera;
    int c=0;
    while(temp->siguiente!= NULL){
		temp= temp->siguiente;
		c++;
	}
	return c;
}


int aleatorio(int len){
    int r;
    srand(time(NULL));
    r= rand()%len+1;

    return r;
}

void barajar(){

	int a;
	int i=0;
	Carta *temp= (Carta*)malloc(sizeof(Carta));
	int len=lenLista();
	
	while (len!= 0){
		i= 0;
		a= aleatorio(len);
		temp= primera;
		while(i!= a){
			temp= temp->siguiente;
			i++;
		}
		if(temp->siguiente== NULL){
			temp->anterior->siguiente=NULL;
			temp->anterior= NULL;
			

  		}else{
				temp->anterior->siguiente= temp->siguiente;
				temp->siguiente->anterior= temp->anterior;
  		}
		temp->siguiente=NULL;
		temp->anterior= NULL;

		len= lenLista();
		if( primeraDes==NULL){
            primeraDes= temp;
			primeraDes->anterior= NULL;
			ultimaDes= temp;
			ultimaDes->siguiente=NULL;
			ultimaDes->anterior= NULL;
			actualDes= primeraDes;

		}else{
			ultimaDes->siguiente= temp;
			temp->anterior= ultimaDes;
			ultimaDes= temp;
			ultimaDes->siguiente= NULL;
  			}
	}
    actual= actualDes;
	primera=primeraDes;
	ultima= ultimaDes;
	primeraDes= NULL;
	ultimaDes=NULL;
	actualDes= NULL;

	
}
int pivot(int *unarray, int izq, int der)
{
    int i;
    int pivote, valor_pivote;
    int aux;

    pivote = izq;
    valor_pivote = unarray[pivote];
    for (i=izq+1; i<=der; i++){
        if (unarray[i] < valor_pivote){
                pivote++;
                aux=unarray[i];
                unarray[i]=unarray[pivote];
                unarray[pivote]=aux;

        }
    }
    aux=unarray[izq];
    unarray[izq]=unarray[pivote];
    unarray[pivote]=aux;
    return pivote;
}

void Quicksort(int *unarray, int izq, int der)
{
     int pivote;
     if(izq < der){
        pivote=pivot(unarray, izq, der);
        Quicksort(unarray, izq, pivote-1);
        Quicksort(unarray, pivote+1, der);
     }
}

void ordenar(){
	int listaReal[54];
	listaReal[0]= 1;
	Carta *temp= (Carta*)malloc(sizeof(Carta));
	Carta *nueva= (Carta*)malloc(sizeof(Carta));
	temp= primera;
	int c=1;
	int valorCarta= 2;
	
	while(temp->siguiente!= NULL){
		listaReal[c]= temp->valorReal;
		temp= temp->siguiente;
		c++;
		}
	
	Quicksort(listaReal, 0, lenLista()-1);

	
	c=1;
	
	while(c != lenLista()){
        Carta *nueva= (Carta*)malloc(sizeof(Carta));
		if (primeraDes==NULL){

			nueva->valor= 1;
			nueva->valorReal= 1;
			primeraDes= nueva;
			ultimaDes= nueva;
			ultimaDes->siguiente=NULL;
			ultimaDes->anterior= NULL;
			actualDes= primeraDes;
			c++;

		}else{
			if (valorCarta >= 14){
				valorCarta= valorCarta-13;
			}
			nueva->valor= valorCarta;
			nueva->valorReal= listaReal[c-1];

			ultimaDes->siguiente= nueva;
			nueva->anterior= ultimaDes;

			ultimaDes= nueva;
			ultimaDes->siguiente= NULL;


			valorCarta++;
			c++;
			}

		
	}
	actual= actualDes;
	primera= primeraDes;
	ultima= ultimaDes;
	primeraDes= NULL;
	ultimaDes=NULL;
	actualDes= NULL;
}

void main(){
	crearBaraja();
	opcionesMenu();
}
