class nodo:

    def __init__(self, valor=None, siguiente=None):
        self.valor = valor
        self.siguiente = siguiente



class listaEnlazada:

    def __init__(self):
        self.primer = None
        self.ultimo=None

    def agregarInicio(self, valor):
        temp= nodo(valor)
        if self.primer==None:
            temp.siguiente = None
            self.primer = temp
            self.ultimo = temp
        else:
            temp.siguiente = self.primer
            self.primer = temp
            del temp

    def agregarFinal(self, valor):

        temp= nodo(valor)
        if self.primer== None:
            temp.siguiente= None
            self.primer= temp
            self.ultimo=temp

        else:
            temp.siguiente=None
            self.ultimo.siguiente=temp
            self.ultimo= temp

    def impLista(self):
        temp= self.primer
        while temp!= None:
            print(temp.valor)
            temp= temp.siguiente

    def lenLista(self):
        c=0
        temp = self.primer
        while temp != None:
            c=c+1
            temp = temp.siguiente

        print(c)
        print("\n")
        return c

    def busqueda(self, valorAbuscar):
        b=0
        temp = self.primer
        if(temp==None):
            print("El indice no existe en lista o no hay elementos\n")
        else:
            while b != valorAbuscar:
                if(temp.siguiente==None):
                    print("El indice no existe en lista\n")
                    return menu()
                else:
                    temp = temp.siguiente
                    b=b+1
            print("El valor que contenia el nodo a buscar es:\n")
            print(temp.valor)
            print("\n")
            return(temp.valor)

    def limpiarLista(self):
        temp= self.primer

        while temp.siguiente!= None:
            aux=temp
            temp= temp.siguiente
            del aux.valor
            del aux.siguiente


miLista = listaEnlazada()



def agrInicio():
    x = int(input("Digite un valor por favor\n"))
    miLista.agregarInicio(x)
    print("Agregado con exito\n")

    return menu()



def agrFinal():
    x= int(input("Digite un valor por favor\n"))

    miLista.agregarFinal(x)
    print("Agregado con exito\n")

    return menu()



def aBuscar():
    x = int(input("Digite un indice a buscar\n"))
    miLista.busqueda(x)
    return menu()



def menu():
    print("1.Agregar dato al inicio de la lista")
    print("2.Agregar dato al final de la lista")
    print("3.Imprimir lista")
    print("4.Tamaño de lista")
    print("5.Buscar por indice")
    print("6.Eliminar Lista")

    j = int(input("Por favor solo las opciones que se dan a elegir\n"))

    if j == 1:
        agrInicio()

    elif j == 2:
        agrFinal()

    elif j == 3:
         miLista.impLista()
    elif j==4:
        miLista.lenLista()
    elif j==5:
        aBuscar()
    elif j==6:
        miLista.limpiarLista()
    else:
        print("Digite una opcion valida\n")
    return menu()

menu()