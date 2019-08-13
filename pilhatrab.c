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

no* pop_p(pilha *p){
	if(p->topo == NULL){
        return NULL;
    }
    else{
        no* aux = p->topo;
        p->topo = aux->prox;
        aux->prox = NULL;
        return aux;
    }
}

int main(){

    pilha *p = create_p();

    printf("%p %d \n",(void*)p->topo,p->cont);

    int cpf, cpft, valor;
    char op;

    scanf("%d %d %d %c", &cpf, &cpft, &valor, &op);
    no *cliente0 = create_n(cpf, cpft, valor, op);
    push_p(p,cliente0);
    printf("%d %d %d %c \n",p->topo->cpf,p->topo->cpft,p->topo->valor,p->topo->op);
    printf("Vazia: %d \n",isEmpty_p(p));
    no* a = pop_p(p);
    printf("%p \n", (void*) a);
    printf("Vazia: %d\n",isEmpty_p(p));
    free(a);
    free(p);

}
