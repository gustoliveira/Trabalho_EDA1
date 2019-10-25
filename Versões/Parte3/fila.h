#ifndef FILA_H
#define FILA_H

typedef struct fila fila;
typedef struct no no;

unsigned long int inicio_f(fila *f);
unsigned long int fim_f(fila *f);
unsigned long int qtd_f(fila *f);
unsigned long int tam_f(fila *f);
no** vetor_f(fila *f);
unsigned long int cpf_f(no *n);
unsigned long int cpft_f(no *n);
long int valor_f(no *n);
char op_f(no *n);
no *prox_f(no *n);

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
