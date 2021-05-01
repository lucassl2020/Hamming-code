#include <stdio.h>
#include <stdlib.h>
#include "listabit.h"

#define PRIMEIRO_INDICE 1


int *decimal_para_binario_inv(int numero){

	int *vetor = (int *)malloc(sizeof(int)),
		i = 0; 

	vetor[i++] = numero % 2;

	while(numero > 1){
		numero /= 2;
		vetor = (int *)realloc(vetor, sizeof(int) * (i + 1));
		vetor[i++] = numero % 2;
	}

	return vetor;

}


listaBits *criar_listaBits(){

	return NULL;

}

listaBits *adicionar_bit(listaBits * lista, int bit){

	listaBits *aux;
	int indice = PRIMEIRO_INDICE;

	if(lista == NULL){
		lista = (listaBits *)malloc(sizeof(listaBits));

		lista->bit = bit;
		lista->indice_binario_inv = decimal_para_binario_inv(indice);
		lista->prox = NULL;
	}else{
		aux = lista;

		while(aux->prox != NULL){
			aux = aux->prox;
			indice++;
		}

		aux->prox = (listaBits *)malloc(sizeof(listaBits));

		aux->prox->bit = bit;
		aux->prox->indice_binario_inv = decimal_para_binario_inv(++indice);
		aux->prox->prox = NULL;
	}

	return lista;

}

int tamanho_listaBits(listaBits * lista){

	int cont=0;

	while(lista != NULL){
		lista = lista->prox;
		cont++;
	}

	return cont;

}

void desalocar_listaBits(listaBits * lista){

	if(lista != NULL){
		desalocar_listaBits(lista->prox);
		free(lista->indice_binario_inv);
		free(lista);
	}

}

void print_listaBits(listaBits * lista){

	while(lista != NULL){
		printf("%d", lista->bit);
		lista = lista->prox;
	}

	printf("\n");

}
