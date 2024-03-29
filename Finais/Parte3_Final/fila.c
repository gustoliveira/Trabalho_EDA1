#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "no.h"
#include "fila.h"

typedef struct no no;
typedef struct fila fila;

struct no{
    unsigned long int cpf,cpft;
    long int valor;
    char op;
    no* prox;
};

struct fila{
	unsigned long int inicio,fim,qtd,tam;
	no** vetor;
};

fila* create_f(unsigned long int tam0){
	unsigned long int tamanho = floor(sqrt(tam0));

	fila* f = (fila*) malloc(sizeof(fila));
 	if(f!=NULL){
 		f->inicio = 0;
 		f->fim = tamanho-1;
 		f->qtd = 0;
 		f->tam = tamanho;
 		f->vetor = (no**) malloc(sizeof(no*)*f->tam);
 		if(f->vetor == NULL) return NULL;
 		else return f;
 	}
 	else return NULL;
}

//Função que retorna 1 se a fila está cheia ou 0 senão
int full_f(fila *f){
	if(f->qtd == f->tam) return 1;
	else return 0;
}

//Função para checar se a fila está vazia
int isEmpty_f(fila *f){
	if(f->qtd == 0) return 1;
	else return 0;
}

//Função para enfileirar elemento
void push_f(fila *f,no* x){
	if(full_f(f) != 1){
		f->fim = (f->fim+1)%f->tam;
		f->vetor[f->fim] = x;
		f->qtd++;
	}
	else return;
}

//Função para desenfileirar primeiro elemento da fila (NULL se vazia)
no* pop_f(fila *f){
	if(isEmpty_f(f)==1){
		return NULL;
	}
	else{
		unsigned long int x = f->inicio;
		f->inicio = (f->inicio+1)%f->tam;
		f->qtd--;
		return f->vetor[x];
	}
}

//Retorna primeiro elemento da fila (NULL - Caso fila vazia)
no* front_f(fila*f){
	if(isEmpty_f(f)==1) {
		return NULL;
	}
	else {
		return f->vetor[f->inicio];
	}
}

//Retorna tamanho da fila
unsigned long int size_f(fila* f){
	return f->tam;
}

//Procura pela primeira ocorrência de um CPF na fila, e retorna-a (NULL Caso não encontrado ou Fila Vazia)
no* search_f (fila* f,unsigned long int cpf){
	no* resultado = NULL;
	if(isEmpty_f(f)==0){
		int flag=0;
		for(unsigned long int i =0; i<f->tam;i++){
			no* aux = front_f(f);
			if(aux->cpf == cpf && flag == 0){
				resultado = aux;
			}
			pop_f(f);
			push_f(f,aux);
		}
	}
	return resultado;
}

//Função para destuir a fila e todos os nós referentes
void destroy_f(fila* f){
	while(isEmpty_f(f)==0){
		no* cliente  = pop_f(f);
		free(cliente);
	}
	free(f->vetor);
	free(f);
}

//Função para acessar inicio da fila
unsigned long int inicio_f(fila *f){
	return f->inicio;
}

//Função para acessar fim da fila
unsigned long int fim_f(fila *f){
	return f->fim;
}

//Função para acessar quantidade de elementos na fila
unsigned long int qtd_f(fila *f){
	return f->qtd;
}

//Função para acessar tamanho da fila
unsigned long int tam_f(fila *f){
	return f->tam;
}

//Função para acessar ponteiro de ponteiros da fila
no** vetor_f(fila *f){
	return f->vetor;
}

//Função para acessar cpf do nó
unsigned long int cpf_f(no *n){
	return n->cpf;
}

//Função para acessar cpft do nó
unsigned long int cpft_f(no *n){
	return n->cpft;
}

//Função para acessar valor do nó
long int valor_f(no *n){
	return n->valor;
}

//Função para acessar quantidade de operações do nó
char op_f(no *n){
	return n->op;
}

//Função para acessar proximo nó
no *prox_f(no *n){
	return n->prox;
}
