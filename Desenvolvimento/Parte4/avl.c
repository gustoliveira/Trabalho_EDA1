//Gustavo de Oliveira Ferreira
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

typedef struct no no;
typedef struct arvore arvore;

struct no{
    int codCliente, qntOp, altura, saldo;
    no *esq, *dir, *pai;
};

struct arvore{
    no *raiz;
    int tam;
};

arvore *create_tree(){
    arvore *arv = (arvore*)malloc(sizeof(arvore));
    arv->raiz = NULL;
    arv->tam = 0;
    return arv;
}

//Retorna um ponteiro para a raiz da arvore
no *raiz(arvore *arv){
    return arv->raiz;
}

//Função para alocar espaço do no
no *create_no(int codCliente, int saldo){
    no *n = (no*)malloc(sizeof(no));
    if(n == NULL){
        return NULL;
    }
    else{
        n->codCliente = codCliente;
        n->saldo = saldo;
        n->qntOp = 1;
        n->altura = 0;
        n->esq = NULL;
        n->dir = NULL;
        n->pai = NULL;
        return n;
    }
}

int isEmpty(arvore *arv){
    if (arv->raiz == NULL) {
        return 1;
    }
    else if(arv->raiz != NULL){
        return 0;
    }
    return 0;
}

no *search_no(no *x, no *n){
    if(x == NULL){
        return x;
    }
    if(x->codCliente < n->codCliente) {
        return search_no(x->dir, n);
    }
    else if(x->codCliente > n->codCliente) {
        return search_no(x->esq, n);
    }
    else{
        return x;
    }
}

no *search_cod(no *x, int codCliente){
    if(x == NULL){
        return x;
    }
    if(x->codCliente < codCliente){
        return search_cod(x->dir, codCliente);
    }
    else if(x->codCliente > codCliente){
        return search_cod(x->esq, codCliente);
    }
    else{
        return x;
    }
}
//Tamanho da arvore
int size(arvore *arv){
    return arv->tam;
}

no *insert(arvore *arv, no *z){
    no *y = NULL;
    no *x = arv->raiz;
    while(x != NULL){
        y = x;
        if(z->codCliente < x->codCliente) x = x->esq;
        else x = x->dir;
    }
    z->pai = y;
    if(y == NULL) arv->raiz = z;
    else if(z->codCliente < y->codCliente) y->esq = z;
    else y->dir = z;

    arv->tam++;
    return z;
}

void transplante(arvore *T, no *u, no *v){
    if(u->pai == raiz(T)) T->raiz = v;
    else if(u == u->pai->esq) u->pai->esq = v;
    else u->pai->dir = v;

    if(v != NULL) v->pai = u->pai;
}

no *minimo(no *x){
    while(x->esq != NULL){
        x = x->esq;
    }
    return x;
}

no *maximo(no *x){
    while(x->dir != NULL){
        x = x->dir;
    }
    return x;
}

no *sucessor(no *x){
    if(x->dir != NULL) return minimo(x->dir);
    no *y = x->pai;
    while(y != NULL && x == y->dir){
        x = y;
        y = x->pai;
    }
    return y;
}

no *predecessor(no *x){
    if(x->dir != NULL) return maximo(x->esq);

    no *y = x->pai;
    while(y != NULL && x == y->esq){
        x = y;
        y = x->pai;
    }
    return y;
}

void PreOrdem(no *x){
    if(x!=NULL){
        printf("%d ", x->codCliente);
        PreOrdem(x->esq);
        PreOrdem(x->dir);
    }
}

void InOrdem(no *x){
    if(x!=NULL){
        InOrdem(x->esq);
        printf("%d ", x->codCliente);
        InOrdem(x->dir);
    }
}
void PosOrdem(no *x){
    if(x!=NULL){
        PosOrdem(x->esq);
        PosOrdem(x->dir);
        printf("%d ", x->codCliente);
    }
}

void imprime_AVL_crescente(no *x){
    if(x!=NULL){
        PosOrdem(x->esq);
        printf("%d %d %d", x->codCliente, x->qntOp, x->saldo);
        PosOrdem(x->dir);
    }
}

void imprime_AVL_decrescente(no *x){
    if(x!=NULL){
        PosOrdem(x->dir);
        printf("%d %d %d", x->codCliente, x->qntOp, x->saldo);
        PosOrdem(x->esq);
    }
}

arvore *destroyTree(arvore *arv, no *x){
    if(x != NULL){
        destroyTree(arv, x->esq);
        destroyTree(arv, x->dir);
        free(x);
    }
    free(arv);
    arv->raiz = NULL;
    return arv;
}

