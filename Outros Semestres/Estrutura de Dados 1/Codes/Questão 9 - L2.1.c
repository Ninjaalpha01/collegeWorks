#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gabriel.c"

char *strcopy(char *str);

void main()
{
	char palavra[15], *p;
	
	printf("Insira a palavra: ");
	fgets(palavra,15,stdin);
	fflush(stdin);
	
	p = strcopy(palavra);
	
	printf("Copia: ");
	imprimechr(p);
	
	free(p);
}

char *strcopy(char *str)
{
	char *pont;
	int tam, i;
	
	tam = strlen(str)-1;
	pont = (char *)malloc(tam);
	
	if (pont == NULL)
		printf("SO nao liberou memoria!\n");
	
	for (i=0; i<tam; i++)
		*(pont+i) = *(str+i);
	
	return pont;
}
