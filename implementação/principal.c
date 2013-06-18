#include "mensager.h"

void main(int argc, char const *argv[])
{
    Processo processo[10];
    int i = 0, num, verificador,j,auxiliar,quantElementos,a=1;

    do{
        printf("\n\nMenu\n");
        printf("0 - Criar um processo\n");
        printf("1 - Executar a primitiva SEND\n");
        printf("2 - Executar a primitiva RECEIVE\n");
        printf("3 - Executar a primitiva SENDREC\n");
        printf("4 - Executar a primitiva NOTIFY\n");
        printf("5 - Listar todos os processos existentes.\n");
        printf("10 - Sair\n\n");


        num = lerInteiro();
        quantElementos = i - 1;
        switch(num){

        case 0:
            printf("Digite o Pid do novo processo\n");
            verificador = lerInteiro();
            for (j = 0; j < i; j++)
            {
            if (processo[j].id==verificador)
                auxiliar = 1;
            }

            if (auxiliar!=1)
            {
                processo[i].id = verificador;

                auxiliar = busca_exec(processo, &quantElementos, a);
                if (auxiliar == -1)
                    processo[i].status = rand() %2;
                else
                    processo[i].status = rand() %1;
                
                printf("\nO processo %d foi criado com sucesso!\n\n",processo[i].id);
                i++;
            }
            else
                printf("\nA chave já foi atribuida a outro processo!!\n\n");

            break;

        case 1:
            printf("Informe o Pid do remetente.\n");            
            auxiliar = lerInteiro();
            auxiliar = busca(processo, &quantElementos, auxiliar);

            if (auxiliar == -1)
                printf("Processo nao existe!\n");

            else
            {
                printf("Informe o Pid do destinatário.\n");            
                j = lerInteiro();
                j = busca(processo, &quantElementos, j);

                if (auxiliar == -1)
                    printf("Processo nao existe.\n");

                else
                {
                    verificador = send(processo[auxiliar],processo[j]);
                    if (verificador == 1)
                        printf("\nMensagem enviada.\n\n");
                    else{
                        processo[j].entrada_ms = processo[auxiliar].id;
                        printf("\nMensagem em espera para envio.\n\n");
                        processo[auxiliar].status = BLOQUEADO;
                    }
                }
            }
        
        break;

        case 2:
            quantElementos = i - 1;
            printf("\nInforme o Pid do destinatário.\n");            
            auxiliar = lerInteiro();
            auxiliar = busca(processo, &quantElementos, auxiliar);

            if (auxiliar == -1)
                printf("\nProcesso nao existe.\n");
            else{
                verificador = receive(processo,processo[auxiliar],quantElementos);
                if (verificador == 1){
                    printf("Mensagem recebida.\n\n");
                    j = busca(processo, &quantElementos, processo[auxiliar].entrada_ms);
                    processo[auxiliar].entrada_ms = -2;
                    processo[j].status = PRONTO;
                }
                else{
                    printf("Não há mensagens para receber.\n\n");
                }
            }

        break;

        case 3:
            quantElementos = i - 1;
            printf("Informe o Pid do remetente.\n");            
            auxiliar = lerInteiro();
            auxiliar = busca(processo, &quantElementos, auxiliar);

            if (auxiliar == -1)
                printf("Processo nao existe!\n");

            else
            {
                printf("Informe o Pid do destinatário.\n");            
                j = lerInteiro();
                j = busca(processo, &quantElementos, j);

                if (auxiliar == -1)
                    printf("Processo nao existe.\n");

                else{
                    printf("Enviando mensagem ao processo de destino\n");
                    verificador = sendrec(processo[auxiliar],processo[j]);
                    if(verificador == 1)
                        printf("Resposta recebida pelo destinatário.\n\n");
                    else{
                        printf("Aguardando destinatário desbloquear...\n\n");
                        processo[j].status = 0;
                        verificador = sendrec(processo[auxiliar],processo[j]);
                        if(verificador == 1)
                        printf("Resposta recebida pelo destinatário.\n\n");
                    }
                }
            }

            break;

        //case 4:
            //printf("processo %d informa processo %d que está ocorrendo uma interrupção de hardware.\n\n");
        //break;

        case 5:
            for (j = 0; j < i; j++)
                printf("\nProcesso: %d status: %d.\n", processo[j].id, processo[j].status);
        break;

        case 10:
            printf("\n\nADEUS.\n\n\n");
        break;

        default:
            printf("\nOpção inválida\n\n");
        break;

    } 
} while(num != 10);
}