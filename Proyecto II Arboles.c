#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//Struct del arbol que se va a utilizar
//posee dos punteros a su derecha e izquierda
typedef struct arbol{
    char link[600];
    char alias[100];

    struct arbol *derecha;
    struct arbol *izquierda;

}arbol;

//struct de apoyo para poder crear una lista
//con los respectivos links

typedef struct links {

    char *link[200];
    struct linkes *sigu;

}links;

//Variable de control ya sea para manejar
//el arbol o la lista de links o bien
//manejar un sistema de opciones

arbol *raiz=NULL;
links *primer=NULL;
links *ultimo=NULL;
int oP;


//Prototipos de funciones que
// se usan en el programa
void opcionesMenu();
void insertarURL(char *l, char *k);
void addURL();
void mostrarLinks(arbol *reco);
void buscarURL(arbol *k, char *j);
void eliminarLink(arbol *reco, char *k);
void eliminarPorOpcionLink(arbol *r);
void addTOP();
void descargarTOP();
void recorrerString(char t[]);
void addArbolTop();

//Funcion utilizada para saber si hay que hacer algo más
//ya sea volver al menu o salir del programa
//no recibe nada ni retorna nada

void returnOpMenu(){

    int op;
    printf("Desea hacer otra cosa?\n");
    printf("1.Sí o 2.No");
    scanf("%d", &op);
    switch (op){
        case 1:
            opcionesMenu();
            break;
        case 2:
            exit(-1);

        default:
            printf("Digito una opcion incorrecta\n");
            returnOpMenu();
            break;
    }
}




//Añade el url y llama a insertarUrl, no recibe nada
//ni retorna nada ademas pregunta si desea ingresar un alias

void addURL(){
    int d;
    char k[200];
    char j[210]="https://";
    char noAlias[10]= "NOALIAS";
    char *alias[50];
    printf("Recuerde NO ingresar el link con https://\n");
    printf("Ingresa la direccion\n");
    scanf("%s", k);
    strcat(j,k);
    printf("¿Desea agregar un alias?\n");
    printf("1.Sí o 2.No");
    scanf("%d", &d);
    if(d==1){
        printf("Digita tu alias\n");
        scanf("%s", &alias);
        insertarURL(j, alias);
    }else{
        insertarURL(j, noAlias);
    }

}

//Inserta el url, dentro del arbol
// no recibe un dos punteros a caracteres
// y no retorna nada

void insertarURL(char *l, char *k){


    arbol *nuevo= (arbol*)malloc(sizeof(arbol));
    strcpy(nuevo->link, l);
    strcpy(nuevo->alias, k);
    nuevo->derecha=NULL;
    nuevo->izquierda=NULL;

    if(raiz==NULL) {
        raiz = nuevo;

    }

    else {

        arbol *ant, *reco;
        ant = NULL;
        reco = raiz;
        while (reco != NULL) {

            ant = reco;
            if (strcmp(l, reco->link) < 0) {
                reco = reco->izquierda;
            } else {
                reco = reco->derecha;
            }
        }

        if (strcmp(l, ant->link) < 0) {
            ant->izquierda = nuevo;

        } else {
            ant->derecha = nuevo;
        }
    }

}

//Funcion que recibe un puntero a un arbol
//y no retorna nada, llama a una funcion que busca
//y pregunta si este encontro el link

void buscarURLX(arbol*t){

    oP=0;
    char aBuscar[200];
    printf("Ingrese el URL a buscar\n");
    printf("Recuerde ingresar el link con https://\n");
    scanf("%s", &aBuscar);

    buscarURL(t, aBuscar);


    if(oP==1){
        printf("Link encontrado con exito\n");
    }else{
        printf("No existe el link \n");
    }
    oP=0;
}

//funcion que recibe un puntero a un arbol
//y un puntero a caracteres recorre el arbol
//buscando el link deseado no retorna nada

void buscarURL(arbol *reco, char *aBuscar){

    if(reco!=NULL) {
        if (strcmp(reco->link, aBuscar) == 0) {

            char word[220] = "xdg-open ";
            oP= 1;
            strcat(word, reco->link);
            system(word);

        } else {
            buscarURL(reco->izquierda, aBuscar);
            buscarURL(reco->derecha, aBuscar);
            oP=0;

        }

    }


}


//funcion que recibe un puntero a un arbol
//y un puntero a caracteres recorre el arbol
//buscando el alias deseado no retorna nada

