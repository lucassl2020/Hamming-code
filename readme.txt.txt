O hamming.c contém os 2 programas integrados.

Como compilar
	hamming.c
		gcc -c hamming.c listabit.c lerPalavra.c
		gcc -o main hamming.o listabit.o lerPalavra.o -lm

Para executar
	Use o terminal para ir até o diretorio do arquivo 
	E digite ./nome_do_executavel ou sudo chmod 777 nome do arquivo
	Por exemplo: 
		./main ou sudo chmod 777 main

Quando executado, será mostrado um menu.

O menu do gerador dará as opções de gerar ou digitar a palavra que será usada. A partir dela será gerado o código.

O menu do avaliador dará as opções de avaliar com e sem erro, mostrar palavra e mostrar codigo. 
Avaliar com erro, faz com que seja inserido um erro em alguma posição aleatória do codigo de hamming antes da avaliação.
