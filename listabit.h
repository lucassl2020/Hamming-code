#ifndef LISTABIT_H
#define LISTABIT_H


struct indice_binario_invertido{
	int *vetor;
	int tamanho;
};

struct lista_bits{
	int bit;
	int tem_erro;
	struct indice_binario_invertido indice_binario_inv;
	struct lista_bits *prox;
};


typedef struct indice_binario_invertido indiceBinInv;
typedef struct lista_bits listaBits;

indiceBinInv decimal_para_binario_inv(int numero);

listaBits *criar_listaBits();
listaBits *adicionar_bit(listaBits * lista, int bit);
int tamanho_listaBits(listaBits * lista);
void desalocar_listaBits(listaBits * lista);
void print_listaBits(listaBits * lista);


#endif