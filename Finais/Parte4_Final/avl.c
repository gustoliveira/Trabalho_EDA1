//Gustavo de Oliveira Ferreira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

typedef struct no no;
typedef struct arv arv;

struct no{
    int codCliente, qntOp, saldo, altura;
    no *esq, *dir, *pai;
};

struct arv{
    no* raiz;
    int tam;
};

//FUNÇÕES PARA ALOCAÇÃO DE MEMÓRIA
arv *create_tree(){
    arv* A = (arv*)malloc(sizeof(arv));
    if (A == NULL){
        return NULL;
    }
    A->raiz = NULL;
    A->tam = 0;
    return A;
}

no* create_no (int cod, int val){
    no* n = (no*)malloc(sizeof(no));
    if (n == NULL){
        return NULL;
    }
    n->codCliente = cod;
    n->qntOp = 1;
    n->saldo = val;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    n->altura = 0;
    return n;
}
//FIM

//FUNÇÕES PARA BALANCEAMENTO
no *RotSimplesEsq(arv *T, no *x){
    no* y = x->dir;
    x->dir = y->esq;
    if (y->esq != NULL) y->esq->pai = x;
    y->esq = x;
    y->pai = x->pai;
    if (T->raiz == x) T->raiz = y;
    else{
        if (x->pai->dir == x) x->pai->dir = y;
        else x->pai->esq = y;
    }
    x->pai = y;
    x->altura = altura_no(x);
    y->altura = altura_no(y);
    return y;
}

no *RotSimplesDir(arv *T, no *x){
    no* y = x->esq;
    x->esq = y->dir;
    if (y->dir != NULL) y->dir->pai = x;
    y->dir = x;
    y->pai = x->pai;
    if (T->raiz == x){
        T->raiz = y;
    }
    else{
        if (x->pai->dir == x){
            x->pai->dir = y;
        }
        else x->pai->esq = y;
    }
    x->pai = y;
    x->altura = altura_no(x);
    y->altura = altura_no(y);
    return y;
}

no *rotacaoDuplaEsq(arv *T, no *x){
    no *y = x->dir;
    y = RotSimplesDir(T, y);
    x = RotSimplesEsq(T, x);
    return x;
}

no *rotacaoDuplaDir(arv *T, no *x){
    no *y = x->esq;
    y = RotSimplesEsq(T, y);
    x = RotSimplesDir(T, x);
    return x;
}

int balanco(no *n){
    if(n == NULL) return 0;
    return altura_no(n->esq)-altura_no(n->dir);
}

no *balanceia(arv* T, no *x){
    if(x == NULL){
        return NULL;
    }
    else{
        if(balanco(x) == -2){
            if(balanco(x->dir) == 1){
                rotacaoDuplaEsq(T, x);
            }
            else{
                RotSimplesEsq(T, x);
            }
        }
        else if(balanco(x) == 2){
            if(balanco(x->esq) == -1){
                rotacaoDuplaDir(T, x);
            }
            else{
                RotSimplesDir(T, x);
            }
        }
        balanceia(T, x->pai);
        return x;
    }
}
//FIM

int alterar_saldo(no* n, int val){
    n->saldo += val;\
    n->qntOp++;
    return n->saldo;
}

int consulta_no (arv* A, int cod){
    if (A->raiz == NULL){
        return 0;
    } else{
        no* n = A->raiz;
        while (n != NULL && n->codCliente != cod){
            if (cod < n->codCliente){
                n = n->esq;
            }
            else{
                n = n->dir;
            }
        }
        if (n == NULL)
            return 0;
        else
            return 1;
    }
}

int max(int a, int b){
	return (a > b) ? a : b;
}

int altura_no(no* raiz){
    if (raiz == NULL) return 0;
    else return (max(altura_no(raiz->esq), altura_no(raiz->dir))+1);
}

no* sucessor (no* n){
    if (n == NULL && n->dir != NULL){
        return NULL;
    }
    no* aux = n->dir;
    while (aux->esq != NULL){
        aux = aux->esq;
    }
    return aux;
}

no *minimo(no *x){
    while(x->esq != NULL){
        x = x->esq;
    }
    return x;
}

no *transplante(arv *T, no *u, no *v){
    if(raiz(T) == u){
        T->raiz = v;
    }
    else if(u == u->pai->esq){
        u->pai->esq = v;
    }
    else{
        u->pai->dir = v;
    }

    if(v != NULL) v->pai = u->pai;
    return u;
}