void buscarAlias(arbol *reco, char *aBuscar){

    if(reco!=NULL) {
        if (strcmp(&reco->alias, aBuscar) == 0) {
            char word[220] = "xdg-open ";
            oP=1;
            strcat(word, reco->link);
            system(word);

        } else {
            buscarAlias(reco->izquierda, aBuscar);
            buscarAlias(reco->derecha, aBuscar);
            oP=0;
        }

    }

}

//Funcion que recibe un puntero a un arbol
//y no retorna nada, llama a una funcion que busca
//y pregunta si este encontro el alias

void buscarAliasX(arbol *t){

    oP=0;
    char aBuscar[200];
    printf("Ingrese el alias a buscar");

    scanf("%s", &aBuscar);
    buscarAlias(t, aBuscar);

    if(oP==1){
        printf("Link encontrado con exito\n");
    }else{
        printf("No existe el link \n");
    }
    oP=0;

}

//Funcion que recibe un puntero al arbol y no
//retorna nada, recorre el arbol en preorden
//e imprime

void mostrarLinks(arbol *reco){

    if (reco != NULL){
        printf("\n");
        printf("%s", reco->link);
        printf("\n");
        printf("%s", &reco->alias);
        printf("\n");
        mostrarLinks(reco->izquierda);
        mostrarLinks(reco->derecha);

    }

}


//Funcion que recibe un puntero al arbol y un puntero
//a un arreglo de chars no retorna nada, recorre
//el arbol hasta encontrarlo y eliminarlo

void eliminarLink(arbol *reco, char *k){

    if(reco!=NULL) {
        if (strcmp(reco->link, k) == 0) {
            free(reco);
        } else {
            eliminarLink(reco->izquierda, k);
            eliminarLink(reco->derecha, k);
        }
    }

}

//Funcion que recibe un arbol y llama a eliminarlink
//solo captura el link que se desea eliminar no retorna nada

void eliminarPorOpcionLink(arbol *r){

    char k[200];
    printf("Digite el link que desea eliminar\n");
    printf("Recuerde ingresar el link con https://\n");
    scanf("%s",&k);
    eliminarLink(r, k);

}

//Funcion que recibe un puntero al arbol y un puntero
//a un arreglo de chars no retorna nada, recorre
//el arbol hasta encontrarlo y eliminarlo

void eliminarLinkPorAlias(arbol *reco, char *k){

    if(reco!=NULL) {
        if (strcmp(reco->alias, k) == 0) {
            free(reco);
        } else {
            eliminarLink(reco->izquierda, k);
            eliminarLink(reco->derecha, k);
        }
    }

}
//Funcion que recibe un arbol y llama a eliminarlink
//solo captura el alias que se desea eliminar no retorna nada

void eliminarPorOpcionAlias(arbol *r){

    char k[200];
    printf("Digite el alias que desea eliminar\n");
    scanf("%s",&k);
    eliminarLinkPorAlias(r, k);

}

//Funcion de manejo de archivos, no recibe ni retorna nada
//lee el archivo y va llamando a recorrerString hasta leer
//todas las lineas del archivo y luego cierra el flujo

void addTOP() {
    int i;
    int c=0;
    char aux;
    char temp[200];

    FILE *flujo = fopen("/home/bryan/Downloads/top500Domains.csv", "rb");
    if (flujo == NULL) {
        perror("Error en la apertura del archivo\n");
    }

    while(!feof(flujo)) {
        fgets(temp, 200, flujo);
        recorrerString(temp);
    }
    fclose(flujo);
}

//Construye una lista con nodos de cada linea del archivo
//donde en cada nodo se guarda el link en un arreglo de chars
//recibe un arreglo de caracteres y no retorna nada

void addLista(char t[]){
    int c=0;
    links *l= (links*)malloc(sizeof(links));
    char j[210] = "https://";
    strcat(j,t);
    strcpy(l->link, j);
    if(primer==NULL){
        primer= l;
        primer->sigu=NULL;
        ultimo=l;
    }else{
        ultimo->sigu=l;
        l->sigu=NULL;
        ultimo=l;
    }


}

//recorre el string que se le pase leyendo caracter a caracter
//y luego llama a addLista con link creado no retorna nada
//y recibe un arreglo de chars y no retorna nada

