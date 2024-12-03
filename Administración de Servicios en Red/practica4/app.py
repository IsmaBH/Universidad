from flask import Flask, url_for, jsonify, request
from flask_sqlalchemy import SQLAlchemy
import conn_remote as cnr
import Usuario as Usuario

#se crea la extension
bd = SQLAlchemy()
#Se crea la app de flask
app = Flask(__name__)
#Se configura SQLite, relativa al folder de la instancia de app
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///pruebas.db'
#Se inicializa la app con la extension
bd.init_app(app)

class ValidationError(ValueError):
    pass

class Usuario(bd.Model):
    __tablename__ = 'Usuarios'
    id = bd.Column(bd.Integer, primary_key=True)
    user_type = bd.Column(bd.String(24), unique=False)
    user_pswd = bd.Column(bd.String(64), unique=False)
    user_lvl = bd.Column(bd.String(64), unique=False)

    def __init__(self, username, perm_lvl, pswd):
        self.user_type = username
        self.user_pswd = pswd
        self.user_lvl = perm_lvl

    def dame_url(disp):
        return url_for('dame_usuario', id=disp.id, _external=True)

    def exporta_datos(disp):
        return {
                'user_type': disp.user_type,
                'user_pswd': disp.user_pswd,
                'user_lvl': disp.user_lvl
        }

    def importa_datos(disp, datos):
        try:
            disp.user_type = datos['user_type']
            disp.user_pswd = datos['user_pswd']
            disp.user_lvl = datos['user_lvl']
        except KeyError as e:
            raise ValidationError('Invalid usuario: missing ' + e.args[0])
        return disp
@app.route('/dispositivos/<int:id>', methods=['GET'])
def dame_usuario(id):
    return jsonify(Usuario.query.get_or_404(id).exporta_datos())
###################################################################################
#  ENDPOINT DEL CRUD de usuarios
###################################################################################
"""
ENDPOINT /usuarios/... :
    EN este endpoint se juntaran todas las funciones del CRUD solo cambiaran los datos
    que se envian y los metodos que se utilizan (GET, POST, PUT, DELETE)
"""
@app.route("/usuarios/", defaults={'username': 'None', 'permit_lvl': 'None', 'password': 'None', 'field': 'None', 'data': 'None'}, methods = ["GET"])
@app.route("/usuarios/<username>/<permit_lvl>/<password>/", defaults={'field': 'None', 'data': 'None'}, methods=["POST"])
@app.route("/usuarios/<username>/<field>/<data>/", defaults={'permit_lvl': 'none', 'password': 'None'}, methods=["PUT"])
@app.route("/usuarios/<username>/", defaults={'permit_lvl': 'None', 'password': 'None', 'field': 'None', 'data': 'None'}, methods=["DELETE"])
def CRUD_USUARIOS(username, permit_lvl, password, field, data):
    if request.method == "GET":
        return jsonify({'Usuarios': [usuario.dame_url() for usuario in Usuario.query.all()]})
    elif request.method == "POST":
        comandos = []
        if username != "cisco":
            usuario = Usuario(username, str(permit_lvl), password)
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
            return "No se puede agregar un segundo usuario admin\n"
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


###################################################################################
if __name__ == '__main__':
    #Aqui se crea el contexto de la base de datos
    with app.app_context():
        bd.create_all()
    #Por ultimo corremos la app
    app.run(host='0.0.0.0', debug=True)
