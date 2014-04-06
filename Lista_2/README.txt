
COMPILACAO
=================

Existem um makefile para realizar toda a compilacao, sendo assim para executar a compilacao deve-se usar o comando:

$ make

Para apagar o arquivo prog gerado pode-se utilizar o comando:
$ make clean

EXECUCAO
=================

Para executar o progama em um arquivo deve-se somente utilizar a linha de comando:

$ ./prog <nome_do_arquivo>


FORMATO DE ARQUIVO
================
O arquivo tem que esta no seguinte formato:

#capturar pontos:

<dot>	 <x>		<y>		 <z>
  d		  1		   2		-1.5

#capturar linhas(vertices):  

<line>	<dot1>	<dot2>	<red>	<green>	<blue>
	l	  		1				2				1			0				 1

#capturar triangulo:

<triangle>	<dot1>	<dot2>	<dot3>	<red>	<green>	<blue>
		t					 1			 3			2				1			 0		 	1

#capturar	quadrilatero:

<quad>	<dot1>	<dot2>	<dot3>	<dot4>	<red>	<green>	<blue>
	q	 			5 		  2			   3		  4 			1			 0			 1


#Exemplo 1 - Criar piramide usando linhas:

d		1			2		-1.5
d	-0.5	-0.5		2	
d	-0.8	 0.5	-0.5
d		2		-0.5		2
d		3		 0.5	 -2
l		1				2			1	0	1
l		1				3			1	1	0
l		1				4			0	1	1
l		1				5			1	0	0	
l		2				3			0	0	1
l		2				4			0.5	1	0
l		3				5			1	1	1
l		4				5			0	1	0


#Exemplo 2 - Criar piramide usando poligonos (triangulos e um quadrilatero):

d		1			2		-1.5
d	-0.5	-0.5		2	
d	-0.8	 0.5	-0.5
d		2		-0.5		2
d		3		 0.5	 -2	 
q	 5 		 2			3		4		1	0	1
t	 1		 3			2				1	0	1
t	 1		 2			4				1	0	1
t	 1		 2			3				1	1	0
t	 1		 4			5				1	0	0	



