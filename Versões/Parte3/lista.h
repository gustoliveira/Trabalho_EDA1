#ifndef LISTA_H
#define LISTA_H

typedef struct lista lista;
typedef struct nol nol;

//Declaração do tipo nó para lista
struct nol{
    unsigned long int cpf,ops; //unsigned long int utilizado para suportar entrada <= 2^32-1
    long int saldo;
    nol* ant;
    nol* prox;
};

//Definição do tipo lista
struct lista{
    nol* primeiro;
    unsigned long int cont;
};

//Função para inicializar lista
lista* create_l();

nol* create_nol(unsigned long int cpf);

//Função para checar se lista está vazia (1 - Vazia / 0 - Não vazia)
int isEmpty_l(lista* l);

//Função para buscar elemento na lista (NULL - Se não encontrado)
nol* search_l(lista* l,unsigned long int k);

//Função para inserir elemento na lista, já ordenando-o
void push_l(lista* l, nol* x);

//Função para remover elemento da lista
nol* pop_l(lista* l, nol* k);

//Função para destruir lista e todo seu conteúdo
void destroy_l(lista* l);

#endif // PILHA_H