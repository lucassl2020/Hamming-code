#ifndef LER_PALAVRA_H
#define LER_PALAVRA_H

#define TRUE 1
#define FALSE 0

char *ler_palavra(const char *msg);
int palavra_invalida(char *palavra);
char *processo_leitura_palavra(const char *msg1, const char *msg2);
int converte_char_para_bit(char caracter);
int tamanho_palavra(char *palavra);

#endif