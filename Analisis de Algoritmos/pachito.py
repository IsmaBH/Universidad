def merge_sort(lista):
    if len(lista) < 2:
        #Si la lista es vacia o de tamaño 1 ya esta ordenada, no hay que hacer nada
        return lista
    else:
        #Calculamos la mitad del arreglo y los subconjuntos derecho e izquierdo
        media = len(lista)//2
        izq = iter(merge_sort(lista[:media]))
        der = iter(merge_sort(lista[media:]))
        #Utilizamos la funcion iter para poder tener un control
        #del siguiente elemento a usar de los subconjuntos
        x1 = next(izq)
        x2 = next(der)
        lista = []
        try:
            while True:
                if x1 <= x2:
                    lista.append(x1)
                    x1 = next(izq)
                else:
                    lista.append(x2)
                    x2 = next(der)
        except:
            #Con la funcion extend() agregamos el resultado final del ordenamiento
            #a los subconjuntos a la lista original y preparamos el resultado final
            if x1 <= x2:
                lista.append(x2)
                lista.extend(der)
            else:
                lista.append(x1)
                lista.extend(izq)
        return lista

nT = [int (x) for x in input().split()]
ti = [int(y) for y in input().split()]
#Ordenamos las tareas para tener primero las mas rapidas de hacer
ordenamiento = merge_sort(ti)
#Ahora que los tenemos podemos definir un contador de tareas
tareas = 0
#Tambien necesitaremos saber las horas disponibles
hrsD = nT[1]
#Ahora recorremos la lista para saber cuantas tareas se puede hacer
for horas in ordenamiento:
    hrsD -= horas
    if hrsD <= 0:
        break
    else:
        tareas += 1
print(tareas)
