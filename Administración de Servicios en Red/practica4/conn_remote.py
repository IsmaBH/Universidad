#!/usr/bin/python3
import paramiko, getpass, time, json

max_buffer = 65635

def obtener_dispositivos(filename):
    with open(filename,'r') as f:
        hosts = json.load(f)
    return hosts

def obtener_comandos(filename):
    with open(filename,'r') as f:
        comandos = [line for line in f.readlines()]
    return comandos

def clear_buffer(conexion):
    if conexion.recv_ready():
        return conexion.recv(max_buffer)

def exec_comandos(hosts,comandos,usuario,password):
    for host in hosts.keys():
        conexion = paramiko.SSHClient()
        conexion.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        conexion.connect(hosts[host]['ip'], username=usuario, password=password, look_for_keys=False, allow_agent=False)
        nueva_conexion = conexion.invoke_shell()
        salida = clear_buffer(nueva_conexion)
        time.sleep(2)
        nueva_conexion.send("terminal length 0 \n")
        salida = clear_buffer(nueva_conexion)
        for comando in comandos:
            nueva_conexion.send(comando)
            time.sleep(2)
            salida = nueva_conexion.recv(max_buffer)
        print("Se termino de configurar {}".format(host))

    nueva_conexion.close()

