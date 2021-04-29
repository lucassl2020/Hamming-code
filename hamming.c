#include <stdio.h>
#include <stdlib.h>
#include "listabit.h"
#include "lerPalavra.h"

#define TRUE 1
#define FALSE 0

#define GERAR_PALAVRA 1
#define DIGITAR_PALAVRA 2
#define GERAR_CODIGO 3
#define AVALIAR_CODIGO 4
#define MOSTRAR_PALAVRA 5
#define MOSTRAR_CODIGO 6
#define SAIR 0

// Fazer loop pra corrigir todos os erros com hamming

/*
O GERADOR DO CÓDIGO TEM QUE SER CAPAZ DE PEGAR UMA PALAVRA
BINÁRIA E GERAR A CODIFICAÇÃO DE HAMMING PARA TRANSMISSÃO DA
REFERIDA PALAVRA.
*/

int menu_opcoes();


int main(){

	char *palavra_enviada = NULL;

	listaBits *dado_enviado = criar_listaBits();

	int i, qtd_bits, opcao;


	while(TRUE){

		opcao = menu_opcoes();

		if(opcao == SAIR){

			break;	

		}else{

			if(opcao == GERAR_PALAVRA){

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

			}else if(opcao == DIGITAR_PALAVRA){

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
				
			}else if(opcao == GERAR_CODIGO){
				
			}else if(opcao == AVALIAR_CODIGO){
				
			}else if(opcao == MOSTRAR_PALAVRA){

				printf("Palavra atual: ");
				print_listaBits(dado_enviado);

			}else if(opcao == MOSTRAR_CODIGO){
				
			}

		}

	}
	

	desalocar_listaBits(dado_enviado);

	return 0;
}


int menu_opcoes(){

	int opcao;

	printf("=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("1 - Gerar palavra\n");
	printf("2 - Digitar palavra\n");
	printf("3 - Gerar codigo hamming\n");
	printf("4 - Avaliar codigo hamming\n");
	printf("5 - Mostrar palavra atual\n");
	printf("6 - Mostrar codigo hamming atual\n");
	printf("0 - Sair\n");
	printf("\n");
	printf("Opcao: "); scanf(" %d", &opcao);
	printf("\n");

	return opcao;

}
