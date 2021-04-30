#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listabit.h"
#include "lerPalavra.h"

#define TRUE 1
#define FALSE 0

#define GERAR_PALAVRA 1
#define DIGITAR_PALAVRA 2
#define SAIR 0

#define AVALIAR_CODIGO 1
#define MOSTRAR_PALAVRA 2
#define MOSTRAR_CODIGO 3
#define VOLTAR 4


// Fazer loop pra corrigir todos os erros com hamming

/*
O GERADOR DO CÓDIGO TEM QUE SER CAPAZ DE PEGAR UMA PALAVRA
BINÁRIA E GERAR A CODIFICAÇÃO DE HAMMING PARA TRANSMISSÃO DA
REFERIDA PALAVRA.
*/

int primeiro_menu();
listaBits *gerar_palavra(listaBits *dado_enviado);
listaBits *digitar_palavra(listaBits *dado_enviado);

listaBits *gerar_codigo(listaBits *dado_enviado);

int segundo_menu();



int main(){

	listaBits *dado_enviado = criar_listaBits(),
			  *codigo_hamming = criar_listaBits();

	int opcao;


	while(TRUE){

		opcao = primeiro_menu();

		if(opcao == SAIR){

			break;	

		}else if(opcao == GERAR_PALAVRA || opcao == DIGITAR_PALAVRA){

			if(opcao == GERAR_PALAVRA){

				dado_enviado = gerar_palavra(dado_enviado);

			}else if(opcao == DIGITAR_PALAVRA){

				dado_enviado = digitar_palavra(dado_enviado);

			}

			desalocar_listaBits(codigo_hamming);
			codigo_hamming = gerar_codigo(dado_enviado);
			printf("CODIGO HAMMING GERADO: ");
			print_listaBits(codigo_hamming);


			while(TRUE){

				opcao = segundo_menu();

				if(opcao == AVALIAR_CODIGO){
					
				}else if(opcao == MOSTRAR_PALAVRA){

					printf("Palavra: ");
					print_listaBits(dado_enviado);

				}else if(opcao == MOSTRAR_CODIGO){

					printf("Codigo Hamming: ");
					print_listaBits(codigo_hamming);
					
				}else if(opcao == VOLTAR){

					break;

				}

			}

		}

	}

	
	desalocar_listaBits(dado_enviado);
	desalocar_listaBits(codigo_hamming);

	return 0;
}


int primeiro_menu(){

	int opcao;

	printf("=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("1 - Gerar palavra\n");
	printf("2 - Digitar palavra\n");
	printf("0 - Sair\n");
	printf("\n");
	printf("Opcao: "); scanf(" %d", &opcao);
	printf("\n");

	return opcao;

}

listaBits *gerar_palavra(listaBits *dado_enviado){

	int i, qtd_bits;

	desalocar_listaBits(dado_enviado);
			
	dado_enviado = criar_listaBits();


	printf("Quantidade de bits(4-256): "); scanf(" %d", &qtd_bits);
	while(qtd_bits < 4 || 256 < qtd_bits){
		printf("Fora do intervalo\nDigite um numero de 4 a 256: "); scanf(" %d", &qtd_bits);
	}
			
	for(i=0; i<qtd_bits; i++){
		dado_enviado = adicionar_bit(dado_enviado, rand()%2);
	}


	printf("\n");

	return dado_enviado;

}

listaBits *digitar_palavra(listaBits *dado_enviado){

	int i;
	char *palavra_enviada = NULL;

	desalocar_listaBits(dado_enviado);
			
	dado_enviado = criar_listaBits();

	
	palavra_enviada = processo_leitura_palavra("Palavra que sera enviada(Ex: 1010011): ", "Palavra invalida, digite novamente: ");
	while(tamanho_palavra(palavra_enviada) < 4 || 256 < tamanho_palavra(palavra_enviada)){
		palavra_enviada = processo_leitura_palavra("Tamanho invalido\nDigite a palavra novamente: ", "Palavra invalida, digite novamente: ");
	}

	for(i=0; palavra_enviada[i]!=0; i++){
		dado_enviado = adicionar_bit(dado_enviado, converte_char_para_bit(palavra_enviada[i]));
	}


	free(palavra_enviada);

	printf("\n");


	return dado_enviado;

}

int segundo_menu(){

	int opcao;

	printf("=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("1 - Avaliar codigo\n");
	printf("2 - Mostrar palavra\n");
	printf("3 - Mostrar codigo\n");
	printf("4 - Voltar\n");
	printf("\n");
	printf("Opcao: "); scanf(" %d", &opcao);
	printf("\n");

	return opcao;

}

listaBits *gerar_codigo(listaBits *dado_enviado){

	int indice = 1,
		expoente = 0;

	listaBits *codigo_hamming = criar_listaBits();

	while(dado_enviado != NULL){

		if(indice == pow(2, expoente)){
			codigo_hamming = adicionar_bit(codigo_hamming, 2);
			expoente++;
		}else{
			codigo_hamming = adicionar_bit(codigo_hamming, dado_enviado->bit);
			dado_enviado = dado_enviado->prox;
		}

		indice++;

	}

	return codigo_hamming;

}
