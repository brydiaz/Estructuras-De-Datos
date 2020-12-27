#Librerias a utilizar cv2 para utilizar el reconocimiento
#de imagenes y numpy en complemento a cv2
from builtins import print

import numpy as np
import cv2
import networkx as nx
import matplotlib.pyplot as plt
import random
from networkx.algorithms import tree
#Obtencion de la imagen a utilizar
from matplotlib.font_manager import weight_dict

img = cv2.imread("/home/bryan/Downloads/ImagenPython/figuras.jpg")
#Conversion a hsv pues por defecto trabaja con RGB
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

#Obtencion del color verde en su expresion más baja
#y su expresion más alta además crea la mascara
#que se encarga de identificar todos los verdes

verdeBajos = np.array([49, 100, 20])
verdeAltos = np.array([80, 255, 255])
maskVerde = cv2.inRange(hsv, verdeBajos, verdeAltos)

#Obtencion del color azul en su expresion más baja
#y su expresion más alta además crea la mascara
#que se encarga de identificar todos los azules

azulesBajos= np.array([100, 100, 20])
azulesAltos= np.array([137, 255, 255])
maskAzul = cv2.inRange(hsv, azulesBajos, azulesAltos)

#Obtencion del color rojo en su expresion más baja
#y su expresion más alta además crea la mascara
#que se encarga de identificar todos los rojos
#como la el rojo existe dos veces en la paleta
#de colores se busca ambas veces

rojoBajo1= np.array([0, 100, 20])
rojoAlto1= np.array([10, 255, 255])
rojoBajo2= np.array([175, 100, 20])
rojoAlto2= np.array([180, 255, 255])

#crea la mascara del primer y segundo rojo
#luego los une y crea la mascara definitiva
maskRoja1= cv2.inRange(hsv, rojoBajo1, rojoAlto1)
maskRoja2=cv2.inRange(hsv,rojoBajo2,rojoAlto2)
maskRoja= cv2.add(maskRoja1, maskRoja2)

amarilloAlto= np.array([32, 255, 255])
amarilloBajo= np.array([20, 100, 20])
maskamarillo= cv2.inRange(hsv, amarilloBajo, amarilloAlto)

moraditoAlto= np.array([145, 255, 255])
moraditoBajo= np.array([130, 100, 20])
maskMoradito= cv2.inRange(hsv, moraditoBajo, moraditoAlto)

#Clase para manejar el objeto figura

class figura:

    def __init__(self,num=None, tipo=None, color=None, siguiente=None):
        self.num=num
        self.tipo = tipo
        self.color = color
        self.siguiente = siguiente

#clase que permite emular las listas enlazadas simples
#con un metodo agregar y de imprimir

class listaSimple:

    def __init__(self):
        self.primer = None
        self.ultimo = None

    def agregar(self,num, tipo, color):
        temp = figura(num,tipo, color)

        if self.primer == None:
            temp.siguiente = None
            self.primer = temp
            self.ultimo = temp
        else:
            temp.siguiente = None
            self.ultimo.siguiente = temp
            self.ultimo = temp

    def imprimir(self):
        temp = self.primer
        while temp != None:
            print(temp.tipo)
            print(temp.num)
            print(temp.color)
            temp = temp.siguiente

#Otras variables de control

listaFiguras = listaSimple()
numero=1
grafo= nx.Graph()
grafoCreado= False

#Funcion que recibe la mascara a buscar y el nombre del color
# no retorna nada busca las lineas de cada figura si esta tiene cierta cantidad
#define que figura es. Y si la mascara no detecta nada entonces no hay nada
#de ese color


def detectarFigura(numero,mask, color):


    contours, h = cv2.findContours(mask, 1, 2)

    for cnt in contours:
        approx = cv2.approxPolyDP(cnt, 0.01 * cv2.arcLength(cnt, True), True)

        if len(approx) == 5:
            listaFiguras.agregar(numero,"Pentagono", color)
            numero = numero + 1

        elif len(approx) == 3:
            listaFiguras.agregar(numero,"Triangulo", color)
            numero = numero + 1


        elif len(approx) == 6:
            listaFiguras.agregar(numero,"Hexagono", color)
            numero = numero + 1


        elif len(approx) == 4:
            listaFiguras.agregar(numero,"Cuadrado", color)
            numero = numero + 1

        elif len(approx) == 7:
            listaFiguras.agregar(numero,"Heptagono", color)
            numero = numero + 1
        elif len(approx) == 8:
            listaFiguras.agregar(numero,"Octagono", color)
            numero = numero + 1


    return numero

