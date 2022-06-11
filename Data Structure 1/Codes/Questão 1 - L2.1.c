#include <stdio.h>
#include <stdlib.h>

/*a) Leitura ilegal
void main()
{
	int var=28;
	int *p=NULL;
	
	p = &var;
	
	printf("%X\n", p);
	printf("%d\n", *p);
	printf("ALTERACAO DE ENDERECO\n");
	p += 4;
	printf("%X\n", p);
	printf("%d", *p);
}*/

/*b) Escrita ilegal
void main()
{
	int var=100;
	int *p=NULL;
	
	p = &var;
	printf("%x\n", p);
	printf("%d\n", *p);
	printf("MUDANCA DE ENDERECO\n");
	p += 4;
	printf("%x\n", p);
	printf("%d \nInsira o valor: ", *p);
	scanf("%d", &*p);
	printf("VALOR DE MEMORIA MODIFICADO ILEGALMENTE\n");
	printf("%x\n", p);
	printf("%d\n", *p);
}*/

/*c) Falha de segmentação
void main()
{
	int *p=NULL;
	
	printf("%d", *p);
}*/

/*d) Vazamento de memória
int *vaza(int *x)
{
	int **p2=NULL;
	
	p2 = (int **) malloc(sizeof(int));
	p2 = &x;
	return *p2;
}

void main()
{
	int x=900;
	int *p;
	
	p = vaza(&x);
	
	printf("%d", *p);
}*/
