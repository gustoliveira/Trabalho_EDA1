#include <stdio.h>
//Biblioteca necessária para funções malloc, realloc, calloc, free
#include <stdlib.h>

int main(){
    int x;

//sizeof deste modo irá falar o tamanho que o tipo da variável que está
//dentro dos parenteses tem, ex: int tem tamanho 4, _Bool tem tamanho 1
    printf("%li\n", sizeof(x));

//malloc retorna um ponteiro tipo void (tem que fazer o casting), ele aloca
//uma quantidade de memória pedida
    int *pont1 = (int *) malloc(sizeof(int));


//calloc é a evolução de malloc, ele retorna um ponteiro de vezes multiplicadas
//o tamanho do tipo, equivalente a:
//      int *pont2 = (int *) malloc(sizeof(int)*m);
//mas, ele limpa todo o espaço alocado e atribui 0;
    int m = 10;
    int *pont2 = (int *) calloc(m, sizeof(int));

//realloc serve para alterar o tamanho do espaço alocado já alocado
//insere-se o ponteiro o qual o espaço que quer ser realocado aponta, e
//seu novo tamanho.
    int n = 20;
    pont2 = (int *) realloc(pont2, sizeof(int)*n);

//CUIDADO: pois caso não haja espaço, a função realloc irá retornar
//ponteiro NULL, para evitar problemas, usa-se esse artificio
    int *pont3 = (int *) calloc(m, sizeof(int));
    int *aux = (int *) realloc(pont3, sizeof(int)*n);
    if(aux != NULL) pont3 = aux;

//Após usar a memória e quiser liberar, para não encher a memória, usa-se free
//com o ponteiro da memória alocada para desalocar
    free(pont1);
    free(pont2);
    free(pont3);
//É de costume fazer ponteiros apontar para NULL depois de desalocar a memória
    pont1 = NULL;
    pont2 = NULL;
    pont3 = NULL;

    return 0;
}