#Funcion que crea el grafo recorre la lista anteriormente creada
#creando nodos con la informacion de cada figura
#primero añade todos los nodos luego ensalsa por tipo
#cuando termina el proceso enlaza por color no recibe ni retorna nada

def crearGrafo():

    temp=listaFiguras.primer

    while temp!= None:
        grafo.add_node(temp)
        temp=temp.siguiente

    temp = listaFiguras.primer
    c=0

    while(temp!=None):
        tempo=listaFiguras.primer
        nodo=obtenerNodo(temp)
        while(tempo!=None):
            nodoAux= obtenerNodo(tempo)
            if(nodo.tipo==nodoAux.tipo):
                randitom= random.randrange(100)
                grafo.add_edge(nodo, nodoAux, weight=randitom)
                tempo= tempo.siguiente
            else:
                tempo = tempo.siguiente
        temp=temp.siguiente

    temp = listaFiguras.primer

    while (temp != None):
        tempo = listaFiguras.primer
        nodo = obtenerNodo(temp)
        while (tempo != None):
            nodoAux = obtenerNodo(tempo)
            if (nodo.color == nodoAux.color):
                randitom = random.randrange(100)
                grafo.add_edge(nodo, nodoAux, weight=randitom)
                tempo = tempo.siguiente
            else:
                tempo = tempo.siguiente
        temp = temp.siguiente

    return



#Funcion auxiliar recibe un nodo
#pregunta si este esta lo retorna y sino no retorna nada

def obtenerNodo(nodo):

    if nodo in grafo:
        return nodo
    else:
        return None

#Funcion auxiliar que recibe la figura y el color
#esta recorre los nodos y si lo encuentra lo retorna

def verificarNodo(fig, color):
    listaNodos= list(grafo.edges())
    c=0
    lista=list()
    while(c!=len(listaNodos)):
        t=0
        tupla = listaNodos[c]
        while(t!=len(tupla)):
            lista.append(tupla[t])
            t=t+1
        c=c+1

    c=0
    while(c!= len(lista)):
        if lista[c].tipo== fig:
            if lista[c].color== color:
                return lista[c]
            else:
                c=c+1
        else:
            c=c+1
    return None


#Funcion que pregunta de donde a donde quieres ir
#no recibe nada y retorna la lista con las figuras más optimas

def rutaMasEficiente():
    print("\n")

    print("Tipos disponibles:")
    print("Cuadrado, Triangulo, Pentagono, Hexagono, Octagono, Heptagono")
    print("Colores disponibles:")
    print("AZUL, VERDE, ROJO, AMARILLO")
    print("Por favor sea especifico así se encontrará con exito la ruta")
    print("\n")
    figP=input("Digite la figura de partida")
    colP=input("Digite el color de partida")
    print("\n")

    nodoPartida= verificarNodo(figP, colP)

    if nodoPartida== None:
        print("\n")
        print("El nodo no existe")
        print("\n")
    else:
        print("\n")
        figL = input("Digite la figura de llegada")
        colL = input("Digite el color de llegada")
        nodoLlegada= verificarNodo(figL, colL)

        if nodoLlegada==None:
            print("El nodo no existe")
        else:
            solucion= list(nx.algorithms.dijkstra_path(G= grafo, source=nodoPartida, target=nodoLlegada))
            c=0
            while c!= len(solucion):
                print("Figura: "+solucion[c].tipo+" "+ "Color: "+solucion[c].color)
                c=c+1
        print("\n")
    return

#Funcion que genera el arbol recubridor minimo utilizando Prim
#no recibe nada y retorna los nodos que generan el arbol recubridor minimo

