#ifndef FILA_H
#define FILA_H

typedef struct fila fila;

struct fila{
	unsigned long int inicio,fim,qtd,tam;
	no** vetor;
};

no* create_n(unsigned long int cpf,unsigned long int cpft,char op, long int valor);
fila* create_f(unsigned long int tamanho);
int full_f(fila *f);
int isEmpty_f(fila *f);
void push_f(fila *f,no* x);
no* pop_f(fila *f);
no* front_f(fila*f);
unsigned long int size_f(fila* f);
no* search_f (fila* f,unsigned long int cpf);
void destroy_f(fila* f);


#endif // FILA_H