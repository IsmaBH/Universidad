#!/usr/bin/python3.6

import os
import sys
import platform
from datetime import datetime
    
ip = input("Ingresa la IP: ")
ipDividida = ip.split('.')
listaip = []
     
try:
   red = ipDividida[0]+'.'+ipDividida[1]+'.'+ipDividida[2]+'.'
   comienzo = int(input("Ingresa el número de comienzo de la subred: "))
   fin = int(input("Ingresa el número en el que deseas acabar el barrido: "))
except:
   print("[!] Error")
   sys.exit(1)
     
     
if (platform.system()=="Windows"):
    ping = "ping -n 1"
else :
    ping = "ping -c 1"
        
tiempoInicio = datetime.now()
print("[*] El escaneo se está realizando desde",red+str(comienzo),"hasta",red+str(fin))
for subred in range(comienzo, fin+1):
    direccion = red+str(subred)
    response = os.popen(ping+" "+direccion)
    for line in response.readlines():
        if ("ttl" in line.lower()):
            #os.system('scp /home/diego/Documentos/Operativos/Scripts/script2.py %s:/home/Descargas' % (direccion, direccion))
            listaip.append(direccion)
            print(direccion,"está activo")
            break
            
tiempoFinal = datetime.now()
tiempo = tiempoFinal - tiempoInicio
print("[*] El escaneo ha durado %s"%tiempo)
print("Las ip's guardadas son: \n")
print(listaip)