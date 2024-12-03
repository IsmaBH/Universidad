#!/usr/bin/python3
from flask import Flask, url_for, jsonify, request
from flask_sqlalchemy import SQLAlchemy
import conn_remote as cnr
import os
import signal
import subprocess
import time
import graficos as gp

#Se crea la extension
bd = SQLAlchemy()
#Se crea la app de Flask
app = Flask(__name__)
#Se configura SQLite, relativa al folder de la instancia de app
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///pruebas.db'
#Se inicializa la extension
bd.init_app(app)

class ValidationError(ValueError):
    pass

#Clase de la tabla principal de dispositivos
class Dispositivo(bd.Model):
    id = bd.Column(bd.Integer, primary_key=True)
    hostname = bd.Column (bd.String (24), nullable = False, unique = False)
    loopback = bd.Column (bd.String (24), nullable = True, unique = False)
    admin_ip = bd.Column (bd.String (24), nullable = True, unique = False)
    rol = bd.Column (bd.String (64), nullable = True, unique = False)
    empresa = bd.Column (bd.String (24), nullable = True, unique = False)
    so = bd.Column (bd.String (24), nullable = True, unique = False)
    interfaces = bd.relationship ('Interfaz', backref = 'dispositivos', lazy = True)
    usuarios = bd.relationship ('Usuario', backref = 'dispositivos', lazy = True)

    #Conjunto de metodos set para el objeto dispositivo
    def setLoopback(self, lo):
        self.loopback = lo
    def setIpAdministrativa(self, ip):
        self.admin_ip = ip
    def setRol(self, r):
        self.rol = r
    def setEmpresa(self, e):
        self.empresa = e
    def setDispOS(self, o):
        self.so = o
    
    #Conjunto de metodos para el manejo de la informacion
    def dame_url(disp):
        return url_for('dame_dispositivo', id=disp.id, _external=True)
    def exporta_datos(disp):
        return {
                'disp_url':disp.dame_url(),
                'hostname':disp.hostname,
                'loopback':disp.loopback,
                'admin_ip':disp.admin_ip,
                'rol':disp.rol,
                'empresa':disp.empresa,
                'so':disp.so,
                'interfaces':disp.interfaces[0].exporta_datos(),
                'usuarios':disp.usuarios[0].exporta_datos()
        }
    def importa_datos(disp, datos):
        try:
            disp.hostname = datos['hostname']
            disp.loopback = datos['loopback']
            disp.admin_ip = datos['admin_ip']
            disp.rol = datos['rol']
            disp.empresa = datos['empresa']
            disp.so = datos['so']
            disp.interfaces = datos['interfaces']
            disp.usuarios = datos['usuarios']
        except KeyError as e:
            raise ValidationError('Invalid dispositivo: missing ' + e.args[0])
        return disp
#Clase de la tabla interfaces que sera la que guarde las interfaces de los dispositivos
#Y guarde su estado, solo podra ser activo o inactivo
class Interfaz(bd.Model):
    id = bd.Column (bd.Integer, primary_key = True)
    dispositivo_id = bd.Column (bd.Integer, bd.ForeignKey ('dispositivo.id'), nullable = False)
    tipo = bd.Column (bd.String (24), nullable = False, unique = False)
    numero = bd.Column (bd.String (24), nullable = True, unique = False)
    ip = bd.Column (bd.String (24), nullable = True, unique = False)
    netmask = bd.Column(bd.String(24), nullable = True, unique = False)
    estado = bd.Column(bd.String(24), nullable = True, unique = False)

    #Conjunto de metodos para el manejo de la informacion
    def dame_url(disp):
        return url_for('dame_interfaces', id=disp.id, _external=True)
    def exporta_datos(disp):
        return {
                'disp_url':disp.dame_url(),
                'dispositivo_id':disp.dispositivo_id,
                'tipo':disp.tipo,
                'numero':disp.numero,
                'ip':disp.ip,
                'netmask':disp.netmask,
                'estado':disp.estado
        }
    def importa_datos(disp, datos):
        try:
            disp.dispositivo_id = datos['dispositivo_id']
            disp.tipo = datos['tipo']
            disp.numero = datos['numero']
            disp.ip = datos['ip']
            disp.netmask = datos['netmask']
            disp.estado = datos['estado']
        except KeyError as e:
            raise ValidationError('Invalid interfaz: missing ' + e.args[0])
        return disp
