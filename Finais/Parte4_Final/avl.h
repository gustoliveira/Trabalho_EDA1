//Gustavo de Oliveira Ferreira

#ifndef AVL_H
#define AVL_H

typedef struct no no;
typedef struct arv arv;

//Função para alocar espaço do arvore
//Retorna um ponteiro para a arvore alocada
arv *create_tree();

//Função para alocar espaço do no
//Retorna ponteiro para o nó alocado
no *create_no(int codCliente, int saldo);

//Função para inserir nó na árvore
//Recebe como argumento ponteiro para a arvore, raiz(), e nó a ser adicionado
//Retorna ponteiro para nó adicionado
no *insereAVL(arv *T, no *x, no *novo);

//Função para balancear árvore
//Recebe como argumento ponteiro para a arvore e ponteiro para o nó
no *balanceia(arv* A, no* node);

//Função para alterar o saldo de um nó
//Recebe com argumento um ponteiro para o nó a ser alterado, o valor, e uma flag
//Insira 1 caso queira subtrair e 0 caso queira adicionar
//Retorna um inteiro contendo o novo saldo do nó
int alterar_saldo(no* n, int valor);

//Função para realizar busca na arv com base no código
//Recebe o nó principal, utilizar função raiz() e o nó que se quer ser procurado
//Retorna um ponteiro para o nó se ele for encontrado e NULL se não houver na arv
int consulta_no(arv* A, int cod);

//Função para saber a altura de um nó;
//Recebe como argumento o nó que se quer saber a altura
//Retorna um inteiro contendo a altura do nó dado
int altura_no(no* n);

//Função para remover nó
//Recebe como argumentos um ponteiro para a arvore, raiz(), e inteiro contendo ó codCliente do nó a ser removido
//Retorna ponteiro para nó removido
no *removeAVL(arv *T, no *x, int codCliente);

//Busca o nó com código sucessor do nó dado
//Recebe o nó que se quer buscar o sucessor
//Retorna ponteiro com nó para o sucessor
no *sucessor(no *x);

//Função para mostrar o 'no cabeça' de uma árvore
//Recebe como argumento um ponteiro para a arv
//Retorna um ponteiro do tipo nó contendo o nó principal
no *raiz(arv *arv);

//Função para retornar ponteiro para o filho a esquerda de um nó
//Rebebe como argumento um ponteiro para o nó
no *noEsq(no *n);

//Função para retornar ponteiro para o filho a Direita de um nó
//Rebebe como argumento um ponteiro para o nó
no *noDir(no *n);

//Função para retornar ponteiro para o pai de um nó
//Rebebe como argumento um ponteiro para o nó
no *noPai(no *n);

//Função para mostrar a quantidade de elementos de uma arv
//Recebe como argumento um ponteiro para a arv
//Retorna um inteiro referente a quantidade de nós de uma árvore
int tam_arv(arv *A);

//Função para mostrar codCliente de um nó
//Recebe como argumento um ponteiro para o nó que se quer mostrar o codCliente
//Retorna um inteiro contendo o codCliente
int codCliente_no(no *n);

//Função para mostrar saldo de um nó
//Recebe como argumento um ponteiro para o nó que se quer mostrar o saldo
//Retorna um inteiro contendo o saldo
int saldo_no(no *n);

//Função para mostrar a quantidade de operações de um nó
//Recebe como argumento um ponteiro para o nó que se quer mostrar a quantidade de operações
//Retorna um inteiro contendo a quantidade de operações
int qntOp_no(no *n);

//Função para realizar busca na arv com base no código
//Recebe o nó principal, utilizar função raiz() e o nó que se quer ser procurado
//Retorna um ponteiro para o nó se ele for encontrado e NULL se não houver na arv
no *search_cod(no *x, int codCliente);

#endif