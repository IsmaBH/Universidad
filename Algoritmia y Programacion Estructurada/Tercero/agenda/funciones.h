#include <stdio.h>
#include <string.h>

struct contacto;
int mostrar_menu(void);
int rellenar (struct contacto *agenda);
void mostrar_agenda(struct contacto *agenda, int numero_contactos);
void agregar_contacto (void);
int nuevo_contacto (void);
int comparar_caracter (char caracter1, char caracter2);
int ordenar_agenda (struct contacto *agenda, int numero_contactos);
int sobreescribir_agenda (struct contacto *agenda, int numero_contactos);
int comparar_cadena (struct contacto *agenda, int numero_contactos, int opcion1, int opcion2);
int ordenar_contacto (struct contacto *agenda, int resultado, int f, int i, int opcion2);