#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int bit;
}listaBits;

int main(){

	int qtd_bits;
	listaBits *lista = criar_listaBits();

	printf("Quantidade de bits (4-256): "); scanf(" %d", &qtd_bits);
	while(qtd_bits < 4 || qtd_bits > 256){
		printf("Digite um número no intervalo de 4 a 256: "); scanf(" %d", &qtd_bits);
	}


	return 0;
}

listaBits *criar_listaBits(){

	return NULL;
}

listaBits *adicionar_bit(listaBits * lista){


}