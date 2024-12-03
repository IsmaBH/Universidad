import pygal
import json
import time

"""
exportar_datos:
    Esta funcion leera de un archivo de texto pares de datos que devolvera en formato de listas
    nombradas como x_data, y_data.
"""
def exporta_DatosPaquetes():
    x_time = []
    packets = []
    with open('resultados.txt','r') as f:
        for line in f.readlines():
            line = eval(line)
            x_time.append(line['Tiempo'])
            packets.append(float(line['Fa2_0_In_uPackets']))
    return x_time, packets
"""
formato_uTiempo:
    Es la funcion que convertira los datos recibidos de paquetes y los convertira en un formato
    de unidad/tiempo.
"""
def formato_uTiempo(data):
    uPackets = []
    for i in range(len(data)):
        if data[i] == 0.0:
            uPackets.append(data[i])
        else:
            uData = abs(int(data[i-1]) - int(data[i]))
            uPackets.append(float(uData))
    return uPackets
"""
exporta_DatosTraps:
    Es la funcion que leera el logging generado por la escucha de las traps para recibir
    los eventos de caida o levantamiento de una interfaz el log tiene el siguiente formato:
    FECHA,PID - MESSAGE
"""
def exporta_DatosTraps(nombre):
    tiempo = []
    valores = []
    with open(nombre,'r') as f:
        for line in f.readlines():
            line = eval(line)
            tiempo.append(line['Tiempo'])
            valores.append(float(line['Evento']))
    return tiempo, valores
"""
grafica_datos:
    Funcion que grafica dos pares de datos recibidos
"""
def grafica_datos(x_data, y_data, titulo, nombre):
    grafica = pygal.Line()
    grafica.title = titulo
    grafica.x_labels = x_data
    grafica.add('data', y_data)
    grafica.render_to_file(nombre)
