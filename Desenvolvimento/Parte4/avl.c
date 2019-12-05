//Gustavo de Oliveira Ferreira
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "avl.h"

typedef struct no no;
typedef struct arvore arvore;

//Struct tipo no
struct no{
    unsigned long int codCliente, qntOp;
    long long int saldo;
    no *esq, *dir, *pai;
};

//Struct tipo arvore
struct arvore{
    no *raiz;
    unsigned long int altura; //Altura da arvore
    unsigned long int tam; //Quantos elementos a arvore contem
};

//Função para alocar espaço do arvore
arvore *create_tree(){
    arvore *arv = (arvore*)malloc(sizeof(arvore));
    arv->raiz = NULL;
    arv->tam = 0;
    return arv;
}

//Função para alocar espaço do no
no *create_no(unsigned long int codCliente, long long int saldo){
    no *n = (no*)malloc(sizeof(no));
    n->codCliente = codCliente;
    n->saldo = saldo;
    n->qntOp = 1;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
}

// Função para verificar se arvore está vazia
int isEmpty(arvore *arv){
    if (arv->raiz == NULL) {       //Se estiver vazia retorna 1
        return 1;
    }
    return 0;
}

//Função para realizar busca na Arvore -> BigO(qntElementos)
//Entra com (raiz(arv), no *n)
no *search_no(no *x, no *n){
    if(x == NULL){
        return x;
    }
    if(x->codCliente < n->codCliente) {
        return search(x->dir, n);
    }
    else if(x->codCliente > n->codCliente) {
        return search(x->esq, n);
    }
    else{
        return x;
    }
}

no *search_cod(no *x, unsigned long int codCliente){
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

//Função iterativa para inserir na ABB
//Se foi inserido corretamente, retorna 1, se já houver o elemento,
//retorna 0 e não insere
int insert_iterativa(arvore *arv, no *x){
    if(arv->raiz == NULL){
        arv->raiz = x;
        arv->tam++;
        return 1;
    }
    else{
        no *auxPai = arv->raiz, *aux = NULL;
        while (auxPai != NULL){
            if(auxPai->codCliente > x->codCliente){
                aux = auxPai->esq;
                if(aux == NULL){
                    auxPai->esq = x;
                    arv->tam++;
                    return 1;
                }
            }
            else if(auxPai->codCliente < x->codCliente){
                aux = auxPai->dir;
                if(aux == NULL){
                    auxPai->dir = x;
                    arv->tam++;
                    return 1;
                }
            }
            auxPai = aux;
        }
    }
    return 0;
}

//Tamanho da arvore
unsigned long int size(arvore *arv){
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

no *remover_abb(arvore *t, no *z){
    if(z->esq == NULL) transplante(t, z, z->dir);
    else if(z->dir == NULL)   transplante(t, z, z->esq);
    else{
        no *y = minimo(z->dir);
        if(y->pai != z){
            transplante(t, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplante(t, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
    }
    t->tam--;
    return z;
}

//raiz - esq - dir
void PreOrdem(no *x){
    if(x!=NULL){
        printf("%lu %lu %lld", x->codCliente, x->qntOp, x->saldo);
        PreOrdem(x->esq);
        PreOrdem(x->dir);
    }
}

//Pode ser utilizada para destruir a arvore
//esq - dir - raiz
void PosOrdem(no *x){
    if(x!=NULL){
        PosOrdem(x->esq);
        PosOrdem(x->dir);
        printf("%lu %lu %lld", x->codCliente, x->qntOp, x->saldo);
    }
}

//Utiliza a idea de varrer atraves de PosOrdem
void destroyTree(arvore *arv, no *x){
    if(x != NULL){
        destroyTree(arv, x->esq);
        destroyTree(arv, x->dir);
        free(x);
    }
    arv->raiz = NULL;
}

//Retorna um ponteiro para a raiz da arvore
no *raiz(arvore *arv){
    return arv->raiz;;
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

int altura(no *n){
    int hDir, hEsq;

    if(n == NULL) return -1;
    hDir = altura(n->dir);
    hEsq = altura(n->esq);

    if(hDir > hEsq) return hDir+1;
    else return hEsq+1;
}

long int saldo_add(no* n, long int valor){
	n->saldo += valor;
    return n->saldo;
}

long int saldo_sub(no* n, long int valor){
	n->saldo -= valor;
    return n->saldo;
}

no *rotacaoEsq(arvore *T, no *x){

}

no *rotacaoDuplaEsq(arvore *T, no *x){
    no *y = x->dir;
    y = rotacaoDir(T, y);
    x = rotacaoEsq(T, x);
    return x;
}

// no *insereAVL(arvore *T, )

// void imprimeArvorePorNivel(no *raiz){
//     if (raiz == NULL) {  // Caso o nó dado esteja vazio
//         cout << "A arvore está vazia" << endl;
//     }
//     else{
//         queue<no*> fila; // Create an empty queue for level order tarversal

//         fila.push(raiz); // Enqueue Root and initialize height

//         while (fila.empty() == false){
//             // nodeCount (queue size) indicates number
//             // of nodes at current lelvel.
//             // Dequeue all nodes of current level and
//             // Enqueue all nodes of next level
//             for(int i = fila.size(); i > 0; i--){
//                 // no *aux = fila.front();
//                 cout << fila.front()->num << " ";
//                 if (fila.front()->esq != NULL)
//                     fila.push(fila.front()->esq);
//                 if (fila.front()->dir != NULL)
//                     fila.push(fila.front()->dir);
//                 fila.pop();
//             }
//             cout << endl;
//         }
//     }
// }

int imprime_AVL_crescente(no *x){
    if(x == NULL){
        printf("A AVL está vazia");
        return 0;
    }
    pilha *stack = create_p();
    while(x != NULL || isEmpty_p(stack)){
        while(x != NULL){
            push(stack, x);
            x = x->esq;
        }
        x = pop_p(stack);
        printf("%lu %lu %lld", x->codCliente, x->qntOp, x->saldo);
        x = x->dir;
    }
    printf("\n");
    destroy_p(stack);
    return 1;
}

int imprime_AVL_crescente(no *x){
    if(x == NULL){
        printf("A AVL está vazia");
        return 0;
    }
    pilha *stack = create_p();
    pilha *p_aux = create_p();
    while(x != NULL || isEmpty_p(p_aux)){
        while(x != NULL){
            push(p_aux, x);
            x = x->esq;
        }
        x = pop_p(p_aux);
        push_p(stack, x);
        x = x->dir;
    }
    while(isEmpty_p(stack) == 0){
        x = pop_p(stack);
        printf("%lu %lu %lld", x->codCliente, x->qntOp, x->saldo);
    }
    printf("\n");
    destroy_p(p_aux);
    destroy_p(stack);
    return 1;
}