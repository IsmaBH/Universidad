#Implementación greedy de los codigos de huffman
import sys #Esta biblioteca es para el manejo de archivos y lectura por linea de comando
from collections import Counter #Este modulo nos es de utilidad para contar las repeticiones de un caracter dentro de nuestro archivo
import heapq #Dado que el arbol a construir es un min-heap binario, utilizamos esta para ayudar en la construcción
import pickle
import json
#Lo primero sera tener una función que nos ayude a calcular las probabilidades de cada simbolo
def obtenerProbabilidades(contenido):
    total = len(contenido) + 1 #Se agrega uno por el caracter de finalizacion
    c = Counter(contenido)
    res = {}
    for char,count in c.items():
        res[char] = float(count) / total
    res['end'] = 1.0/total
    return res
#Ahora una función que nos ayude a crear el arbol
def crearArbol(probabilidades):
    q = []
    for caracter,prob in probabilidades.items():
        #La fila de prioridad esta ordenada por prioridad y profundidad
        heapq.heappush(q,(prob,0,caracter))
    while len(q) > 1:
        e1 = heapq.heappop(q)
        e2 = heapq.heappop(q)
        nuevo_e = (e1[0]+e2[0],max(e1[1],e2[1])+1,[e1,e2])
        heapq.heappush(q,nuevo_e)
    return q[0]
#El siguiente paso es crear el diccionario de codificación
def crearDiccionario(arbol):
    res = {}
    pila_busqueda = []
    #El ultimo elemento de la lista es el prefijo
    pila_busqueda.append(arbol+("",))
    while len(pila_busqueda) > 0:
        elm = pila_busqueda.pop()
        if type(elm[2]) == list:
            prefijo = elm[-1]
            pila_busqueda.append(elm[2][1]+(prefijo+"0",))
            pila_busqueda.append(elm[2][0]+(prefijo+"1",))
            continue
        else:
            res[elm[2]] = elm[-1]
        pass
    return res
#La siguiente función se encargara de convertir los datos del archivo original con el codigo generado por el diccionario
def compresion(dic,contenido):
    res = ""
    for caracter in contenido:
        codigo = dic[caracter]
        res = res + codigo
    #Ahora agregamos el caracter final e inicial
    res = '1' + res + dic['end']
    #Agregamos ceros para convertir en multiplo de 8
    res = res + (len(res) % 8 * "0")
    return int(res,2)
#Por ultimo tenemos una función que guarda en un archivo el nuevo mensaje
def guardar(mensaje,dic,nombre_a):
    #Guardamos el mensaje con el nombre dado
    fichero_salida = open(nombre_a,'wb')
    pickle.dump(mensaje,fichero_salida)
    fichero_salida.close()
    #Guardamos el diccionario en otro archivo con el mismo nombre inicial
    fichero_salida = open(nombre_a+".dic",'w')
    json.dump(dic,fichero_salida)
    fichero_salida.close()
    pass
#Parte de prueba para el algoritmo, main del programa
fichero = open(sys.argv[1])
contenido = fichero.read()
fichero.close()
#Calculamos la probabilidad
probs = obtenerProbabilidades(contenido)
#Construimos el arbol de codificación
arbol = crearArbol(probs)
#Construimos el diccionario para codificar
dic = crearDiccionario(arbol)
#Creamos el nuevo contenido del archivo
nm = compresion(dic,contenido)
#Y por ultimo lo escribimos en un archivo
guardar(nm,dic,sys.argv[2])
print("Proceso terminado con exito")
