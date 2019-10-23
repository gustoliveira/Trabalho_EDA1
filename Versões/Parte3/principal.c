#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"
#include "fila.h"

int main(){

    unsigned long int cpf, cpft;
    long int tam;
    char c;                  //Criou variáveis para ler valores
    scanf("%lu %lu %c %lu", &cpf, &cpft, &c, &tam);


    fila *f = create_f(tam);

    // Imprime os valores no topo da pilha, como os nós foram apenas criados mas não
    // foi feito push, dará falha de segmentação, afinal, os nós não foram ligados
    // a pilha ainda
    // //printf("%d %d %d %c \n",p->topo->cpf,p->topo->cpft,p->topo->valor,p->topo->op);


    // printf("Vazia: %d \n",isEmpty_l(l));  //Verifica se a pilha está vazia

    //Um ponteiro para cada cliente receber o retorno da função create_n
    no *cliente0 = create_no(cpf+1, cpft+1, c, 100);
    no *cliente1 = create_no(cpf+2, cpft+2, c, 200);
    no *cliente2 = create_no(cpf+3, cpft+3, c, 300);
    no *cliente3 = create_no(cpf+4, cpft+4, c, 400);
    no *cliente4 = create_no(cpf+5, cpft+5, c, 500);
    no *cliente5 = create_no(cpf+6, cpft+6, c, 600);

    //Cria dois ponteiros auxiliares para facilitar o push e o printf
    no *ax0 = cliente0;
    no *ax1 = cliente1;
    no *ax2 = cliente2;
    no *ax3 = cliente3;
    no *ax4 = cliente4;
    no *ax5 = cliente5;

    //Empilha os nós de cada cliente imprime para testar
    push_f(f, ax4);
    push_f(f, ax2);
    push_f(f, ax0);
    push_f(f, ax5);
    push_f(f, ax1);
    push_f(f, ax3);

    while(isEmpty_f(f)==0){


        int x = l->primeiro->cpf;
        printf("%d\n",x);
        pop_f(l, l->primeiro);
        if(isEmpty_f(l) == 1) break;
    }

    // destroy_l(l);
    // int x = l->primeiro->cpf;
    // printf("%d\n", x);

    // printf("debug\n");

    //Verificando se a função pop_p está retornando corretamente
    // nol *a = pop_l(l, ax2);
    // printf("%p\n", (void*)a);

    // printf("Vazia: %d\n",isEmpty_l(l)); //Imprime 0 pois a foram feitos 2 push e 1 pop

    // destroy_l(l);     //Destrói toda a pilha e seus dados

    return 0;
}

