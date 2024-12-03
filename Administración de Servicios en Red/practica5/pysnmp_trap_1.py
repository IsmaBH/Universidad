#Receptor python de traps snmp
from pysnmp.entity import engine, config
from pysnmp.carrier.asyncore.dgram import udp
from pysnmp.entity.rfc3413 import ntfrcv
import logging

snmpEngine = engine.SnmpEngine()

TrapAgentAddress='192.168.3.10'; #Direccion del escucha de traps
Port=162;  #Puerto

logging.basicConfig(filename='traps_recibidas.log', filemode='w', format='%(asctime)s - %(message)s', level=logging.INFO)

logging.info("El gestor esta escuchando SNMP Traps en "+TrapAgentAddress+" , Puerto : " +str(Port))
logging.info('--------------------------------------------------------------------------')

print("El gestor esta escuchando SNMP Traps en "+TrapAgentAddress+" , Puerto : " +str(Port));

config.addTransport(
    snmpEngine,
    udp.domainName + (1,),
    udp.UdpTransport().openServerMode((TrapAgentAddress, Port))
)

#Configuracion de comunidad V1 y V2c
config.addV1System(snmpEngine, 'todo', 'privada')

#Configuracion de usuario V3
#config.addV3User(
#	snmpEngine, 'usr-sha-aes128',
#	config.usmHMACSHAAuthProtocol, 'authkey1',
#	config.usmAesCfb128Protocol, 'privkey1'
#)

def cbFun(snmpEngine, stateReference, contextEngineId, contextName,
          varBinds, cbCtx):
    print("Mensaje nuevo de traps recibido");
    logging.info("Mensaje nuevo de traps recibido")
    for name, val in varBinds:   
        logging.info('%s = %s' % (name.prettyPrint(), val.prettyPrint()))
        if str(name) == "1.3.6.1.2.1.1.3.0":
            tiempo = str(val)
        if str(name) == "1.3.6.1.2.1.2.2.1.2.4":
            aux = str(val)
            nombre = aux.replace('/','_')+'.txt'
        if str(name) == "1.3.6.1.4.1.9.2.2.1.1.20.4":
            if str(val) == "administratively down":
                evento = 0
            else:
                evento = 1
        print('%s = %s' % (name.prettyPrint(), val.prettyPrint()))
    resultado = {}
    resultado['Tiempo'] = tiempo
    resultado['Evento'] = evento
    with open(nombre,'a') as f:
        f.write(str(resultado))
        f.write('\n')

    logging.info("==== Fin del mensaje de la trampa ====")
ntfrcv.NotificationReceiver(snmpEngine, cbFun)

snmpEngine.transportDispatcher.jobStarted(1)  

try:
    snmpEngine.transportDispatcher.runDispatcher()
except:
    snmpEngine.transportDispatcher.closeDispatcher()
    raise
