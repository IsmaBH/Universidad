#Implementación de una estrategia greedy para el problema de la seleccion de actividades
class actividad:
    def __init__(self,indice,horaInicio,horaTermino):
        self.__indice = indice
        self.__inicio = horaInicio
        self.__termino = horaTermino
    #Metodos de la clase
    def getIndice(self):
        return self.__indice
    def getInicio(self):
        return self.__inicio
    def getTermino(self):
        return self.__termino

#Funcion que implementa el algoritmo
def seleccion(listaActividades):
    listaActividades.sort(key = lambda x: x.getTermino(),reverse = False)
    actividades = 1
    solucion = [listaActividades[0]]
    #Con un ciclo for recorremos las actividades
    for m in range(1,len(listaActividades)):
        candidato = listaActividades[m]
        if (candidato.getInicio() >= solucion[actividades-1].getTermino()):
            solucion.append(candidato)
            actividades += 1
    return solucion,actividades

#Codigo main para probar el algoritmo
print("Introduce las horas de inicio y termino en ese orden")
i = [float(x) for x in input().split()]
t = [float(y) for y in input().split()]
#Construimos la lista de actividades
listaActividades = []
for j in range(len(i)):
    listaActividades.append(actividad(j+1,i[j],t[j]))
#Hacemos uso del algoritmo
resultado,actividades = seleccion(listaActividades)
#Imprimimos los resultados
print("Las actividades elejidas son: ", end = "")
for i in range(len(resultado)):
    print(str(resultado[i].getIndice()) + " ", end = "")
print("")
#Imprimimos la cantidad total de actividades
print("El numero total de actividades es: " + str(actividades))
