def zeroPad(numberString,zeros,left = True):
    #Funcion que regresa la cadena con zeros a la derecha o izquierda
    #Esta es una funcion auxliar que nos ayuda a poner las potencias de 10
    #a los numeros separados por karatsuba
    for i in range(zeros):
        if left:
            numberString = '0' + numberString
        else:
            numberString = numberString + '0'
    return numberString

def karatsubaMultiplication(x,y):
    #En este algoritmo nos aprovechamos de que un numero de n digitos puede escribirse de la forma
    #x = ax10^(n/2) + b   y de que karatsuba nos dice que podemos disminuir la cantidad de multiplicaciones
    #que debemos realizar.
    #Convertimos a strings las entradas para un manejo mas facil de los digitos
    x = str(x)
    y = str(y)
    #Caso base de la recursion
    if len(x) == 1 and len(y) == 1:
        return int(x) * int(y)
    if len(x) < len(y):
        x = zeroPad(x,len(y) - len(x))
    elif len(y) < len(x):
        y = zeroPad(y,len(x) - len(y))
    n = len(x)
    j = n//2
    #En caso de digitos impares
    if(n%2) != 0:
        j += 1
    BzeroPadding = n - j
    AzeroPadding = BzeroPadding * 2
    a = int(x[:j])
    b = int(x[j:])
    c = int(y[:j])
    d = int(y[j:])
    #Parte recursiva del algoritmo
    ac = karatsubaMultiplication(a,c)
    bd = karatsubaMultiplication(b,d)
    k = karatsubaMultiplication(a+b,c+d)
    A = int(zeroPad(str(ac),AzeroPadding,False))
    B = int(zeroPad(str(k-ac-bd),BzeroPadding,False))
    return A + B + bd

a = input()
b = input()
print(karatsubaMultiplication(a,b))
