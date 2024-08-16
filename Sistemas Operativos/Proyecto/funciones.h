#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "TADListaD.h"
#include "matrices.h"

int process;
int swap;
unsigned char **Dir_RAM;
unsigned char **Dir_SWAP;
char str1[80], str2[80], str3[80], str4[80];

void analiza(int opt, int fd2, char *myfifo1);
int administra(char *str1, int fd1, char * myfifo1, lista *L, int ram);