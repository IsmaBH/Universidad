#!/usr/bin/python3.6

import os, sys
import subprocess

comando1 = "find /home/ -name *.jpg"
paths1 = []
ins = "cp "
pathd = " /tmp/jpg"
salida = os.popen(comando1).read()
#Este for separa los saltos de linea obtenidos en salida y los concatena con otras partes
#para despues guardar los comandos completos en una listas (copiado de imagenes jpg)
for i in salida:
	if i[-1:] != "\n":
		ins = ins+i[-1:]
	if i[-1:] == "\n":
		ins = ins+pathd
		paths.append(ins)
		ins = "cp "
#Este for recorre la lista de comandos y los ejecuta
for i in range(len(paths1)):
	command = paths1[i]
	os.popen(command)