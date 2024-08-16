#Implementacion del algoritmo de la mochila entera (knapsack 0/1)
#Se uso como referencia el paper "Dynamic Programming Solution to the discrete
#knapsack problem" escrito por Cheng Li, Virgil Pavlu, Javed Aslam, tambien se
#uso el analisis hecho en clase para la lectura de este paper.
def mochila(W,wt,val,n):
    K = [[0 for x in range(W+1)] for x in range(n+1)]
    #Construimos la tabla K en modo bottom up
    for i in range(n+1):
        for w in range(W+1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
    #Regresamos la tabla K entera debido a que se usara posteriormente
    return K
#La funcion eleccion() es una funcion auxiliar para reconstruir la
#seleccion usada para el resultado K[n][W]
def eleccion(c,w,n,W):
    while n > 0 and W > 0:
        if c[n][W] > c[n-1][W]:
            print(str(n)+" ",end='')
            W = W - w[n-1]
        n -= 1
#Codigo main para las pruebas del algoritmo
val = [60,100,120]
wt = [10,20,30]
W = 50
n = len(val)
k = mochila(W,wt,val,n)
print("Valor obtenido: " + str(k[n][W]))
print("Objetos seleccionados: ",end='')
eleccion(k,wt,n,W)
print("")
