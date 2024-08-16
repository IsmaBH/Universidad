class objeto:
    def __init__(self,indice,valor,peso):
        self.__indice = indice
        self.__valor = valor
        self.__peso = peso
        self.__costo = valor/peso
    #Metodos get de la clase
    def getIndice(self):
        return self.__indice
    def getValor(self):
        return self.__valor
    def getPeso(self):
        return self.__peso
    def getCosto(self):
        return self.__costo

#Funcion que implementa el algoritmo de la mochila fraccionaria
def kpf(listaObjetos,pT):
    listaObjetos.sort(key = lambda x: x.getCosto(),reverse = True)
    espacioRestante = pT
    solucion = []
    for i in range(len(listaObjetos)):
        if (listaObjetos[i].getPeso() > espacioRestante):
            fraccion = espacioRestante / listaObjetos[i].getPeso()
            objeto = (listaObjetos[i].getIndice(),listaObjetos[i].getPeso() * fraccion,listaObjetos[i].getValor() * fraccion)
            solucion.append(objeto)
        else:
            objeto = (listaObjetos[i].getIndice(),listaObjetos[i].getPeso(),listaObjetos[i].getValor())
            solucion.append(objeto)
            espacioRestante -= listaObjetos[i].getPeso()
    return solucion
#Codigo de prueba del algoritmo
print("Introduce las cadenas de pesos y valores en ese orden")
p = [int(x) for x in input().split()]
v = [int(y) for y in input().split()]
print("Introduce el peso maximo de la mochila")
pT = int(input())
#Se construye la lista de objetos
listaObjetos = []
for i in range(len(p)):
    listaObjetos.append(objeto(i+1,v[i],p[i]))
#Hacemos uso del algoritmo de la mochila
resultado = kpf(listaObjetos,pT)
#Imprimimos el resultado
print("Los objetos elegidos son ", end = "")
print(resultado)
#Imprimimos el valor obtenido
print("El valor total obtenido es: " + str(sum([valor[2] for valor in resultado])))
