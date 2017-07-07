/*		BIBLIOTECA PARA LISTAS SIMPLESMENTE ENCADEADAS COM INTEIROS
	AUTOR:  SAMUEL SOUTO SILVEIRA
	DATA:   07/07/2017
	VERSÃO: 1.0
	E-MAIL: soutosamuel@hotmail.com
*/
#ifndef LSE_H_
#define LSE_H_

#include <stdlib.h>

// estrutura para um nó da lista
typedef struct no{
	int info;
	struct no *prox;
}Cell;

/* ------------------------------------------------------------------------------------------
função que aloca o começo de uma lista encadeada
entrada: ponteiro para lista
saida  : ponteiro para lista
*/
Cell* aloca(Cell *L);
/* ------------------------------------------------------------------------------------------
função que desaloca o começo de uma lista encadeada
entrada: ponteiro para lista
saida  : ponteiro para lista
*/
Cell* desaloca(Cell *L);
/* ------------------------------------------------------------------------------------------
função que insere no topo um numero
entrada: ponteiro para lista e inteiro a ser inserido
saida  : ponteiro para lista
*/
Cell* insereNoTop(Cell *L, int num);
/* ------------------------------------------------------------------------------------------
função que insere no final de uma lista encadeada
entrada: ponteiro para lista e inteiro a ser inserido
saida  : ponteiro para lista
*/
Cell* insereNoFim(Cell *L, int num);
/* ------------------------------------------------------------------------------------------
função que imprime uma lista encadeada
entrada: ponteiro para lista
saida  : void */
void imprime(Cell *L);
/* ------------------------------------------------------------------------------------------
função que concatena duas listas encadeadas
entrada: ponteiros para listas
saida  : ponteiro para lista
*/
Cell* concatena(Cell *L1, Cell *L2);
/* ------------------------------------------------------------------------------------------
funçaõ que busca um elemento em uma dada lista
entrada: ponteiro para lista e numero inteiro a ser verificado
saida  : ponteiro para lista
*/
Cell* busca(Cell* L, int num);
/* ------------------------------------------------------------------------------------------
função que retira um  elemento da lista
entrada: ponteiro de ponteiro para lista e inteiro a ser removido
saida  : ponteiro para o nó removido
*/
Cell* removeNo(Cell **L, int num);
/* ------------------------------------------------------------------------------------------
função que insere ordenadamente um  elemento em uma lista ordenada
entrada: ponteiro para lista e inteiro a ser inserido
saida  : ponteiro para lista
*/
Cell* insereOrd(Cell *L, int num);

#endif
