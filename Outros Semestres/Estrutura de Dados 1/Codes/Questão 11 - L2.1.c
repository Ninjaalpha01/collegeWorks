#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int igual(char *str1, char *str2);

void main()
{
	const n=15;
	char s1[n], s2[n];
	
	printf("Insira:\n");
	printf("string 1: ");
	fgets(s1,n,stdin);
	printf("string 2: ");
	fgets(s2,n,stdin);
	
	int qnt;
	
	qnt = igual(s1,s2);
	
	printf("Existem %d caracteres iguais!\n", qnt);
}

int igual(char *str1, char *str2)
{
	int x=0, i, n1, n2;
	
	n1 = strlen(str1)-1;
	n2 = strlen(str2)-1;
	
	for (i=0; i<n1 || i<n2; i++)
		if(*(str1+i) == *(str2+i))
			x++;
	
	return x;
}
