def merge_sort(lista):
    #Lo primero es saber si la lista es mayor a 2
    #Esto debido a que si es menor a 2 ya esta ordenada
    if len(lista) < 2:
        return lista
    else:
        middle = len(lista) // 2
        right = merge_sort(lista[:middle])
        left = merge_sort(lista[middle:])
        return merge(right,left)
def merge(lista1,lista2):
    i,j = 0,0
    result = []
    #Intercalar ordenadamente
    while(i < len(lista1) and j < len(lista2)):
        if (lista1[i] < lista2[j]):
            result.append(lista1[i])
            i += 1
        else:
            result.append(lista2[j])
            j += 1
    #Agregamos los resultados a la lista
    result += lista1[i:]
    result += lista2[j:]
    #Regresamos los resultados
    return result
