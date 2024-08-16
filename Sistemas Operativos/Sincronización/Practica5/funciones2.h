#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/shm.h>

void Produce(int i, int call_flag, int msg_flag, llamadas *ptr1, mensajes *ptr2);
void Consume(int i, int call_flag, int msg_flag, llamadas *ptr1, mensajes *ptr2, condicion *parar);
void Escribe_msg(int id, char* buffer);
void Escribe_llamadas(int id, char* buffer);