no* removeAVL (arv* T, no* n, int codCliente){
    if (n == NULL){
        return NULL;
    }
    if (n->codCliente < codCliente){
        return removeAVL(T, n->dir, codCliente);
    }
    else if (n->codCliente > codCliente){
        return removeAVL(T, n->esq, codCliente);
    }
    else if(n->codCliente == codCliente){
        no *retorno = n;
        if (n->dir == NULL && n->esq == NULL){
            if (T->raiz == n) T->raiz = NULL;
            else if (n->pai->esq == n) n->pai->esq = NULL;
            else n->pai->dir = NULL;

            balanceia(T, n->pai);
        }
        else{
            if (n->dir == NULL){
                if (T->raiz == n){
                    T->raiz = n->esq;
                    n->esq->pai = NULL;
                }
                else if (n->pai->esq == n){
                    n->pai->esq = n->esq;
                    n->esq->pai = n->pai;
                }
                else{
                    n->pai->dir = n->esq;
                    n->esq->pai = n->pai;
                }
                balanceia(T, n->esq);
            }
            else if (n->esq == NULL){
                if (T->raiz == n){
                    T->raiz = n->dir;
                    n->dir->pai = NULL;
                }
                if (n->pai->esq == n){
                    n->pai->esq = n->dir;
                    n->dir->pai = n->pai;
                }
                else{
                    n->pai->dir = n->dir;
                    n->dir->pai = n->pai;
                }
                balanceia(T, n->dir);
            }
            else{
                no* min_dir = minimo(n->dir);
                no* x = min_dir->pai;
                if (n->dir == min_dir) x = min_dir;
                if (T->raiz == n){
                    T->raiz = min_dir;
                    if (n->dir != min_dir){
                        if (min_dir->dir != NULL){
                            min_dir->dir->pai = min_dir->pai;
                        }
                        min_dir->pai->esq = min_dir->dir;
                    }
                    min_dir->pai = NULL;
                }
                else{
                    if (n->pai->dir == n){
                        n->pai->dir = min_dir;
                        if (n->dir != min_dir){
                            min_dir->pai->esq = min_dir->dir;
                            if (min_dir->dir != NULL){
                                min_dir->dir->pai = min_dir->pai;
                            }
                        }
                        min_dir->pai = n->pai;
                    }
                    else{
                        n->pai->esq = min_dir;
                        if (n->dir != min_dir){
                            min_dir->pai->esq = min_dir->dir;
                            if (min_dir->dir) min_dir->dir->pai = min_dir->pai;
                        }
                        min_dir->pai = n->pai;
                    }
                }
                min_dir->esq = n->esq;
                if (min_dir->esq) min_dir->esq->pai = min_dir;
                if (n->dir != min_dir){
                    min_dir->dir = n->dir;
                    if (min_dir->dir) min_dir->dir->pai = min_dir;
                }
                balanceia(T, x);
            }
        }
        T->tam--;
        return retorno;
    }
}

no *insereAVL(arv *T, no *x, no *novo){
    if(T->raiz == NULL){
        T->raiz = novo;
        novo->altura = 1;
        novo->pai = NULL;
        T->tam++;
    }
    else{
        if(novo->codCliente < x->codCliente){
            if(x->esq == NULL){
                x->esq = novo;
                novo->pai = x;
                novo->altura = 1;
                T->tam++;
            }
            else{
                insereAVL(T, x->esq, novo);
            }
        }
        else if(novo->codCliente > x->codCliente){
            if(x->dir == NULL){
                x->dir = novo;
                novo->altura = 1;
                novo->pai = x;
                T->tam++;
            }
            else{
                insereAVL(T, x->dir, novo);
            }
        }

        balanceia(T, x);
    }
    return x;
}

no *raiz(arv *T){
    return T->raiz;
}

no *noEsq(no *n){
    return n->esq;
}

no *noDir(no *n){
    return n->dir;
}

no *noPai(no *n){
    return n->pai;
}

int tam_arv(arv *A){
    if(A != NULL) return A->tam;
    else return 0;
}

int codCliente_no(no *n){
    if(n == NULL) return 0;
    return n->codCliente;
}

int saldo_no(no *n){
    if(n == NULL) return 0;
    return n->saldo;
}

int qntOp_no(no *n){
    if(n == NULL) return 0;
    return n->qntOp;
}

no *search_cod(no *x, int codCliente){
    no *y = x;
    while (x != NULL && x->codCliente != codCliente){
        y = x;
        if (x->codCliente > codCliente){
            x = x->esq;
        }
        else{
            x = x->dir;
        }
    }
    return x;
}

