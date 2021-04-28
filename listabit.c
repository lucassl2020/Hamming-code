#include <stdio.h>
#include <stdlib.h>
#include "listabit.h"

listaBits *criar_listaBits(){

	return NULL;

}

listaBits *adicionar_bit(listaBits * lista, int bit){

	listaBits *aux;

	if(lista == NULL){
		lista = (listaBits *)malloc(sizeof(listaBits));

		lista->bit = bit;
		lista->prox = NULL;
	}else{
		aux = lista;

		while(aux->prox != NULL){
			aux = aux->prox;
		}

		aux->prox = (listaBits *)malloc(sizeof(listaBits));

		aux->prox->bit = bit;
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
		if(lista->prox != NULL)
			desalocar_listaBits(lista->prox);
			
		free(lista);
	}

}

void print_listaBits(listaBits * lista){

	if(lista != NULL){
		while(lista->prox != NULL){
			printf("%d ", lista->bit);
			lista = lista->prox;
		}

		printf("%d\n", lista->bit);
	}

}
