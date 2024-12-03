##Soy el archivo de monitoreo
from pysnmp.entity import engine, config
from pysnmp.carrier.asyncore.dgram import udp
from pysnmp.entity.rfc3413 import ntfrcv
from pysnmp.entity.rfc3413.oneliner import cmdgen
import datetime
import json
import time
import sys

cmdGen = cmdgen.CommandGenerator()

"""
snmp_query:
    Fncion que permite enviar una solicitud snmp y recibir una respuesta
"""
def snmp_query(host, community, oid):
    errorIndication, errorStatus, errorIndex, varBinds = cmdGen.getCmd(
        cmdgen.CommunityData(community),
        cmdgen.UdpTransportTarget((host, 161)),
        oid
    )

    #Revisamos errores e imprimimos
    if errorIndication:
        print(errorIndication)
    else:
        if errorStatus:
            print('%s at %s' % (
                errorStatus.prettyPrint(),
                errorIndex and varBinds[int(errorIndex)-1] or '?'
                )
            )
        else:
            for name, val in varBinds:
                return(str(val))


"""
monitoreo_paquetes:
    el monitoreo de paquetes se hara en un intervalo de 20 segundos solo de los paquetes de entrada
    para este ejemplo se guardaran los resultados en un archivo de texto "resultados.txt" del cual
    se leera para posteriormente generar una grafica de paquetes por cada 20 segundos.
"""
def monitoreo_Paquetes(hostname, intervalo, interfaz, iname):
    host = hostname
    community = 'privada'
    #Hostname OID
    system_name = '1.3.6.1.2.1.1.5.0'
    #Se monitoreara la interfaz FastEthernet 2/0, los paquetes de entrada
    fa_in_uPackets = interfaz
    #Hacemos un ciclo infinito que cheque los paquetes cada 20 segundos
    while True:
        resultado = {}
        tiempo = datetime.datetime.now()
        nombre = snmp_query(host, community, system_name)
        resultado['Tiempo'] = tiempo.strftime("%H:%M:%S")
        resultado['Fa_In_uPackets'] = snmp_query(host, community, fa_in_uPackets)
        fname = nombre+iname+".txt"
        #Guardamos los resultados en un archivo de texto
        with open(fname,'a') as f:
            f.write(str(resultado))
            f.write('\n')
        time.sleep(int(intervalo))
    #Este ciclo se terminara hasta que el programa main lo interrumpa

hostname, interfaz, intervalo, iname = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
#print(type(hostname), type(interfaz), type(intervalo))
monitoreo_Paquetes(hostname, intervalo, interfaz, iname)
