//Gustavo de Oliveira Ferreira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

//INSERE OU ALTERA VALOR NA ÁRVORE
void insere(arv* T, int codCliente, int op, int valor){
    no *n = search_cod(raiz(T), codCliente);
    if(op == 1){
        valor = valor*(-1);
    }
    if(n == NULL){
        insereAVL(T, raiz(T), create_no(codCliente, valor));
    }
    else{
        alterar_saldo(n, valor);
    }
}

//CONSULTA SE NÓ EXISTE OU NÃO
void consulta(arv* T, int codCliente){
    no *n = search_cod(raiz(T), codCliente);
    if(n == NULL) printf("nao existe no com chave: %d\n", codCliente);
    else printf("existe no com chave: %d\n", codCliente);
}

//REMOVE NÓ
void remove_no(arv* T, int codCliente){
    if(consulta_no(T, codCliente)){
        no* removido = removeAVL(T, raiz(T), codCliente);
        free(removido);
    }
}

//IMPRIME ARVORE EM ORDEM CRESCENTE
void imprime_AVL_crescente(no* n){
    if (n == NULL) return;
    else{
        imprime_AVL_crescente(noEsq(n));
        printf("%d %d %d\n", codCliente_no(n), qntOp_no(n), saldo_no(n));
        imprime_AVL_crescente(noDir(n));
    }
}

//IMPRIME ARVORE EM ORDEM DESCRESCENTE
void imprime_AVL_decrescente(no* n){
    if (n == NULL) return;
    else{
        imprime_AVL_decrescente(noDir(n));
        printf("%d %d %d\n", codCliente_no(n), qntOp_no(n), saldo_no(n));
        imprime_AVL_decrescente(noEsq(n));
    }
}

void imprime_AVL_nivel(no* n, int nivel, int cont){
    if(n == NULL) return;
    else if(nivel == cont){
        printf("%d\n", codCliente_no(n));
    }
    else{
        imprime_AVL_nivel(noEsq(n), nivel, cont+1);
        imprime_AVL_nivel(noDir(n), nivel, cont+1);
    }
}

//IMPRIME NÍVEL DA AVL
void imprime_nivel(arv* T, int nivel){
    if(altura_no(raiz(T)) >= nivel){
        imprime_AVL_nivel(raiz(T), nivel, 1);
    }
}

//IMPRIME RELATÓRIO FINAL
void relatorio_final(arv* T){
    int n = tam_arv(T);
    printf("-+- Inicio relatorio -+-\n%d\n", n);
    for(int i = 0; i < n; i++){
        no* removido = removeAVL(T, raiz(T), codCliente_no(raiz(T)));
        printf("%d %d %d\n", codCliente_no(removido), qntOp_no(removido), saldo_no(removido));
        free(removido);
    }
    printf("-+- Fim relatorio -+-\n");
}

int main(){
    int codCliente, op, valor, nivel;
    char operacao, c;
    arv* T = create_tree();

    while(1 != 2){
        scanf("%c", &operacao);
        if(operacao == 'i'){
            scanf(" %d %d %d", &codCliente, &op, &valor);
            insere(T, codCliente, op, valor);
        }
        else if(operacao == 'c'){
            scanf("%d", &codCliente);
            consulta(T, codCliente);
        }
        else if(operacao == 'r'){
            scanf("%d", &codCliente);
            remove_no(T, codCliente);
        }
        else if(operacao == 'p'){
            scanf(" %c", &c);
            if(c == 'c') imprime_AVL_crescente(raiz(T));
            else imprime_AVL_decrescente(raiz(T));
        }
        else if(operacao == 'n'){
            scanf("%d", &nivel);
            imprime_nivel(T, nivel);
        }
        else if(operacao == 'h') {
            printf("%d\n", altura_no(raiz(T)));
        }
        else if(operacao == 'f'){
            relatorio_final(T);
            free(T);
            break;
        }
    }
    return 0;
}