#Clase de la tabla usuarios que sera la que guarde los usuarios de cada dispositivo
class Usuario(bd.Model):
    id = bd.Column (bd.Integer, primary_key = True)
    dispositivo_id = bd.Column (bd.Integer, bd.ForeignKey ('dispositivo.id'), nullable = False)
    user_type = bd.Column (bd.String (24), unique = False)
    user_pswd = bd.Column (bd.String (64), unique = False)
    user_lvl = bd.Column (bd.String (24), unique = False)

    def __init__(self, username, perm_lvl, pswd):
        self.user_type = username
        self.user_pswd = pswd
        self.user_lvl = perm_lvl
    def dame_url(disp):
        return url_for ('dame_usuarios', id = disp.id, _external = True)
    def exporta_datos(disp):
        return{
                'dispositivo_id':disp.dispositivo_id,
                'user_type':disp.user_type,
                'user_pswd':disp.user_pswd,
                'user_lvl':disp.user_lvl
        }
    def importa_datos(disp,datos):
        try:
            disp.dispositivo_id = datos['dispositivo_id']
            disp.user_type = datos['user_type']
            disp.user_pswd = datos['user_pswd']
            disp.user_lvl = datos['user_lvl']
        except KeyError as e:
            raise ValidationError('Invalid usuario: missing ' + e.args[0])
        return disp
###########################################################################################
@app.route('/dispositivos/<int:id>', methods=['GET'])
def dame_dispositivo(id):
    return jsonify(Dispositivo.query.get_or_404(id).exporta_datos())
@app.route('/interfaces/<int:id>', methods=['GET'])
def dame_interfaces(id):
    return jsonify(Interfaz.query.get_or_404(id).exporta_datos())
@app.route('/usuarios/<int:id>', methods=['GET'])
def dame_usuarios(id):
    return jsonify(Usuario.query.get_or_404(id).exporta_datos())
###########################################################################################
#           Funciones utilitarias
###########################################################################################
def translate_OID(interfaz):
    oid_base = "1.3.6.1.2.1.2.2.1.11."
    if interfaz == "0-0":
        oid = oid_base+"1"
    elif interfaz == "1-0":
        oid = oid_base+"2"
    elif interfaz == "1-1":
        oid = oid_base+"3"
    elif interfaz == "2-0":
        oid = oid_base+"4"
    elif interfaz == "2-1":
        oid = oid_base+"5"
    elif interfaz == "3-0":
        oid = oid_base+"6"
    elif interfaz == "3-1":
        oid = oid_base+"7"
    else:
        oid = oid_base+"1"
    return oid

def monitorea_paquetes(hostname, interfaz, tiempo, iname):
    proc = subprocess.Popen(["python3","monitoreo.py",hostname,interfaz,tiempo,iname], preexec_fn=os.setsid)
    return proc
###########################################################################################
###########################################################################################
#           ENDPOINT DEL CRUD de /usuarios
###########################################################################################
@app.route('/usuarios/', defaults={'username':'None', 'permit_lvl':'None', 'password':'None', 'field':'None', 'data':'None'}, methods = ["GET"])
@app.route("/usuarios/<username>/<permit_lvl>/<password>/", defaults={'field': 'None', 'data': 'None'}, methods=["POST"])
@app.route("/usuarios/<username>/<field>/<data>/", defaults={'permit_lvl': 'none', 'password': 'None'}, methods=["PUT"])
@app.route("/usuarios/<username>/", defaults={'permit_lvl': 'None', 'password': 'None', 'field': 'None', 'data': 'None'}, methods=["DELETE"])
def CRUD_USUARIOS(username, permit_lvl, password, field, data):
    if request.method == "GET":
        return jsonify({'Usuarios': [usuario.dame_url() for usuario in Usuario.query.all()]})
    elif request.method == "POST":
        comandos = []
        if username != "cisco": #Esta linea se cambia cisco por admin para restringir que solo sea 1
            usuario = Usuario(username, str(permit_lvl), password)
            #listaUsuarios = Usuario.query.all()
            #listaUsuarios.append(usuario)
            bd.session.add(usuario)
            bd.session.commit()
            """
            hosts = cnr.obtener_dispositivos('dispositivos.json')
            comando = "username "+username+" privilege "+permit_lvl+" secret "+password+"\n"
            comandos.append("configure terminal\n")
            comandos.append(comando)
            comandos.append("end\n")
            cnr.exec_comandos(hosts,comandos,"admin","cisco")
            """
            return jsonify({'Location': usuario.dame_url()}), 201
        else:
            return "No se puede agregar un segundo usuario admin"
    elif request.method == "PUT":
        usuario = bd.session.execute(bd.select(Usuario).filter_by(user_type=username)).scalar_one()
        if field == "password":
            usuario.user_pswd = data
        elif field == "user_lvl":
            usuario.user_lvl = data
        else:
            usuario.user_type = data
        bd.session.commit()
        """
        comandos = []
        hosts = cnr.obtener_dispositivos('dispositivos.json')
        comando1 = "no username "+username+"\n"
        comando2 = "username "+usuario.user_type+" privilege "+usuario.user_lvl+" secret "+usuario.user_pswd+"\n"
        comandos.append("configure terminal\n")
        comandos.append(comando1)
        comandos.append(comando2)
        comandos.append("end\n")
        cnr.exec_comandos(hosts,comandos,"admin","cisco")
        """
        return jsonify({'Location': usuario.dame_url()}), 201
    elif request.method == "DELETE":
        usuario = bd.session.execute(bd.select(Usuario).filter_by(user_type=username)).scalar_one()
        bd.session.delete(usuario)
        bd.session.commit()
        """
        comandos = []
        hosts = cnr.obtener_dispositivos('dispositivos.json')
        comando = "no username "+username+"\n"
        comandos.append("configure terminal\n")
        comandos.append(comando)
        comandos.append("end\n")
        cnr.exec_comandos(hosts,comandos,"admin","cisco")
        """
        return "Se elimino al usuario {} de todos los routers\n".format(username)
