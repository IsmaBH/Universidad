#El nombre del archivo a abrir debe ser pasado por linea de comandos con el siguiente comando
#ejecutable.py nombre_del_archivo
#!/usr/bin/python3.6
from PIL import Image, ImageOps
import sys

imagen = Image.open(sys.argv[1])
imagenbn = imagen.convert("L")
coloriza = ImageOps.colorize(imagenbn, "black", "cyan")
coloriza.show()
coloriza.save("blue_filter.jpg")