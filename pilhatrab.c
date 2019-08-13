#include<stdio.h>
#include<stdlib.h>

//Definição do tipo pilha e nó
typedef struct pilha pilha;
typedef struct no no;


//Declaração do tipo nó
struct no{
    int cpf,cpft,valor;
    char op;
    no* prox;
};

//Declaração do tipo pilha
struct pilha{
    no* topo;
    int cont;
};

//Função para inicializar nó
no* create_n(int cpf,int cpft,int valor,char op){
    no *n = (no*) malloc(sizeof(no));
    n->cpf = cpf;
    n->cpft = cpft;
    n->valor = valor;
    n->op = op;
    return n;

}
//Função para inicializar pilha
pilha* create_p(){
        pilha *p = (pilha*) malloc(sizeof(pilha));
        p->topo = NULL;
        p->cont = 0;
    return p;
}

//Função para empilhar elemento
void push_p(pilha *p, no *n){
    n->prox = p->topo;
    p->topo = n;
}

int isEmpty_p(pilha *p){
    if(p->topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    pilha *p = create_p();

    printf("%p %d \n",(void*)p->topo,p->cont);

    int cpf, cpft, valor;
    char op;

    scanf("%d %d %d %c", &cpf, &cpft, &valor, &op);
    no *guiche0 = create_n(cpf, cpft, valor, op);
    printf("%d %d %d %c\n", guiche0->cpf, guiche0->cpft, guiche0->valor, guiche0->op);


}