int altura(no *n){
    int hDir, hEsq;

    if(n == NULL) return -1;
    hDir = altura(n->dir);
    hEsq = altura(n->esq);

    if(hDir > hEsq) return hDir+1;
    else return hEsq+1;
}

int saldo_add(no* n, int valor){
	n->saldo += valor;
    return n->saldo;
}

int saldo_sub(no* n, int valor){
	n->saldo -= valor;
    return n->saldo;
}

no *rotacaoSimplesEsq(arvore *T, no *x){
    no *y = x->dir;
    x->dir = y->esq;

    if(T->raiz == x){
        T->raiz = y;
    }
    else{
        if(x == x->pai->esq){
            x->pai->esq = y;
        }
        else{
            x->pai->dir = y;
        }
    }
    x->dir->pai = x;
    y->pai = x->pai;
    x->pai = y;
    y->esq = x;

    x->altura = altura(x);
    y->altura = altura(y);

    printf("Rotação Simples Esquerda");
    return y;
}

no *rotacaoSimplesDir(arvore *T, no *x){
    no *y = x->esq;
    x->esq = y->dir;

    if(T->raiz == x){
        T->raiz = y;
    }
    else{
        if(x == x->pai->esq){
            x->pai->esq = y;
        }
        else{
            x->pai->dir = y;
        }
    }
    x->esq->pai = x;
    y->pai = x->pai;
    x->pai = y;
    y->dir = x;

    x->altura = altura(x);
    y->altura = altura(y);

    printf("Rotação Simples Direita");
    return y;
}

no *rotacaoDuplaEsq(arvore *T, no *x){
    no *y = x->dir;
    y = rotacaoSimplesDir(T, y);
    x = rotacaoSimplesEsq(T, x);
    printf("Rotação Dupla Esquerda");
    return x;
}

no *rotacaoDuplaDir(arvore *T, no *x){
    no *y = x->dir;
    x = rotacaoSimplesEsq(T, x);
    y = rotacaoSimplesDir(T, y);
    printf("Rotação Dupla Direita");
    return x;
}

int max(int a, int b){
	return (a > b) ? a : b;
}

int altura_no(no* n){
    if (n == NULL) return 0;
    else return (max(altura_no(n->esq), altura_no(n->dir))+1);
}

int balanco(no *n){
    return(altura_no(n->esq)-altura_no(n->dir));
}

no *balanceamento(arvore* T, no *x){
    if(balanco(x) == -2){
        no *y = x->dir;
        if(balanco(y) == 1){
            rotacaoDuplaEsq(T, x);
        }
        else{
            rotacaoSimplesEsq(T, x);
        }
    }
    if(balanco(x) == 2){
        no *y = x->esq;
        if(balanco(y) == -1){
            rotacaoDuplaDir(T, x);
        }
        else{
            rotacaoSimplesDir(T, x);
        }
    }
    return x;
}

no *insereAVL(arvore *T, no *x, no *novo){
    if(T->raiz == NULL){
        T->raiz = novo;
        novo->altura = 1;
        novo->pai = NULL;
        return novo;
    }
    // printf("Debug\n");
    if(novo->codCliente < x->codCliente){
        if(x->esq == NULL){
            x->esq = novo;
            novo->altura = 1;
            novo->pai = x;
        }
        else{
            x->esq = insereAVL(T, x->esq, novo);
        }
    }
    if(novo->codCliente > x->codCliente){
        if(x->dir == NULL){
            x->dir = novo;
            novo->altura = 1;
            novo->pai = x;
        }
        else{
            x->dir = insereAVL(T, x->dir, novo);
        }
    }
    int k = balanco(x);
    if(k < 0) k = k * (-1);

    if(k == 2){
        balanceamento(T, x);
    }
    return novo;
}

// no *removeAVL(arvore *T, no *x, int k){
//     if(x == NULL){
//         return NULL;
//     }

//     if(k < x->codCliente){
//         x->esq = removeAVL(T, x->esq, k);
//     }
//     else{
//         if(k > x->codCliente){
//             x->dir = removeAVL(T, x->dir, k);
//         }
//         else{
//             if(x->esq == NULL){
//                 transplante(T, x, x->dir);
//             }
//             else if(x->dir == NULL){
//                 transplante(T, x, x->esq);
//             }
//             else{
//                 y = AVL_Mi
//             }
//         }
//     }
// }

