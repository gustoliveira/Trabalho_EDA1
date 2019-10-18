#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"

int main(){
    lista *l = create_l();

    long long int cpf;                  //Criou variáveis para ler valores
    scanf("%lld", &cpf);


    // Imprime os valores no topo da pilha, como os nós foram apenas criados mas não
    // foi feito push, dará falha de segmentação, afinal, os nós não foram ligados
    // a pilha ainda
    // //printf("%d %d %d %c \n",p->topo->cpf,p->topo->cpft,p->topo->valor,p->topo->op);


    // printf("Vazia: %d \n",isEmpty_l(l));  //Verifica se a pilha está vazia

    //Um ponteiro para cada cliente receber o retorno da função create_n
    nol *cliente0 = create_nol(cpf);
    nol *cliente1 = create_nol(cpf+1);
    nol *cliente2 = create_nol(cpf+2);
    nol *cliente3 = create_nol(cpf+3);
    nol *cliente4 = create_nol(cpf+5);
    nol *cliente5 = create_nol(cpf+4);

    //Cria dois ponteiros auxiliares para facilitar o push e o printf
    nol *ax0 = cliente0;
    nol *ax1 = cliente1;
    nol *ax2 = cliente2;
    nol *ax3 = cliente3;
    nol *ax4 = cliente4;
    nol *ax5 = cliente5;

    //Empilha os nós de cada cliente imprime para testar
    push_l(l, ax4);
    push_l(l, ax2);
    push_l(l, ax0);
    push_l(l, ax5);
    push_l(l, ax1);
    push_l(l, ax3);

    while(isEmpty_l(l)==0){
        int x = l->primeiro->cpf;
        printf("%d\n",x);
        pop_l(l, l->primeiro);
        if(isEmpty_l(l) == 1) break;
    }
    // printf("debug\n");

    //Verificando se a função pop_p está retornando corretamente
    // nol *a = pop_l(l, ax2);
    // printf("%p\n", (void*)a);

    // printf("Vazia: %d\n",isEmpty_l(l)); //Imprime 0 pois a foram feitos 2 push e 1 pop

    // destroy_l(l);     //Destrói toda a pilha e seus dados

    return 0;
}

