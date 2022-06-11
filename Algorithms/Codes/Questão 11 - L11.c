#include <stdio.h>
#include <conio.h>
#include <string.h>

char inverter(char palavra[], int n, int m, char copia[]);
void copiar(char palavra[], char copia[], int n);

int main()
{
	int i, n, m=0, opc;
	char palavra[n], copia[n];
	
	system("cls");
	fflush(stdin);
	printf("Insira a palavra:\n");
	gets(palavra);
	
	for (i=0; palavra[i] != '\0'; i++)
		n++;
	copiar(palavra,copia,n-1);
	inverter(palavra,n-2,m,copia);
	printf("\n%s\n", palavra);
	
	return 0;
}

void copiar(char palavra[], char copia[], int n)
{
	int i;
	
	for (i=0; i < n; i++)
		copia[i] = palavra[i];
}

char inverter(char palavra[], int n, int m, char copia[])
{
	if (n == 0)
	{
		palavra[m] = copia[n];
	}
		
	else
	{
		palavra[m] = copia[n];
		return inverter(palavra,n-1,m+1,copia);
	}
}
