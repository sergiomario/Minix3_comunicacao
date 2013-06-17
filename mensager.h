#include <stdio.h>
#include <stdlib.h>

#ifndef MENSAGER_H

#define MENSAGER_H

#define EXEC 1;
#define PRONTO 0;
#define BLOQUEADO -1;

typedef struct Processo
{
	int id;
	int status;
	int entrada_ms;
}Processo;




int send(int ,int, int);

int receive(Processo *, Processo , int);

int sendrec(int ,int, int);

int notify(int ,int );

int lerInteiro();

#endif