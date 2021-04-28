#include <stdio.h>
#include <stdlib.h>
#include "listabit.h"

#define TRUE 1
#define FALSE 0

// Fazer loop pra corrigir todos os erros com hamming

void enter_para_fechar();
char *ler_palavra(const char *msg);
int palavra_invalida(char *palavra);
char *processo_leitura_palavra(const char *msg1, const char *msg2);
int palavras_tamanho_igual(char *palavra1, char *palavra2);
int converte_char_para_bit(char caracter);


int main(){

	char *palavra_enviada = NULL,
		 *palavra_recebida = NULL;
	listaBits *dado_enviado = criar_listaBits(),
			  *dado_recebido = criar_listaBits();
	int i;

	palavra_enviada = processo_leitura_palavra("Digite o dado enviado(Ex: 1010011): ", "Palavra invalida, digite novamente: ");

	palavra_recebida = processo_leitura_palavra("Digite o dado recebido(Ex: 1010011): ", "Palavra invalida, digite novamente: ");
	
	while(palavras_tamanho_igual(palavra_enviada, palavra_recebida) == FALSE){
		printf("Os dados possuem tamanhos diferentes\n");

		palavra_enviada = processo_leitura_palavra("Digite novamente o dado enviado: ", "Palavra invalida, digite novamente: ");

		palavra_recebida = processo_leitura_palavra("Digite novamente o dado recebido: ", "Palavra invalida, digite novamente: ");
	}

	for(i=0; palavra_enviada[i]!=0; i++){
		dado_enviado = adicionar_bit(dado_enviado, converte_char_para_bit(palavra_enviada[i]));
		dado_recebido = adicionar_bit(dado_recebido, converte_char_para_bit(palavra_recebida[i]));
	}

	print_listaBits(dado_enviado);
	print_listaBits(dado_recebido);


	free(palavra_enviada);
	free(palavra_recebida);
	desalocar_listaBits(dado_enviado);
	desalocar_listaBits(dado_recebido);

	enter_para_fechar();

	return 0;
}


void enter_para_fechar(){

	printf("Digite enter para fechar\n");
	setbuf(stdin, NULL);
	getchar();

}

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

int palavras_tamanho_igual(char *palavra1, char *palavra2){

	int i=0;
	while(palavra1[i] != 0 && palavra2[i] != 0){
		i++;
	}

	if(palavra1[i] == 0 && palavra2[i] == 0){
		return TRUE;
	}

	return FALSE;

}

int converte_char_para_bit(char caracter){

	if(caracter == '0')
		return 0;

	return 1;

}
