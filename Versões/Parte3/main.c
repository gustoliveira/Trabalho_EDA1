/*
Gustavo de Oliveira Ferreira
João Lucas Lima de Melo
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "no.h"
#include "lista.h"
#include "fila.h"
#include "pilha.h"

//Função que opera sobre o nó referente para depositar valor na conta, além de atualizar a quantidade de operações realizadas
void deposit(nol* cliente1, nol* cliente2, long int valor){
  saldo_l_add(cliente2, valor);
  ops_l_add(cliente2);
  ops_l_add(cliente1);
}

//Função que opera sobre o nó referente para retirar valor da conta, além de atualizar a quantidade de operações realizadas
void saque(nol* cliente, long int valor){
  saldo_l_sub(cliente, valor);
  ops_l_add(cliente);
}

//Função que opera sobre o nó referente para transferir valor de uma conta para outra, além de atualizar a quantidade de operações realizadas
void transfer(nol* cliente1, nol* cliente2, long int valor){
  saldo_l_sub(cliente1, valor);
  saldo_l_add(cliente2, valor);
  ops_l_add(cliente2);
  ops_l_add(cliente1);
}

//Função para enviar cliente para atendimento
void attendance(unsigned long int ordem, no* cliente, pilha** vetor, int qt_guiche){
  int guiche = ordem%qt_guiche; //Cálculo do guiche para qual o cliente irá
  push_p(vetor[guiche], cliente);
}

//Função para atualizar/criar registros para lista do relatório final
void update_frelat(lista*l, no* cliente){
  if(op_p(cliente) != 'S'){
      //Procura pela existência de CPF ou CPFT na lista, e adiciona-os caso não existam
      if(search_l(l,cpf_p(cliente)) == NULL) push_l(l,create_nol(cpf_p(cliente)));
      if(search_l(l,cpft_p(cliente)) == NULL) push_l(l,create_nol(cpft_p(cliente)));
      //Realiza as operações sobre os nós da lista
      switch(op_p(cliente)){
        case 'D' : deposit(search_l(l,cpf_p(cliente)),search_l(l,cpft_p(cliente)),valor_p(cliente));
        break;
        case 'T': transfer(search_l(l,cpf_p(cliente)),search_l(l,cpft_p(cliente)),valor_p(cliente));
        break;
      }
  }
  else{
      //Procura pela existência de CPF na lista, e adiciona-o caso não exista
      if(search_l(l,cpf_p(cliente)) == NULL) push_l(l,create_nol(cpf_p(cliente)));
      saque(search_l(l,cpf_p(cliente)), valor_p(cliente));
  }
}

//Exibe as informações referente a pilha desejada, retirando o topo, lendo-o e adicionando à uma fila auxiliar, depois a pilha original retorna a
//seu estado inicial (Além disso enquanto exibe atualiza o relatório final)
void show_p(pilha *p, lista* l){
	if(isEmpty_p(p) == 0){
		pilha* paux = create_p();
		while(isEmpty_p(p)!=1){
			no* aux = pop_p(p);
			printf("[%lu,%lu,%c,%lu]\n",cpf_p(aux),cpft_p(aux),op_p(aux),valor_p(aux));
			update_frelat(l,aux);
			push_p(paux,aux);
		}
		while(isEmpty_p(paux) != 1) {
			push_p(p,pop_p(paux));
		}
		free(paux);
	}
}

//Função para gerar/exibir relatório parcial e atualizar relatório final
void show_relat_diario(pilha** vetor, unsigned long int qt_guiche, lista* l, int i){
  	//Formatação da saída, utilização da função de exibição para exibir todos os dados de determinada pilha
  	printf("-:| RELATÓRIO DIARIO %d |:-\n%lu\n", i+1, qt_guiche);
    for(unsigned long int j = 0; j < qt_guiche; j++){
		// if(isEmpty_f(f) != 1){
    		printf("Guiche %ld: %lu\n", j+1, cont_p(vetor[j]));
    		show_p(vetor[j], l);
		// }
		// else{
			// printf("Guiche %ld: 0\n", j+1);
		// }
    }
}

//Função para exibir relatório final
void show_relat_final(lista* l){
  //Formatação da saída, utilização da função de exibição para exibir todos os dados de determinada lista
  printf("\n-:| RELATÓRIO FINAL |:-\n %lu\n", cont_l(l));
    nol* aux = lPrimeiro(l);
    while(aux!=NULL){
      printf("-:[ %lu : %lu %li\n", cpf_l(aux),ops_l(aux),saldo_l(aux));
      aux = prox_l(aux);
    }
}

//Cria e inicializa vetor de pilhas para funcionarem como guichê
pilha** create_vet_p(unsigned long int qt_guiches){
  pilha **vetor_pilhas = (pilha**) malloc(sizeof(pilha*)*qt_guiches);
  if(vetor_pilhas != NULL){
    for(unsigned long int i =0; i < qt_guiches; i++){
      vetor_pilhas[i] = create_p();
    }
    return vetor_pilhas;
  }
  else return NULL;
}

int main(){
    // int qt_guiches = 3; //Quantidade de guichês que serão disponibilizados para atendimento.
	unsigned long int m, n, d, cpf, cpft, valor;
    char op;
    scanf("%lu %lu %lu", &n, &m, &d); // Entrada de N

    fila* f = create_f(n); //Cria fila com tamanho máximo igual à quantidade de inserts
    //Criação do cliente integrado à inserção na fila de atendimento
    for(unsigned long int i = 0; i < n; i++){
    	scanf("%lu %lu %c %lu", &cpf, &cpft, &op, &valor);
    	no* cliente = create_n(cpf, cpft, op, valor);
    	push_f(f, cliente); //Envia clientes para fila de espera
    }

	unsigned long int tam = tam_f(f);
	printf("%lu\n", tam);

    lista* l = create_l(); //Criação da lista para relatório final

	for(int i = 0; isEmpty_f(f) == 0; i++){
	    pilha **vetor_pilhas = create_vet_p(m); //Vetor de ponteiros para pilhas (guiches)
		for(unsigned long int k = 0; k < d; k++){
			no* aux = pop_f(f); //Pega primeiro elemento da fila
			attendance(k, aux, vetor_pilhas, m); //Envia primeiro elemento da fila para atendimento
			if(isEmpty_f(f) == 1) break;
		}
		show_relat_diario(vetor_pilhas, m, l, i);
    	free(vetor_pilhas);
	}

    //Chamada para a função de exibição do relatório Final
    show_relat_final(l);

    destroy_f(f);
    destroy_l(l);

}
