#include <stdlib.h>
#include <stdio.h>
#include "no.h"

typedef struct no no;
typedef struct nol nol;

struct no{
    unsigned long int cpf,cpft;
    long int valor;
    char op;
    no* prox;
};

struct nol{
    unsigned long int cpf,ops; //unsigned long int utilizado para suportar entrada <= 2^32-1
    long int saldo;
    nol* ant;
    nol* prox;
};

//Função para inicializar nó
no* create_n(unsigned long int cpf, unsigned long int cpft, char op, long int valor){
  no *n = (no*) malloc(sizeof(no));
  if(n!=NULL){ //Testa a alocação
	    n->cpf = cpf;
	    n->cpft = cpft;
	    n->valor = valor;
	    n->op = op;
	    n->prox = NULL;
	    return n;
	}
	else return NULL;
}

//Função para inicializar nó de lista
nol* create_nol(unsigned long int cpf){
  nol *n = (nol*) malloc(sizeof(nol));
  if(n!=NULL){
	    n->cpf = cpf;
      n->ops = 0;
      n->saldo = 0;
	    return n;
	}
	else return NULL;
}