void recorrerString(char t[]) {

    char aux = '0';

    int c = 0;
    int j = 0;
    char link[100];

    while (t[c] != ',') {
        aux = t[c];
        c++;
    }

    aux = t[c + 1];


    if (aux == '"') {

        c++;
        c++;
        aux = t[c];

        while (t[c] != '"') {
            if (t[c] =='\0') {
                break;
            } else {
                aux = t[c];
                link[j] = aux;
                j++;
                c++;

            }

        }
        link[j] = '\0';
    }
    addLista(link);

}

//Funcion de administrador xD recorre la lista
//e imprime los links no recibe ni retorna nada

void imprimirListaDeLinks(){

    links *temp= (links*)malloc(sizeof(links));
    temp= primer;
    int c=0;
    while(temp->sigu!= NULL){
        printf("%s\n", temp->link);
        temp= temp->sigu;
    }
    returnOpMenu();
}



//Recorre la lista y coge de cada nodo el link
//y lo añade al arbol luego lo inserta
//no retorna ni recibe nada

void addArbolTop() {

    links *l = (links*) malloc(sizeof(links));
    l = primer->sigu;

    while (l->sigu!=NULL) {
        char noAlias[10]= "NOALIAS";
        insertarURL(l->link, noAlias);
        l=l->sigu;
    }
}

//No recibe ni retorna nada conecta al servidor y descarga el archivo CSV

void descargarTOP(){
    system("xdg-open https://moz.com/top-500/download/?table=top500Domains");
    printf("Por favor espere...\n");
    sleep(10);
    addTOP();
    printf("Descarga lista!!\n");
    addArbolTop();
    returnOpMenu();

}
//Funcion que recibe un puntero al arbol y un puntero
//a un arreglo de chars no retorna nada, recorre
//el arbol hasta encontrar el alias y luego lo
//actualiza

void actAlias(arbol *reco, char *aBuscar ){

    if(reco!=NULL) {
        if (strcmp(&reco->link, aBuscar) == 0) {
            oP=1;
            printf("Digite el nuevo alias\n");
            scanf("%s", reco->alias);
            printf("Actualizado correctamente\n");


        } else {
            actAlias(reco->izquierda, aBuscar);
            actAlias(reco->derecha, aBuscar);
            oP=0;
        }

    }

}
//Funcion que recibe un puntero a un arbol
//y no retorna nada, llama a una funcion que busca
//y pregunta si este es el alias luego lo actualiza

void actualizarAlias(arbol *t) {
    oP=0;
    char aBuscar[200];
    printf("Recuerde ingresar el link con https://\n");
    printf("Ingrese el URL al que desea cambiar alias\n");
    scanf("%s", &aBuscar);

    actAlias(t, aBuscar);


    if(oP==1){
        printf("Alias cambiado con exito\n");

    }else{
        printf("No existe el link \n");
    }
    oP=0;
}


//Funcion del menú, muestra las diversas opciones
// No recibe nada ni tampoco retorna nada

void opcionesMenu(){
    int d;
    printf("================\n");
    printf("1. Añadir URL\n");
    printf("2. Buscar por URL\n");
    printf("3. Buscar por Alias\n");
    printf("4. Ver links guardados\n");
    printf("5. Descargar el top 500 de URL\n");
    printf("6. Eliminar por Link\n");
    printf("7. Eliminar por Alias\n");
    printf("8. Actualizar Alias\n");
    printf("9. Salir\n");
    printf("Por favor digite una opcion:\n");
    printf("================\n");
    scanf("%d", &d);
    switch(d){
        case 1:
            addURL();
            returnOpMenu();
            break;
        case 2:
            buscarURLX(raiz);
            returnOpMenu();
            break;
        case 3:
            buscarAliasX(raiz);
            returnOpMenu();
            break;
        case 4:
            mostrarLinks(raiz);
            returnOpMenu();
            break;
        case 5:
            descargarTOP();
            returnOpMenu();
            break;
        case 6:
            eliminarPorOpcionLink(raiz);
            returnOpMenu();
            break;
        case 7:
            eliminarPorOpcionAlias(raiz);
            returnOpMenu();
        case 8:
            actualizarAlias(raiz);
            returnOpMenu();

        case 9:
            exit(-1);


        case 27:
            imprimirListaDeLinks();

        default:
            printf("Digito una opcion invalida\n");
            printf("Por favor digite una opcion:\n");
            opcionesMenu();
    }
}




//Main su funcion es llamar a las opciones del menu
//no recibe ni retorna nada
void main(){
    opcionesMenu();
}
