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
//Retorna um ponteiro contendo o endereço da lista
lista* create_l();

//Função para criar nó do tipo lista
//Recebe como argumento um usigned long int com o valor do cpf
//Retorna um ponteiro para o nó criado
nol* create_nol(unsigned long int cpf);

//Função para checar se lista está vazia
//Recebe como argumento um ponteiro para a lista a ser analizada
//Retorna 1 se Vazia e 0 se Não vazia
int isEmpty_l(lista* l);

//Função para buscar elemento na lista
//Recebe como argumento um ponteiro para a lista e um usigned long int com o valor do cpf
//Retorna um ponteiro para o nó ou NULL se não encontrado
nol* search_l(lista* l, unsigned long int k);

//Função para inserir elemento na lista em um local de maneira que a lista sempre fica ordenada
//Recebe como argumento um ponteiro para a lista e um ponteiro para o nó de lista que
//Retorna um ponteiro para o nó inserido
nol* push_l(lista* l, nol* x);

//Função para remover elemento da lista
//Recebe como argumento um ponteiro para a lista e um nó para lista
//Retorna elemento que foi retirado da lista
nol* pop_l(lista* l, nol* k);

//Função para destruir lista e todo seu conteúdo
//Recebe como argumento um ponteiro para a lista
lista* destroy_l(lista* l);

#endif // PILHA_H