###########################################################################################
#           FIN DEL CRUD DE /usuarios
###########################################################################################
###########################################################################################
#           ENDPOINT /routes
###########################################################################################
@app.route("/routes", methods=["GET"])
def obtenerDispositivos():
    comandos = cnr.obtener_comandos('comandos.txt')
    hosts = cnr.obtener_dispositivos('dispositivos.json')
    cnr.exploracion(hosts,comandos,"admin","cisco")
    for host in hosts.keys():
        hostname, lo = cnr.importar_datos(host+'.txt')
        dispositivo = Dispositivo(hostname=hostname)
        dispositivo.setLoopback(lo)
        usuario = Usuario("admin","15","cisco")
        interfaz = Interfaz(tipo="FastEthernet",numero="1/0")
        interfaz2 = Interfaz(tipo="FastEthernet",numero="2/0")
        dispositivo.usuarios.append(usuario)
        dispositivo.interfaces.append(interfaz)
        dispositivo.interfaces.append(interfaz2)
        bd.session.add(dispositivo)
        bd.session.add(usuario)
        bd.session.add(interfaz)
        bd.session.add(interfaz2)
        bd.session.commit()
    return jsonify({'Dispositivos': [dispositivo.dame_url() for dispositivo in Dispositivo.query.all()]})
###########################################################################################
#           FIN DEL ENDPOINT /routes
###########################################################################################
###########################################################################################
#           ENDPOINT /routers/<hostname>/
###########################################################################################
@app.route("/routers/<hostname>/", methods=["GET"])
def obtenerInfoHost(hostname):
    dispositivo = bd.session.execute(bd.select(Dispositivo).filter_by(hostname=hostname)).scalar_one()
    return dispositivo.exporta_datos()
###########################################################################################
#           FIN DEL ENDPOINT /routers/<hostname>/
###########################################################################################
###########################################################################################
#           ENDPOINT /routers/<hostname>/interfaces
###########################################################################################
@app.route("/routers/<hostname>/interfaces", methods=["GET"])
def obtenerInfoInterfaz(hostname):
    dispositivo = bd.session.execute(bd.select(Dispositivo).filter_by(hostname=hostname)).scalar_one()
    return jsonify({'Interfaces': [interfaz.dame_url() for interfaz in dispositivo.interfaces]})
