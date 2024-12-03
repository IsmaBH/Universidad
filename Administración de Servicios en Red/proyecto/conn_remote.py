#!/usr/bin/python3
import paramiko, getpass, time, json, re

max_buffer = 65635

def obtenHost(hostname):
    with open('dispositivos.json','r') as f:
        hosts = json.load(f)
    return hosts[hostname]['ip']

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

def exploracion(hosts,comandos,usuario,password):
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
            with open(host+'.txt','a') as f:
                f.write(str(salida))
                f.write('\n')

def importar_datos(filename):
    regex1 = 'hostname .{1,5}'
    regex2 = 'ip address .{11,15}'
    with open(filename,'r') as f:
        for line in f.readlines():
            resultado = re.search(regex1,line)
            if resultado:
                hostname = resultado.group()
            else:
                resultado = re.search(regex2,line)
                lo = resultado.group()
    hostname = hostname.split()
    lo = lo.split()
    return hostname[1], lo[2]

def exec_one_host(host,comandos,usuario,password):
    conexion = paramiko.SSHClient()
    conexion.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    conexion.connect(host, username=usuario, password=password, look_for_keys=False, allow_agent=False)
    nueva_conexion = conexion.invoke_shell()
    salida = clear_buffer(nueva_conexion)
    time.sleep(2)
    nueva_conexion.send("terminal length 0 \n")
    salida = clear_buffer(nueva_conexion)
    for comando in comandos:
        nueva_conexion.send(comando)
        time.sleep(2)
        salida = nueva_conexion.recv(max_buffer)
    print("Se termino de configurar")
    nueva_conexion.close()
