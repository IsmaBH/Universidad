#include <stdio.h>
#include <string.h>

struct empleado;
int mostrar_menu(void);
int rellenar (struct empleado *agenda);
void mostrar_agenda(struct empleado *agenda, int numero_contactos);
int agregar_contacto (struct empleado *agenda, int numero_contactos);
int ordenar_agenda (struct empleado *agenda, int numero_contactos);
int sobreescribir_agenda (struct empleado *agenda, int numero_contactos);
int ordenar_contacto (struct empleado *agenda, int f, int i);
int eliminar_registro(struct empleado *agenda, int numero_contactos);
