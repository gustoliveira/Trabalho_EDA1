#ifndef PILHA_H
#define PILHA_H

typedef struct no no;
typedef struct pilha pilha;

//Declaração do tipo nó
struct no{
    unsigned long int cpf,cpft; //unsigned long int utilizado para suportar entrada <= 2^32-1
    long int valor;
    char op;
    no* prox;
};

//Declaração do tipo pilha
struct pilha{
    no* topo;
    unsigned long int cont;
};

no* create_n(unsigned long int cpf,unsigned long int cpft,char op, long int valor);
pilha* create_p();
no* push_p(pilha *p, no *n);
int isEmpty_p(pilha *p);
no* pop_p(pilha *p);
pilha *destroy_p(pilha *p);
no* search_p(pilha* p, unsigned long int cpf);

#endif // PILHA_H