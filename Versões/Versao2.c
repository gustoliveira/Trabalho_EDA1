/*
Álvaro Souza Oliveira
Gustavo de Oliveira Ferreira
João Lucas Lima de Melo
Natan Santos Moura
 */
#include<stdio.h>
#include<stdlib.h>

//Definição do tipo pilha, fila, lista e nó
typedef struct fila fila;
typedef struct pilha pilha;
typedef struct lista lista;
typedef struct no no;


//Declaração do tipo nó
struct no{
    unsigned long int cpf,cpft,valor; //unsigned long int utilizado para suportar entrada <= 2^32-1
    char op;
    no* prox;
};

//Declaração do tipo pilha
struct pilha{
    no* topo;
    unsigned long int cont;
};

//Função para inicializar nó
no* create_n(unsigned long int cpf,unsigned long int cpft,unsigned long int valor,char op){
    no *n = (no*) malloc(sizeof(no));
    if(n!=NULL){
	    n->cpf = cpf;
	    n->cpft = cpft;
	    n->valor = valor;
	    n->op = op;
	    n->prox = NULL;
	    return n;
	}
	else return NULL;

}
//Função para inicializar pilha
pilha* create_p(){
    pilha *p = (pilha*) malloc(sizeof(pilha));
    if(p!=NULL){
	    p->topo = NULL;
	    p->cont = 0;
	    return p;
	}
	else return NULL;
}

//Função para empilhar elemento
void push_p(pilha *p, no *n){
    n->prox = p->topo;
    p->topo = n;
    p->cont++;
}

//Checa se a pilha está vazia, retorna "1" se sim e "0" caso contrário
int isEmpty_p(pilha *p){
    if(p->topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Desempilha elemento do topo da pilha referente, retorna NULL se pilha estiver vazia
no* pop_p(pilha *p){
	if(isEmpty_p(p) == 1){
        return NULL;
    }
    else{
        no* aux = p->topo;
        p->topo = aux->prox;
        aux->prox = NULL;
        p->cont--;
        return aux;
    }
}

//Remove a pilha e todos os dados referentes a ela
void destroy_p(pilha *p){
	while(1 == 1){
		if(isEmpty_p(p) == 1) break;
		free(pop_p(p)); //Libera o espaço de memória do Nó enquanto desempilha-o
	}
	free(p);
}

//Exibe as informações referente a pilha desejada
void show_p(pilha *p){
	if(isEmpty_p(p) == 0){
		no* aux = p->topo;	
		while(1==1){
			printf("[%lu, %lu, %c, %lu]\n",aux->cpf,aux->cpft,aux->op,aux->valor);
			aux = aux->prox;
			if(aux==NULL) break;
		}
	}
}

//Declaração do tipo fila
struct fila{
	unsigned long int inicio,fim,qtd,tam;
	unsigned long int* vetor;
};

//Função para inicializar fila
fila* create_f(unsigned long int tamanho){
	fila* f = (fila*) malloc(sizeof(fila));
 	if(f!=NULL){
 		f->inicio = 0;
 		f->fim = 0;
 		f->qtd = 0;
 		f->tam = tamanho;
 		f->vetor = (int*) malloc(sizeof(int)*f->tam);
 		if(f->vetor == NULL) return NULL;
 		else return f;
 	}
 	else return NULL;
}

int full_f(fila *f){
	if(f->qtd == f->tam) return 1;
	else return 0;
}

//Função para checar se a fila está vazia
int isEmpty_f(fila *f){
	if(f->qtd == 0) return 1;
	else return 0;
}

//Função para enfileirar elemento
void push_f(fila *f,no* x){
	if(full_f(f)==1) printf("FILA CHEIA!");
	else{
		f->fim = (f->fim+1)%f->tam;
		f->vetor[f->fim] = x;
		f->qtd++;
	}
}

//Função para desenfileirar primeiro elemento da fila 
no* pop_f(fila *f){
 
}

//Retorna cpf do primeiro elemento da fila
unsigned long int front_f(fila*f){

}

//Definição do tipo lista
struct lista{
    no* primeiro;
    int cont;
};

//Função para inicializar lista
lista* create_l(){
    lista* l = (lista*) malloc(sizeof(lista));
    if (l == NULL) return NULL;
    else{
        l->primeiro = NULL;
        l->cont=0;
        return l;   
    }
    
}

//Função para checar se lista está vazia
int isEmpty_l(lista* l){
    if (l->primeiro == NULL)
        return 1;
    else
        return 0;
}

//Função para buscar elemento na lista
no* search_l(lista* l,int k){
    no* aux = l->primeiro;
    while(aux != NULL){
        if(aux->cpf == k) return aux;
        aux = aux->prox;    
    }
    return NULL;
}

//Função para inserir elemento na lista 
void inserir_lista(lista* l, no* x){
  /* MUDAR PARA ORDENADA  if(lista_vazia(l)==1 || pos == 1){
        x->prox = l->primeiro;
        l->primeiro = x;    
    }
    else{
        int i = 1;
        no* aux = l->primeiro;
        while(i!=pos-1 && aux->prox!=NULL){
            aux = aux->prox;
            i++;    
        }
    x->prox = aux->prox;
    aux->prox = x;
    }*/
}

//Função para remover elemento da lista
no* pop_l(lista* l, no* k){
    if(l->primeiro == k)
        l->primeiro = l->primeiro->prox;
    else{
        no* x = l->primeiro;
        while(x->prox !=NULL){
            if(x->prox == k){
                x->prox = k->prox;
                break;          
            }
            else x = x->prox;
        }
    }
    k->prox = NULL;
    return k;
}

int main(){
    //Vetor de ponteiros para pilhas (guiche)
    pilha **vetor_pilhas = (pilha**) malloc(sizeof(pilha*)*3);
    //Preenchimento do vetor de ponteiros para pilhas
    for(int i =0; i<3;i++){
    	 vetor_pilhas[i] = create_p();
    }
	unsigned long int n, cpf, cpft, valor;
    char op;
    no *cliente = NULL; //Ponteiro auxiliar para manipular inserção de nós
    scanf("%lu",&n); // Entrada de N
    //Preenchimento do ponteiro auxiliar, criação do nó e associação à guiche referente
   /* for(unsigned long int i = 0; i<n;i++){
    	scanf("%lu %lu %c %lu", &cpf, &cpft, &op, &valor);
    	cliente = create_n(cpf, cpft, valor, op);
    	int guiche  = i%3;  //Cálculo do guiche para qual o cliente irá
    	push_p(vetor_pilhas[guiche],cliente);
    } ALTERAR PARA FUNÇÃO*/
    
    //Formatação da saída, utilização da função de exibição para exibir todos os dados de determinada pilha
    /*printf("-:| RELATÓRIO PARCIAL |:-\n3\n");
    for(int i =0; i<3;i++){
    	printf("Guiche %d: %lu\n",i+1,vetor_pilhas[i]->cont);
    	show_p(vetor_pilhas[i]);
    	destroy_p(vetor_pilhas[i]);
    } ALTERAR PARA FUNÇÃO*/
    free(vetor_pilhas);
}
