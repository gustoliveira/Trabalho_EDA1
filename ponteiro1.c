#include <stdio.h>

int main (){
    int x;
    x = 10;

//Declaração de um ponteiro
    int *pont1;
//Fazer ponteiro apontar para o ender de mem da variável x
    pont1 = &x;

//Isso irá mostrar o conteudo do endereço
    printf("CASO 1:\n");
    printf("Mostrando o conteudo: %d %d\n", *pont1, x);
//Isso irá mostrar o endereço de memória
    printf("Mostrando o endereço: %d %d\n", pont1, &x);

//pont2 aponta para ender de y e depois pega o conteudo de z e joga
//para ender de y, logo, y == z
    int y = 20, z = 30;
    int *pont2;
    pont2 = &y;
    *pont2 = z;
    printf("CASO 2:\nMexendo no conteudo do ponteiro e alterando o valor da variável a qual ele está ligado\n");
    printf("%d %d\n", y, z);

//Atribuir NULL à um ponteiro faz com que ele não aponte para nada
    printf("CASO 3:\nFazendo ponteiro não apontar para nada\n");
    pont2 = NULL;
    printf("Endereço do ponteiro depois de NULL: %d\n", pont2);

    return 0;
}
