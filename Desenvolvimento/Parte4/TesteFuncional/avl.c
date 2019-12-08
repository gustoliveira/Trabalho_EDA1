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

// no* removeAVL(arv *T, no* x, int codCliente){
//     if(x == NULL){
//         return NULL;
//     }
//     if(codCliente < x->codCliente){
//         x->esq = removeAVL(T, x->esq, codCliente);
//     }
//     else if(codCliente > x->codCliente){
//         x->esq = removeAVL(T, x->dir, codCliente);
//     }
//     else if(codCliente == x->codCliente){
//         T->tam--;
//         if(x->esq == NULL){
//             if(x->pai->esq = x) x->pai->esq = transplante(T, x, x->dir);
//             else x->pai->dir = transplante(T, x, x->dir);
//         }
//         else if(x->dir == NULL){
//             if(x->pai->esq = x) x->pai->esq = transplante(T, x, x->esq);
//             else x->pai->dir = transplante(T, x, x->esq);
//         }
//         else{
//             no* y = minimo(x->dir);
//             no *z = copia_no(y);
//             transplante(T, x, z);
//             z->esq = x->esq;
//             z->dir = x->dir;
//             if(x->dir != NULL) x->dir->pai = z;
//             if(x->esq != NULL) x->esq->pai = z;
//             x = z;
//             x->dir = removeAVL(T, x->dir, y->codCliente);

//         }
//     }
//     if(x == NULL){
//         return NULL;
//     }
//     x->altura = altura_no(x);
//     if(balanco(x) == 2 || balanco(x) == -2){
//         balanceia(T, x);
//     }
//     return x;
// }
// no *copia_no(no *y){
//     no* z = create_no(y->codCliente, y->saldo);
//     z->altura = y->altura;
//     z->qntOp = y->qntOp;
//     return z;
// }

no* removeAVL (arv* A, no* n, int k){
    if (n == NULL)
        return NULL;
    if (n->codCliente < k){
        return removeAVL(A, n->dir, k);
    }
    else if (n->codCliente > k){
        return removeAVL(A, n->esq, k);
    }
    else if(n->codCliente == k){
        A->tam--;
        no* removido = n;
        //FOLHA
        if (n->dir == NULL && n->esq == NULL){
            if (A->raiz == n){
                A->raiz = NULL;
            }
            else if (n->pai->dir == n){
                n->pai->dir = NULL;
            }
            else{
                n->pai->esq = NULL;
            }
            balanceia(A, n->pai);
        }
        //UM FILHO NA ESQ
        else if (n->dir == NULL){
            if (A->raiz == n){
                A->raiz = n->esq;
                n->esq->pai = NULL;
            }
            else if (n->pai->dir == n){
                n->pai->dir = n->esq;
                n->esq->pai = n->pai;
            }
            else{
                n->pai->esq = n->esq;
                n->esq->pai = n->pai;
            }
            balanceia(A, n->esq);
        }
        //UM FILHO NA DIR
        else if (n->esq == NULL){
            if (A->raiz == n){
                A->raiz = n->dir;
                n->dir->pai = NULL;
            }
            else if (n->pai->dir == n){
                n->pai->dir = n->dir;
                n->dir->pai = n->pai;
            }
            else{
                n->pai->esq = n->dir;
                n->dir->pai = n->pai;
            }
            balanceia(A, n->dir);
        }
        //DOIS FILHOS
        else{
            no* suc = sucessor(n);
            no* aux = suc->pai;
            if (n->dir == suc)
                aux = suc;
            //DOIS FILHOS E RAIZ
            if (A->raiz == n){
                A->raiz = suc;
                if (n->dir != suc){
                    if (suc->dir != NULL){
                        suc->dir->pai = suc->pai;
                    }
                    suc->pai->esq = suc->dir;
                }
                suc->pai = NULL;
            }
            //DOIS FILHOS E NAO RAIZ
            else{
                if (n->pai->dir == n){
                    n->pai->dir = suc;
                    if (n->dir != suc){
                        suc->pai->esq = suc->dir;
                        if (suc->dir != NULL){
                            suc->dir->pai = suc->pai;
                        }
                    }
                    suc->pai = n->pai;
                }
                else{
                    n->pai->esq = suc;
                    if (n->dir != suc){
                        suc->pai->esq = suc->dir;
                        if (suc->dir) suc->dir->pai = suc->pai;
                    }
                    suc->pai = n->pai;
                }
            }
            suc->esq = n->esq;
            if (suc->esq) suc->esq->pai = suc;
            if (n->dir != suc){
                suc->dir = n->dir;
                if (suc->dir) suc->dir->pai = suc;
            }
            balanceia(A, aux);
        }
        return removido;
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

void imprime_AVL_crescente(no* n){
    if (n == NULL) return;
    else{
        imprime_AVL_crescente(n->esq);
        printf("%d %d %d\n", n->codCliente, n->qntOp, n->saldo);
        imprime_AVL_crescente(n->dir);
    }
}

void imprime_AVL_decrescente(no* n){
    if (n == NULL) return;
    else{
        imprime_AVL_decrescente(noDir(n));
        printf("%d %d %d\n", n->codCliente, n->qntOp, n->saldo);
        imprime_AVL_decrescente(n->esq);
    }
}

void imprime_AVL_nivel(no* n, int nivel, int cont){
    if(n == NULL) return;
    else if(nivel == cont){
        printf("%d\n", n->codCliente);
    }
    else{
        imprime_AVL_nivel(n->esq, nivel, cont+1);
        imprime_AVL_nivel(n->dir, nivel, cont+1);
    }
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

