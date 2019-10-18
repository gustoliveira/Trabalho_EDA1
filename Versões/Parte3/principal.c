#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    pilha *p = create_p();                          //Criou a pilha

    long long int cpf, cpft, valor; char op;                  //Criou variáveis para ler valores
    scanf("%lld %lld %c %lld", &cpf, &cpft, &op, &valor);


    // Imprime os valores no topo da pilha, como os nós foram apenas criados mas não
    // foi feito push, dará falha de segmentação, afinal, os nós não foram ligados
    // a pilha ainda
    // //printf("%d %d %d %c \n",p->topo->cpf,p->topo->cpft,p->topo->valor,p->topo->op);

    printf("debug\n");

    printf("Vazia: %d \n",isEmpty_p(p));  //Verifica se a pilha está vazia


    //Um ponteiro para cada cliente receber o retorno da função create_n
    no *cliente0 = create_n(cpf, cpft, op, valor);
    no *cliente1 = create_n(cpf+1, cpft+1, op, valor+1);
    //Cria dois ponteiros auxiliares para facilitar o push e o printf
    no *ax0 = cliente0;
    no *ax1 = cliente1;

    //Empilha os nós de cada cliente imprime para testar
    push_p(p, ax0);
    printf("%ld %ld %c %ld \n", ax0->cpf, ax0->cpft, ax0->op, ax0->valor);
    push_p(p, ax1);
    printf("%ld %ld %c %ld \n", ax1->cpf, ax1->cpft, ax1->op, ax1->valor);

    //Verificando se a função pop_p está retornando corretamente
    no *a = pop_p(p);
    printf("%p\n", (void*)a);

    printf("Vazia: %d\n",isEmpty_p(p)); //Imprime 0 pois a foram feitos 2 push e 1 pop

    destroy_p(p);     //Destrói toda a pilha e seus dados

    return 0;
}

