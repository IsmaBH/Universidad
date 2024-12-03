#!/usr/bin/python3
#Monitoreo de los paquetes de una interfaz y escucha de eventos de caida y levantamiento
import os
import signal
import subprocess
import time
import graficos as gp

"""
monitorea_paquetes:
"""
def monitorea_paquetes():
    proc = subprocess.Popen(["python3","monitoreo.py"], preexec_fn=os.setsid)
    return proc
"""
escucha_traps:
    funcion que cumplira la funcion de abrir un canal de escucha para recibir traps de linkup
    y linkdown para registrar las caidas o bajas de una interfaz y poder graficar el tiempo
    que estan encendidas o apagadas.
"""
def escucha_traps():
    proc = subprocess.Popen(["python3","pysnmp_trap_1.py"], preexec_fn=os.setsid)
    return proc
"""
main:
    la funcion main tendra la creacion de hilos para la ejecucion de las funciones escucha_traps
    y monitorea_paquetes.
"""
def main():
    print("Levantando los servicios de monitorea")
    time.sleep(1)
    x1 = monitorea_paquetes()
    x2 = escucha_traps()
    print("Se han levantado los servicios")
    time.sleep(1)
    condicion = True
    while condicion == True:
        opcion = input()
        if opcion == "1":
            print("Deteniendo el monitoreo de paquetes")
            os.killpg(os.getpgid(x1.pid), signal.SIGTERM)
            print("Se detuvo el monitoreo")
            time.sleep(1)
            print("Deteniendo el monitoreo de traps")
            os.killpg(os.getpgid(x2.pid), signal.SIGTERM)
            print("Se detuvo el monitoreo")
            time.sleep(1)
            print("Generando grafica de paquetes")
            tiempo, paquetes = gp.exporta_DatosPaquetes()
            t_tiempo, t_value = gp.exporta_DatosTraps('FastEthernet2_0.txt')
            uPaquetes = gp.formato_uTiempo(paquetes)
            gp.grafica_datos(tiempo, uPaquetes, "paquetes", 'monitoreo.svg')
            gp.grafica_datos(t_tiempo, t_value, "Link up/down", 'traps.svg')
        elif opcion == "2":
            print("Levantando servicios de monitoreo")
            x1 = monitorea_paquetes()
            x2 = escucha_traps()
        else:
            print("Terminando programa")
            condicion = False
            time.sleep(1)

main()
