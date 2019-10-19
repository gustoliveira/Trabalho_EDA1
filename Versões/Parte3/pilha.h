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

//Função para criar nó
//Recebe como argumento unsigned long int cpf(valor do cpf), unsigned long int cpft(cpf do terceiro),
//char op(caractere informando a operação), long int valor(valor da operação)
//Retorna um ponteiro para o nó criado
no* create_n(unsigned long int cpf,unsigned long int cpft,char op, long int valor);

//Função para criar pilha
//Retorna ponteiro contendo o endereço da pilha
pilha* create_p();

//Função para checar se a pilha está vazia
//Recebe como argumento um ponteiro para a pilha a ser analizada
//Retorna 1 se Vazia e 0 se Não vazia
int isEmpty_p(pilha *p);

//Função para buscar um elemento na pilha
//Recebe como argumento um ponteiro para a pilha e um usigned long int contendo o valor do cpf a ser buscado
//Retorna um ponteiro para o nó ou NULL se não encontrado
no* search_p(pilha* p, unsigned long int cpf);

//Função para inserir elemento no topo da pilha
//Recebe como argumento um ponteiro para a pilha e um ponteiro para o nó que vai ser inserido
//Retorna um ponteiro para o nó recem criado
no* push_p(pilha *p, no *n);

//Função para retirar elemento do topo da pilha
//Recebe como argumento um ponteiro para a pilha
//Retorna um ponteiro para o nó que foi retirado
no* pop_p(pilha *p);

//Função para destruir a pilha e todo seu conteudo
//Recebe como argumento um ponteiro para a pilha a ser destruida
//Retorna um ponteiro para a pilha destruida, se bem sucedido retorna NULL
pilha *destroy_p(pilha *p);

#endif // PILHA_H