#include <stdio.h>
#include <stdlib.h>
#include "lerPalavra.h"

#define TRUE 1
#define FALSE 0


char *ler_palavra(const char *msg){

	char *palavra = (char *)malloc(sizeof(char));
	int i=0;

	setbuf(stdin, NULL);

	printf("%s", msg);
	while((palavra[i] = getchar()) != '\n'){
		i++;
 		palavra = (char *)realloc(palavra, sizeof(char) * (i + 1));
	}
	palavra[i] = 0;

	return palavra;

}

int palavra_invalida(char *palavra){

	int i=0;

	while(palavra[i] != 0){
		if(palavra[i] != '0' && palavra[i] != '1'){
			return TRUE;
		}

		i++;
	}

	return FALSE;

}

char *processo_leitura_palavra(const char *msg1, const char *msg2){

	char *palavra = NULL;

	palavra = ler_palavra(msg1);

	while(palavra_invalida(palavra)){
		palavra = ler_palavra(msg2);
	}

	printf("\n");

	return palavra;

}

int converte_char_para_bit(char caracter){

	if(caracter == '0')
		return 0;

	return 1;

}

int tamanho_palavra(char *palavra){

	int cont = 0;

	while(palavra[cont] != 0){
		cont++;
	}

	return cont;

}
