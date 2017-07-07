#include "fila.h"

// função que cria uma fila
fila* criaFila(){
  fila *F = (fila*) calloc(1, sizeof(fila));
  return F;
}

// função que destroi uma fila
void desalocaFila(fila *F){
  no *aux;
  if(F == NULL) printf ("\n A fila ja esta desalocada\n");
  else{
    if(F->card == 0){
      free(F);
      return;
    }
    aux = F->L;
    while(F->card != 0){
      F->card--;
      F->L = F->L->prox;
      free(aux);
      aux = F->L;
    }
  }
}

//função que insere em uma fila
void insereFila(fila *F, int n){
  no *aux = (no*) calloc(1,sizeof(no));
  no *aux1;
  if(F == NULL || aux == NULL){
    printf("\n ERRO\n Falta de Memoria\n");
    return;
  }
  aux->info = n;
  F->card++;
  if(F->L == NULL){
    F->L = aux;
    return;
  }
  aux1 = F->L;
  while(aux1->prox != NULL){
    aux1 = aux1->prox;
  }
  aux1->prox = aux;
}

// função que retira de uma fila
int retiraFila(fila *F){
  int n;
  no *aux;
  if(F == NULL){
    printf("\n ERRO\n Falta de Memoria\n");
    return -1;
  }
  else if(F->L == NULL){
    printf("\n ERRO\n fila vazia");
    return 0;
  }
  aux = F->L;
  n = aux->info;
  if(F->card == 1){
    F->L = NULL;
    F->card = 0;
    free(aux);
    return n;
  }
  aux->prox = NULL;
  F->L = F->L->prox;
  free(aux);
}

//função que imprime fila
void imprimeFila(fila *F){
  if(F == NULL){
    printf("\n ERRO\n Falta de Memoria\n");
    return;
  }
  else if(F->L == NULL){
    printf("\n ERRO\n A fila esta vazia\n");
    return;
  }
  printf("\n");
  no *aux= F->L;
  while(aux != NULL){
    printf("%d\n",aux->info);
    aux = aux->prox;
  }
}

//função que verifica se uma fila esta vazia
int verificaFila(fila *F){
  if(F == NULL){
    printf("\n ERRO\n Falta de Memoria\n");
    return -1;
  }
  if(F->card == 0) return 1;
  return 0;
}

//função que verifica a quantidade de elementos em uma fila
int  cardinaFila(fila *F){
  if(F == NULL){
    printf("\n ERRO\n Falta de Memoria");
    return -1;
  }
  else if(F->L == NULL) return 0;
  return F->card;
}
