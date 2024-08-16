#Implementacion con DP del problema de multiplicacion de cadena de matrices
#Es la implementacion del algoritmo expuesto en el libro del Cormen
#Se asume que el usuario u otro funcion auxiliar verifica que los tamaños de
#las matrices sean correctos para la multiplicacion, esta funcion solo se centra
#en implementar el algoritmo
def MatrixChainOrder(p):
    #Calculamos la longitud
    n = len(p) - 1
    #Por simplicidad se añade una columna y una fila extra
    #A la variable dp, estas no son usadas
    dp = [[0 for i in range(n)] for j in range(n)]
    s = [[0 for i in range(n)] for j in range(n)]
    #dp[i,j] = Numero escalar minimo de multiplicaciones
    #necesarias para calcular la matriz A[i]A[i+1]...A[j]
    #donde la dimension de A[i] es p[i-1]xp[i]
    
    #El costo de multiplicar una sola matriz(Caso base)
    for i in range(0, n):
        dp[i][i] = 0
    #Caso recursivo
    #l es la longitud de la cadena
    for l in range(2,n+1):
        for i in range(0, n-l+1):
            j = i + l - 1
            if i < j:
                q = [dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1] for k in range(i,j)]
                #Se obtiene el minimo de los costos e indice
                (s[i][j], dp[i][j]) = min(enumerate(q), key=lambda x: x[1])
                #Se corrige la s debido a la funcion enumerate
                s[i][j] = s[i][j] + i + 1

    return dp,s
#Funcion auxiliar que permite mostrar el resultado obtenido en pantalla
def parentesisOptimos(s,i,j):
    if i == j:
        print("A%d" % (i+1),end='')
    else:
        print("(",end='')
        parentesisOptimos(s,i,s[i][j]-1)
        parentesisOptimos(s, s[i][j],j)
        print(")",end='')
#Parte para probar el funcionamiento del algoritmo
arr = [int(x) for x in input().split()]
dp,s = MatrixChainOrder(arr)
print("Numero minimo de multiplicaciones: " + str(dp[0][len(dp[0])-1]))
j = len(s[0]) - 1
parentesisOptimos(s,0,j)
print('')
