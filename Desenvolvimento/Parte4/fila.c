#include <stdio.h>
#include <stdlib.h>
typedef struct fila fila;
typedef struct no no;

struct no{
    unsigned long int codCliente, qntOp;
    long long int saldo;
    no *esq, *dir, *pai;
};

struct fila{
	no* inicio, *fim;
	unsigned long int tam;
};

void destroi(fila *f){
	while(vazia(f) != 1){
		no *aux = desenfileira(f);
		free(aux);
	}
}

fila* cria_fila(){
    fila *f = (fila*) malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int vazia(fila *f){
    if (f->inicio == NULL) return 1;
    else return 0;
}

void enfileira(fila *f,no* x){
    if(vazia(f)==1){
        f->inicio = x;
        f->fim = x;
    }
    else{
        f->fim->esq = x;
        f->fim = x;
    }
    x->esq = NULL;
	f->tam++;
}

no* desenfileira(fila *f){
    if(vazia(f)==1) return NULL; //Fila vazia
    else{
        no* x = f->inicio;
        f->inicio = x->esq;
        if(f->inicio == NULL){
            f->fim=NULL;
        }
        x->esq = NULL;
		f->tam--;
        return x;
    }
}

no *frente(fila*f){
    if(vazia(f)==1 || f->inicio == NULL) return 0;
    else return f->inicio;
}

int imprimeArvorePorNivel(no *raiz){
    if (raiz == NULL) {  // Caso o nó dado esteja vazio
        printf("A arvore está vazia");
		return 0;
    }
	fila *f = cria_fila();
	enfileira(f, raiz);

	while (vazia(f) != 1){
		for(int i = f->tam; i > 0; i--){
			no *aux = frente(f);
			printf("%lu %lu %ld", aux->codCliente, aux->qntOp, aux->saldo);
			if (aux->esq != NULL)
				enfileira(f, aux->esq);
			if (aux->dir != NULL)
				enfilera(f, aux->dir);
			desenfileira(f);
		}
		printf("\n");
	}
	return 1;
}
