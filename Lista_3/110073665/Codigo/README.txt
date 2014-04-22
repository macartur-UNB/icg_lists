LISTA 3
==================================================
Aluno	Macártur de Sousa Carvalho	
			11/0073665

ARQUIVOS
==================================================
CG.h
CG.cpp
Makefile
main.cpp
vec.h
Mesh.h
Mesh.cpp
README.txt



COMPILACAO
=================

Existem um makefile para realizar toda a compilacao, sendo assim para executar a compilacao deve-se usar o comando no diretorio do Makefile:

$ make

Para apagar o arquivo prog gerado pode-se utilizar o comando:

$ make clean

EXECUCAO
=================

Para executar o progama em um arquivo deve-se somente utilizar a linha de comando:

$ ./prog <nome_do_arquivo_de_entrada> <tipo de renderização>

nome_do_arquivo_de_entrada = *.off
arquivos com extensão diferente de .off não será executado

tipo podendo ser:

line =    cria malha triangular usando linhas)
polygon = criar o objeto usando poligonos

Exemplo:  ./prog bun_zipper.off line
					ou
					./prog bun_zipper.off polygon

FORMATO DE ARQUIVO
================
O arquivo tem que esta no seguinte formato:

primeira linha contendo String com:
COFF: para capturar cor 
ou 
OFF : para não capturar cor

em seguida deve linha contendo:
<pontos> <faces> <textura>

Exemplo:
	1590  1800    0

*textura igual 0 quer dizer sem textura

Depois linhas contendo todos os pontos:
 < X > < Y > < Z > < RED > < BLUE > < GREEN > <ALPHA>

Exemplo:
	0  -0.3555 0.333 127  127  0	1

Em seguida linhas contendo as faces
 <tipo> <indice 1> <indice 2> <indice 3> <indice 4>

se tipo for igual a 3 será lido apenas os 3 primeiros indices
se tipo for igual a 4 será lido os quatro indices
