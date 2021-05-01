#ifndef LISTABIT_H
#define LISTABIT_H


struct lista_bits{
	int bit;
	int *indice_binario_inv;
	struct lista_bits *prox;
};

typedef struct lista_bits listaBits;

int *decimal_para_binario_inv(int numero);

listaBits *criar_listaBits();
listaBits *adicionar_bit(listaBits * lista, int bit);
int tamanho_listaBits(listaBits * lista);
void desalocar_listaBits(listaBits * lista);
void print_listaBits(listaBits * lista);


#endif