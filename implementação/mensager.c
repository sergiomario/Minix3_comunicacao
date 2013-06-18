#include "mensager.h"

int send(int origem,int destino, int status_d){
Processo processo;
Processo processo2;
processo.id = origem;
processo2.id = destino;
processo2.status = status_d;
    if (processo2.status == 0)
        return 1;
    else
        return 0;
}

int receive(Processo *p, Processo dest, int quant){
    int aux;
    aux = busca(p, &quant, dest.entrada_ms);
    if (p[aux].id == dest.entrada_ms)
        return 1;
    else
        return 0;

}

int sendrec(int origem,int destino, int status_d){
Processo processo;
Processo processo2;
processo.id = origem;
processo2.id = destino; 
processo2.status = status_d; 
    printf("Enviando mensagem ao processo de destino\n");
    if(processo2.status == 0)
        return 1;
    else
        return 0;
}

int notify(int origem,int destino){

}


int lerInteiro(){
    char num[10];
    gets(num);
    return atoi(num);
}

int busca (int *prt, int *quant, int elemento){
    int i;
    Processo *PCO = prt;
    for(i=0; i<=*quant; i++){
          if(PCO[i].id == elemento)
          return i;
          }
          return -1;
    }    