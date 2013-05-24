#include "mensager.h"

void main(int argc, char const *argv[])
{
Processo processo;
Processo processo2;
int i = 0, num, verificador;
//processo.id = i;
processo.status = EXEC;
i++;
processo2.id = i;
processo2.status = N_EXEC;
    do{
    	printf("Menu\n");
    	printf("1 - Send\n");
    	printf("2 - Receive\n");
    	printf("3 - Sendrec\n");
    	printf("4 - Notify\n");
    	printf("10 - Sair\n");

    	printf("Status do processo %d: %d\n",processo.id, processo.status);
    	printf("Status do processo %d: %d\n",processo2.id, processo2.status);
    	num = lerInteiro();
    	switch(num){

    		case 1:
    		verificador = send(processo.id,processo2.id,processo2.status);
    		if (verificador == 1)
    		    printf("Mensagem enviada.\n\n");
    		else{
    			processo2.fila = processo.id;
    			printf("Mensagem em espera para envio.\n\n");
    		}
    		break;

    		case 2:
    		verificador = receive(processo.id,processo2.id,processo2.fila);
    		if (verificador == 1){
    			printf("Mensagem recebida.\n\n");
    			processo2.fila = -1;
    		}
    		else{
    			printf("Não há mensagens para receber.\n\n");
    		}
    		break;

    		case 3:
    		verificador = sendrec(processo.id,processo2.id,processo2.status);
    		if(verificador == 1)
    			printf("Resposta recebida pelo destinatário.\n\n");
    		else{
    			printf("Aguardando destinatário desbloquear...\n\n");
    			processo2.status = 0;
    			verificador = sendrec(processo.id,processo2.id,processo2.status);
    			if(verificador == 1)
    			printf("Resposta recebida pelo destinatário.\n\n");
    		}
    		break;

    		case 4:
    		printf("processo %d informa ao processo %d que está ocorrendo uma interrupção de hardware.\n\n",processo2.id,processo.id);
    		break;

    		case 10:
    		printf("Adeus.\n\n\n");
    		break;

    		default:
    		printf("Opção inválida\n\n");
            break;

    	}
    if(processo.status > processo2.status){
    	processo.status = N_EXEC;
    	processo2.status = EXEC;
    }
    else {
    	processo.status = EXEC;
    	processo2.status = N_EXEC
    }
    }while(num != 10);
}