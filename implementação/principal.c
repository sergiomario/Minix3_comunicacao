#include "mensager.h"

void main(int argc, char const *argv[])
{
    Processo processo[10];
    int i = 0, num, verificador,j,auxiliar,quantElementos;

    do{
        printf("\n\nMenu\n");
        printf("0 - Criar um processo\n");
        printf("1 - Send\n");
        printf("2 - Receive\n");
        printf("3 - Sendrec\n");
        printf("4 - Notify\n");
        printf("5 - Listar processos\n");
        printf("10 - Sair\n");


        num = lerInteiro();
        switch(num){

          case 0:
          printf("Digite o id do processo\n");
          verificador = lerInteiro();
          for (j = 0; j < i; j++)
          {
            if (processo[j].id==verificador)
                auxiliar = 1;
        }

        if (auxiliar!=1)
        {
            processo[i].id = verificador;
            processo[i].status = rand() %2;
            printf("\nO processo %d criado\n\n",processo[i].id);
            i++;
        }
        else
            printf("chave atribuida a outro processo!!\n\n");

        break;

        case 1:
            quantElementos = i - 1;
            printf("Informe o id do remetente.\n");            
            auxiliar = lerInteiro();
            auxiliar = busca(processo, &quantElementos, auxiliar);
            
            if (auxiliar == -1)
                printf("Processo nao existe.\n");

        else
        {
            printf("Informe o id do destinatário.\n");            
            j = lerInteiro();
            j = busca(processo, &quantElementos, j);

            if (auxiliar == -1)
            printf("Processo nao existe.\n");

            else
            {
                verificador = send(processo[auxiliar].id,processo[j].id,processo[j].status);
                if (verificador == 1)
                    printf("Mensagem enviada.\n\n");
                else{
                    processo[j].entrada_ms = processo[auxiliar].id;
                    printf("Mensagem em espera para envio.\n\n");
                    processo[auxiliar].status = BLOQUEADO;
                    }
            }
        }
        
     break;

     case 2:
     quantElementos = i - 1;
     printf("Informe o id do destinatário.\n");            
     auxiliar = lerInteiro();
     auxiliar = busca(processo, &quantElementos, auxiliar);

     if (auxiliar == -1)
        printf("Processo nao existe.\n");
    else{
        verificador = receive(processo,processo[auxiliar],quantElementos);
            if (verificador == 1){
                printf("Mensagem recebida.\n\n");
                num = busca(processo, &quantElementos, processo[auxiliar].entrada_ms);
                processo[auxiliar].entrada_ms = -2;
                processo[num].status = PRONTO;
            }
            else{
                printf("Não há mensagens para receber.\n\n");
            }
    }

    break;

            // case 3:
            // verificador = sendrec(processo.id,processo2.id,processo2.status);
            // if(verificador == 1)
            //  printf("Resposta recebida pelo destinatário.\n\n");
            // else{
            //  printf("Aguardando destinatário desbloquear...\n\n");
            //  processo2.status = 0;
            //  verificador = sendrec(processo.id,processo2.id,processo2.status);
            //  if(verificador == 1)
            //  printf("Resposta recebida pelo destinatário.\n\n");
            // }
            // break;

            // case 4:
            // printf("processo %d informa ao processo %d que está ocorrendo uma interrupção de hardware.\n\n",processo2.id,processo.id);
            // break;

     case 5:
     for (j = 0; j < i; j++)
        printf("Processo %d status %d.\n", processo[j].id, processo[j].status);
    break;

    case 10:
    printf("Adeus.\n\n\n");
    break;

    default:
    printf("Opção inválida\n\n");
    break;

} 
}while(num != 10);
}