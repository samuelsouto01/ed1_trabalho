#ifndef FILA_H_
#define FILA_H_

#include <stdio.h>
#include <stdlib.h>

// estrutura para um Nó
typedef struct no{
  int info;
  struct no *prox;
}no;

// estrutura para uma fila
typedef struct fila{
  no *L;
  int card;
}fila;

// função que cria uma fila
fila* criaFila();

// função que destroi uma fila
void desalocaFila(fila *F);

//função que insere em uma fila
void insereFila(fila *F, int );

// função que retira de uma fila
int retiraFila(fila *F);

//função que imprime fila
void imprimeFila(fila *F);

//função que verifica se uma fila esta vazia
int verificaFila(fila *F);

//função que verifica a quantidade de elementos em uma fila
int  cardinaFila(fila *F);

#endif
