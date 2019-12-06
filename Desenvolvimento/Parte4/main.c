//Gustavo de Oliveira Ferreira
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){
    printf("Debug");
    arvore *arv = create_tree();
    int vetor[8] = {5, 4, 7, 20, 14, 19, 21, 16};
    no *a0 = create_no(vetor[0], 500);
    no *a1 = create_no(vetor[1], 500);
    no *a2 = create_no(vetor[2], 500);
    no *a3 = create_no(vetor[3], 600);
    no *a4 = create_no(vetor[4], 30);
    no *a5 = create_no(vetor[5], 9);
    no *a6 = create_no(vetor[6], 30);
    no *a7 = create_no(vetor[7], 1);

    insereAVL(arv, raiz(arv), a0);
    insereAVL(arv, raiz(arv), a1);
    insereAVL(arv, raiz(arv), a2);
    insereAVL(arv, raiz(arv), a3);
    insereAVL(arv, raiz(arv), a4);
    insereAVL(arv, raiz(arv), a5);
    insereAVL(arv, raiz(arv), a6);
    insereAVL(arv, raiz(arv), a7);

    printf("\nInOrdem: ");
    InOrdem(raiz(arv));
    return 0;
}

// no *insere_no(arvore *arv, unsigned long int codCliente, int opCliente, long int valor){
//     no *n = search_cod(raiz(arv), codCliente);
//     if(search(raiz(arv), n) != NULL){
//         alterar_saldo(n, opCliente, valor);
//     }
//     else{
//         n = create_no(codCliente, valor);
//         alterar_saldo(n, opCliente, valor);
//     }
//     return n;
// }

// long int alterar_saldo(no *aux, int opCliente, long int valor){
//     if(opCliente == 1) {
//         saldo_sub(aux, valor);
//     }
//     else{
//         saldo_add(aux, valor);
//     }

// }

// void consulta_no(unsigned long int codCliente, arvore *arv){
//     no *aux = search_cod(raiz(arv), codCliente);
//     if(aux == NULL){
//         printf("nao existe no com chave: %lu", codCliente);
//     }
//     else{
//         printf("existe no com chave: %lu", codCliente);
//     }
// }

// //COMPLETAR
// void relatorio(arvore *arv){
//     prinf("-+- Inicio Relatorio -+-");
//     unsigned long int n = size(arv);
//     for(unsigned long int i = 0; i < n; i++){
//         printf("");
//     }
//     prinf("-+- Fim Relatorio -+-");
// }

// //COLOCAR PARA REMOVER AVL
// no *remove_no(arvore *arv, unsigned long int codCliente){
//     no *n = search_cod(arv, codCliente);
//     remover_abb(arv, n);
//     return n;
// }

// int main(){
//     char operacao, listagemOrdem;
//     unsigned long int codCliente, nivel;
//     long int valor;
//     int opCliente;

//     arvore *arv = create_tree();

//     while(1==1){
//         scanf("%c", &operacao);
//         if(operacao == 'i'){
//             scanf("%lu %d %ld", &codCliente, &opCliente, &valor);
//             insere_no(arv, codCliente, opCliente, valor);
//         }
//         else if(operacao == 'c'){
//             consulta_no(codCliente, arv);
//         }
//         else if(operacao == 'r'){
//             no *n = remove_no(arv, codCliente);
//             free(n);
//         }
//         else if(operacao == 'p'){
//             scanf("%c", &listagemOrdem);
//             if(listagemOrdem == 'c') {
//                 imprime_AVL_crescente(raiz(arv));
//             }
//             else{
//                 imprime_AVL_decrescente(raiz(arv));
//             }
//         }
//         else if(operacao == 'n'){
//             scanf("%lu", &nivel);
//             /////////////////////////////////////
//         }
//         else if(operacao == 'h'){
//             printf("%lu", altura(raiz(arv)));
//         }
//         else if(operacao == 'f'){

//         }
//     }

//     return 0;
// }