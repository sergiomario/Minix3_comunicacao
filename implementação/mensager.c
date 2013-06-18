#include "mensager.h"

int send(Processo p1, Processo p2){

    if (p2.status == 0)
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

int sendrec(Processo p1, Processo p2){
    if(p2.status == 0)
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

int busca (Processo *prt, int *quant, int elemento){
    int i;
    Processo *PCO = prt;
    for(i=0; i<=*quant; i++){
        if(PCO[i].id == elemento)
            return i;
    }
            return -1;
}

int busca_exec (Processo *prt, int *quant, int elemento){
    int i;
    Processo *PCO = prt;
    for(i=0; i<=*quant; i++){
        if(PCO[i].status == elemento)
            return i;
    }
            return -1;
}      