def arbolRecubridorMinimoPrim():
    print("\n")
    print("El arbol recubridor minimo con Prim es: ")
    solucion = list(tree.minimum_spanning_edges(grafo, algorithm= "prim"))
    c = 0
    print(len(solucion))

    while c != len(solucion):
        tupla=solucion[c]
        print("Figura: " + tupla[0].tipo + " " + "Color: " + tupla[0].color)
        print("Figura: " + tupla[1].tipo + " " + "Color: " + tupla[1].color)

        c = c + 1
    print("\n")
    print("MANERA ALTERNATIVA:")
    print(solucion)
    print("\n")

    return
#Menu del programa no recibe ni retorna nada

def opcionesMenu():

    print(">>1. Visualizar imagen cargada")
    print(">>2. Reconocer las figuras por color y forma")
    print(">>3. Construir el grafo a partir de figuras reconocidas")
    print(">>4. Imprimir grafo de manera grafica")
    print(">>5. Encontrar ruta más eficiente entre una figura y otra")
    print(">>6. Arbol Recubridor Minimo con Prim")

    opcion=int(input(">>Digite su opcion<<"))

    if opcion==1:
        cv2.imshow('img', img)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
        opcionesMenu()

    elif opcion==2:
        act=detectarFigura(numero,maskVerde, "VERDE")
        act2=detectarFigura(act,maskAzul, "AZUL")
        act3= detectarFigura(act2, maskamarillo, "AMARILLO")
        act4= detectarFigura(act3, maskMoradito, "MORADITO")
        detectarFigura(act4,maskRoja, "ROJO")
        print("\n")
        print(">>>>>>>>>>>>Imagen revisada<<<<<<<<<<<")
        print("\n")
        opcionesMenu()

    elif opcion==3:
        if(listaFiguras.primer==None):
            print("\n")
            print(">>>>>>>>>>La imagen no ha sido cargada al programa<<<<<<<<<<<")
            print("\n")
            opcionesMenu()
        else:
            if grafo.size()==0:
                crearGrafo()
                listaGraf = list(grafo)
                print("\n")
                print(">>>>>>>>>>>>>>>Grafo creado exitosamente<<<<<<<<<<<<<<")
                print("\n")
                opcionesMenu()

            else:
                print("\n")
                print(">>>>>>>>>>>>El grafo ya fue creado<<<<<<<<<<<<<")
                print("\n")
                opcionesMenu()

    elif opcion==4:

        if grafo.size()==0:
            print("\n")
            print(">>>>>>>>>>>>El grafo no ha sido creado<<<<<<<<<<<<<")
            print("\n")
            opcionesMenu()
        else:
            nx.draw(grafo)

            nodos= list(grafo.nodes())
            aristas= list(grafo.edges())
            c=0
            print("\n")
            print(">>>>>>>>>>>>>NODOS<<<<<<<<<<<<<<<")
            while c!= len(nodos):
                print(nodos[c].tipo+ " " +nodos[c].color)
                c=c+1
            c=0
            print(">>>>>>>>>>>>>>>>>>>>>ARISTAS<<<<<<<<<<<<<<<<<")
            while c!= len(aristas):
                tupla=aristas[c]
                h=0
                print(tupla[h].tipo+" "+tupla[h].color+" "+tupla[h+1].tipo+" "+tupla[h+1].color)
                print("Con un peso de: "+ str(grafo[tupla[h]][tupla[h+1]]['weight']))
                c=c+1
            print("\n")
            plt.savefig("simple_path.png")  # save as png
            plt.show()  # display
            opcionesMenu()

    elif opcion==5:
        if grafo.size()==0:
            print("\n")
            print(">>>>>>>>>>>>El grafo no ha sido creado<<<<<<<<<<<<<")
            print("\n")
            opcionesMenu()
        else:
            rutaMasEficiente()
            opcionesMenu()


    elif opcion==6:
        if grafo.size()==0:
            print("\n")
            print(">>>>>>>>>>>>El grafo no ha sido creado<<<<<<<<<<<<<")
            print("\n")
            opcionesMenu()
        else:
            arbolRecubridorMinimoPrim()
            opcionesMenu()


    return

opcionesMenu()