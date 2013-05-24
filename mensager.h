#include <stdio.h>

#ifndef MENSAGER_H

#define MENSAGER_H

#define EXEC 1;
#define N_EXEC 0;

typedef struct Processo
{
	int id;
	int status;
	int fila;
}Processo;




int send(int ,int, int);

int receive(int ,int, int);

int sendrec(int ,int, int);

int notify(int ,int );

int lerInteiro();

#endif