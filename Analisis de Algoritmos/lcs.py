#Problema de la subsecuencia comun mas larga implementada en python
def lcs(s1,s2,m,n):
    #Creamos la "matriz" que nos ayudara a guardar los resultados
    L = [[0 for x in range(n+1)] for x in range(m+1)]
    #Construimos la matriz en modo bottom-up
    #Los casos siguientes nos dicen si el caracter
    #que se esta revisando en cada instante esta o no 
    #en la otra cadena y si esta coloca el valor de la lcs
    #en la matriz y si no hay resultado coloca un 0
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif s1[i-1] == s2[j-1]:
                L[i][j] = L[i-1][j-1] + 1
            else:
                L[i][j] = max(L[i-1][j],L[i][j-1])
    #Una vez llenada las matriz con el valor de la lcs nos interesa
    #reconstruirla por lo que obtendremos los indices
    index = L[m][n]
    lcs = [""]*(index+1)
    lcs[index] = ""
    i = m
    j = n
    #Con este ciclo while rellenaremos la variable lcs al recorrer
    #las secuencias dadas
    while i > 0 and j > 0:
        if s1[i-1] == s2[j-1]:
            lcs[index-1] = s1[i-1]
            i -= 1
            j -= 1
            index -= 1
        elif L[i-1][j] > L[i][j-1]:
            i -= 1
        else:
            j -= 1
    #Imprimimos las subsecuencias
    print("Secuencia 1 : " + s1 + "\nSecuencia 2 : " + s2)
    print("LCS : " + "".join(lcs))

#Parte main para prueba del algoritmo
#En el archivo adjunto lcs.txt se incluyen los valores de prueba
#propuestos en el libro de Cormen el cual es una secuencia de adn
s1 = input()
s2 = input()
m = len(s1)
n = len(s2)
lcs(s1,s2,m,n)