###########################################################################################
#           FIN DEL ENDPOINT /routers/<hostname>/interfaces
###########################################################################################
###########################################################################################
#           ENDPOINT DEL CRUD DE /routers/<hostname>/usuarios/<username>/<perm_lvl>/<pswd>/<field>/<data>
###########################################################################################
@app.route("/routers/<hostname>/usuarios/", defaults={'username':'None','perm_lvl':'None','pswd':'None','field':'None','data':'None'}, methods = ["GET"])
@app.route("/routers/<hostname>/usuarios/<username>/<perm_lvl>/<pswd>/", defaults={'field':'None','data':'None'}, methods = ["POST"])
@app.route("/routers/<hostname>/usuarios/<username>/<field>/<data>/", defaults={'perm_lvl':'None','pswd':'None'}, methods = ["PUT"])
@app.route("/routers/<hostname>/usuarios/<username>/", defaults={'perm_lvl':'None','pswd':'None','field':'None','data':'None'}, methods = ["DELETE"])
def CRUD_ROUTERS(hostname,username, perm_lvl, pswd, field, data):
    if request.method == "GET":
        dispositivo = bd.session.execute(bd.select(Dispositivo).filter_by(hostname=hostname)).scalar_one()
        return jsonify({'Usuarios': [usuario.dame_url() for usuario in dispositivo.usuarios]})
    elif request.method == "POST":
        dispositivo = bd.session.execute(bd.select(Dispositivo).filter_by(hostname=hostname)).scalar_one()
        usuario = Usuario(username,perm_lvl,pswd)
        info = usuario.exporta_datos()
        dispositivo.usuarios.append(usuario)
        bd.session.add(usuario)
        bd.session.commit()
        
        comandos = []
        host = cnr.obtenHost(hostname)
        comando = "username "+username+" privilege "+perm_lvl+" secret "+pswd+"\n"
        comandos.append("configure terminal\n")
        comandos.append(comando)
        comandos.append("end\n")
        cnr.exec_one_host(host,comandos,"admin","cisco")
        
        return info
    elif request.method == "PUT":
        dispositivo = bd.session.execute(bd.select(Dispositivo).filter_by(hostname=hostname)).scalar_one()
        if username == "admin":
            usuario = dispositivo.usuarios[0]
        else:
            usuario = dispositivo.usuarios[1]
        if field == "password":
            usuario.user_pswd = data
        elif field == "user_lvl":
            usuario.user_lvl = data
        else:
            usuario.user_type = data
        info = usuario.exporta_datos()
        bd.session.commit()
        
        comandos = []
        host = cnr.obtenHost(hostname)
        comando1 = "no username "+username+"\n"
        comando2 = "username "+usuario.user_type+" privilege "+usuario.user_lvl+" secret "+usuario.user_pswd+"\n"
        comandos.append("configure terminal\n")
        comandos.append(comando1)
        comandos.append(comando2)
        comandos.append("end\n")
        cnr.exec_one_host(host,comandos,"admin","cisco")
        
        return info
    elif request.method == "DELETE":
        dispositivo = bd.session.execute(bd.select(Dispositivo).filter_by(hostname=hostname)).scalar_one()
        usuario = dispositivo.usuarios[1]
        bd.session.delete(usuario)
        bd.session.commit()
        
        comandos = []
        host = cnr.obtenHost(hostname)
        comando = "no username "+username+"\n"
        comandos.append("configure terminal\n")
        comandos.append(comando)
        comandos.append("end\n")
        cnr.exec_one_host(host,comandos,"admin","cisco")
        
        return "Se elimino al usuario"
###########################################################################################
#           FIN DEL CRUD DE /routers
###########################################################################################
###########################################################################################
#           ENDPOINT /routers/<hostname>/interfaces/<interfaz>/octetos/<tiempo>
###########################################################################################
"""
ENDPOINT /monitoreo...:
    Este endpoint activara el monitoreo y modificara parametros de este, activando o
    desactivando el monitoreo de paquetes.
"""
@app.route("/routers/<hostname>/interfaces/<interfaz>/octetos/", defaults={'hostname':'None','interfaz':'None','tiempo':'None'}, methods = ["GET"])
@app.route("/routers/<hostname>/interfaces/<interfaz>/octetos/<tiempo>", methods = ["POST"])
@app.route("/routers/<hostname>/interfaces/<interfaz>/octetos/", defaults={'tiempo':'None'}, methods = ["DELETE"])
def monitor_parte_dos(hostname, interfaz, tiempo):
    if request.method == "GET":
        with open('resultados.txt','r') as f:
            for line in f.readlines():
                print(eval(line))
        return "Ya son todos los paquetes"
    elif request.method == "POST":
        interfaz_oid = translate_OID(interfaz)
        procx = monitorea_paquetes(hostname, interfaz_oid, tiempo, interfaz)
        tupla = (hostname, interfaz, procx)
        procesos.append(tupla)
        return "Se inicio el muestreo\n"
    elif request.method == "DELETE":
        for elemento in procesos:
            if elemento[0] == hostname and elemento[1] == interfaz:
                os.killpg(os.getpgid(elemento[2].pid), signal.SIGTERM)
                procesos.pop(procesos.index(elemento))
                break
            else:
                return "No existe el proceso seleccionado\n"
        return "Se detuvo el muestreo\n"
    else:
        print("Metodo no soportado\n")
###########################################################################################
#           FIN DEL ENDPOINT
###########################################################################################
###########################################################################################
#           ENDPOINT /routers/<hostname>/interfaces/<interfaz>/grafica
###########################################################################################
"""
ENDPOINT /graficos....:
    Este endpoint graficara los resultados del monitoreo de una interfaz seleccionada
"""
@app.route("/routers/<hostname>/interfaces/<interfaz>/grafica", methods = ["GET"])
def grafica_paquetes(hostname, interfaz):
    fname = hostname+interfaz+".txt"
    tiempo, paquetes = gp.exporta_DatosPaquetes(fname)
    uPaquetes = gp.formato_uTiempo(paquetes)
    gp.grafica_datos(tiempo, uPaquetes, "paquetes", "monitoreo.svg")
    return "Se genero la grafica con el nombre de monitoreo.svg\n"
###########################################################################################
#           FIN DEL ENDPOINT
###########################################################################################
if __name__ == '__main__':
    with app.app_context():
        bd.create_all()
    #Por ultimo corremos la app
    procesos = []
    app.run(host='0.0.0.0', debug=True)
