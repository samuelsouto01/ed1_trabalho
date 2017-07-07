#include "LSE.h"

Cell* aloca(Cell *L){
	L = (Cell*) malloc (sizeof(Cell));
	L = NULL;
	return L;
}

Cell* desaloca(Cell *L){
	Cell *aux;
	while(!fimDaLista(L)){
		aux = L;
		L = L->prox;
		free(aux);
	}
	return NULL;
}

Cell* insereNoTop(Cell *L, int num){
	Cell *aux;
	aux = (Cell*) malloc(sizeof(Cell));
	if(fimDaLista(L)){
		L = aux;
		aux->prox = NULL;
		aux->info = num;
	}
	else{
		aux->prox = L;
		L = aux;
		aux->info = num;
	}
	return L;
}

Cell* insereNoFim(Cell *L, int num){
	Cell *novo, *aux;
	novo = (Cell*) malloc(sizeof(Cell));
	if(fimDaLista(L)){
		L = insereNoTop(L, num);
		return L;
	}
	else {
		aux = L;
		while (!proximoNull(L)) L = L->prox;
		L->prox = novo;
		novo->prox = NULL;
		novo->info = num;
		return aux;
	}
}

void imprime(Cell *L){
	if(fimDaLista(L)) printf("\n A lista esta vazia\n");
	else {
		while(!fimDaLista(L)){
			printf("%d\n", L->info);
			L = L->prox;
		}
	}
}

Cell* concatena(Cell *L1, Cell *L2){
	Cell *top = L1;
	while(!proximoNull(L1)) L1 = L1->prox;
	L1->prox = L2;
	return top;
}

Cell* busca(Cell* L, int num){
	if(!fimDaLista(L)){
		while(!fimDaLista(L)){
			if(L->info == num) return L;
			L = L->prox;
		}
		return NULL;
	}
	return NULL;
}

Cell* removeNo(Cell **L, int num){
	Cell *aux, *ant = NULL, *aux1 = *L;
	if(fimDaLista(*L)){
		return NULL;
	}
	else{
		aux = busca(*L, num);
		if(!fimDaLista(aux)){
			// loop para saber onde se encontra o elemento no inicio ou no meio/fim
			while(!proximoNull(aux1)){
				if(ant == NULL){
					if(aux1->info == aux->info){
						break;
					}
					ant = aux1;
					aux1 = aux1->prox;
				}
				if(aux1->info == aux->info){
					break;
				}
				ant = aux1;
				aux1 = aux1->prox;
			}
			// despredimento do no
			if(ant == NULL){
				*L = aux->prox;
				aux->prox = NULL;
				return aux;
			}
			ant->prox = aux->prox;
			aux->prox = NULL;
			return aux;
		}
		return NULL;
	}
}

Cell* insereOrd(Cell *L, int num){
	Cell *aux = L, *ant = NULL, *novo;
	novo = (Cell*) malloc(sizeof(Cell));
	if(fimDaLista(L)){
		novo->prox = NULL;
		novo->info = num;
		return novo;
	}
	while(!fimDaLista(aux)){
		if(num < aux->info ) break;
		ant = aux;
		aux = aux->prox;
	}
	if(aux != NULL){
		if(ant == NULL){
			novo->prox = L;
			novo->info = num;
			return novo;
		}
		ant->prox = novo;
		novo->prox = aux;
		novo->info = num;
		return L;
	}
	ant->prox = novo;
	novo->prox = NULL;
	novo->info = num;
	return L;
}
