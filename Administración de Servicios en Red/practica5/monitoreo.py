#Soy el archivo de monitoreo
from pysnmp.entity import engine, config
from pysnmp.carrier.asyncore.dgram import udp
from pysnmp.entity.rfc3413 import ntfrcv
from pysnmp.entity.rfc3413.oneliner import cmdgen
import datetime
import json
import time

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
def monitoreo_Paquetes():
    host = '192.168.3.1'
    community = 'privada'
    #Hostname OID
    system_name = '1.3.6.1.2.1.1.5.0'
    #Se monitoreara la interfaz FastEthernet 2/0, los paquetes de entrada
    fa2_0_in_uPackets = '1.3.6.1.2.1.2.2.1.11.4'
    #Hacemos un ciclo infinito que cheque los paquetes cada 20 segundos
    while True:
        resultado = {}
        tiempo = datetime.datetime.now()
        resultado['Tiempo'] = tiempo.strftime("%H:%M:%S")
        resultado['Fa2_0_In_uPackets'] = snmp_query(host, community, fa2_0_in_uPackets)
        #Guardamos los resultados en un archivo de texto
        with open('resultados.txt','a') as f:
            f.write(str(resultado))
            f.write('\n')
        time.sleep(20)
    #Este ciclo se terminara hasta que el programa main lo interrumpa

monitoreo_Paquetes()
