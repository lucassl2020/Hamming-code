#include <stdio.h>
#include <stdlib.h>
#include "listabit.h"

#define PRIMEIRO_INDICE 1
#define TRUE 1
#define FALSE 0


indiceBinInv decimal_para_binario_inv(int numero){

	indiceBinInv indice_bin_inv;
	int i = 0; 

	indice_bin_inv.vetor = (int *)malloc(sizeof(int));

	indice_bin_inv.vetor[i++] = numero % 2;

	while(numero > 1){
		numero /= 2;
		indice_bin_inv.vetor = (int *)realloc(indice_bin_inv.vetor, sizeof(int) * (i + 1));
		indice_bin_inv.vetor[i++] = numero % 2;
	}
	indice_bin_inv.tamanho = i;

	return indice_bin_inv;

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
		lista->tem_erro = FALSE;
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
		aux->prox->tem_erro = FALSE;
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
		free(lista->indice_binario_inv.vetor);
		free(lista);
	}

}

void print_listaBits(listaBits * lista){

	int i = 1;

	printf("\t[INDICE] - BIT\n\n");
	while(lista != NULL){
		printf("\t[%3d] - %d", i++, lista->bit);
		if(lista->tem_erro == TRUE){
			printf(" [BIT COM ERRO]");
		}
		printf("\n");
		lista = lista->prox;
	}

	printf("\n");

}
