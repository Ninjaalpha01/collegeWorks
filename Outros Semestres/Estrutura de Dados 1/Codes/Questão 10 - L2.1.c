#include <stdio.h>
#include <stdlib.h>
#include "gabriel.c"

int Strlen(char *str);
char *Strcpy(char *str);
void Strlwr(char *str);
void Strupr(char *str);
char *Strchr(char *str, char x);
char *Strcat(char *str1, char *str2, int n1, int n2);

int main ()
{
	const tam=40;
	char s1[tam], s2[tam];
	int ns1, ns2;
	char *cop, *conc, *sch;
	
	printf("Insira:\n");
	printf("string 1: ");
	fgets(s1,tam,stdin);
	fflush(stdin);
	printf("string 2: ");
	fgets(s2,tam,stdin);
	fflush(stdin);
		
	ns1 = Strlen(s1)-1;
	ns2 = Strlen(s2)-1;
	
	cop = Strcpy(s1);
	printf("copia s1: ");
	imprimechr(cop);
	
	Strlwr(s1);
	printf("s1 lwrcase: ");
	imprimechr(s1);
	
	Strupr(s2);
	printf("s2 uprcase: ");
	imprimechr(s2);
	
	char c;
	printf("Insira um caractere: ");
	scanf("%c", &c);
	fflush(stdin);
	sch = Strchr(s1,c);
	printf("strchr (s1,%c): ", c);
	imprimechr(sch);
	
	conc = Strcat(s1,s2,ns1,ns2);
	printf("conca s1 e s2: ");
	imprimechr(conc);
	
	return 0;
}

int Strlen(char *str)
{
	int i=0;
	
	while (*(str+i) != '\0')
		i++;
	
	return i;
}

char *Strcpy(char *str)
{
	char *pont;
	int n, i;
	
	n = strlen(str);
	pont = (char *)malloc(n * sizeof(char));
	
	if (pont == NULL)
		printf("SO nao liberou memoria!\n");
	
	for (i=0; i<n && *(str+i) != '\n'; i++)
		*(pont+i) = *(str+i);
	
	return pont;
}

void Strlwr(char *str)
{
	int i, n;
	
	n = strlen(str);
	
	for (i=0; i<n; i++)
		if (*(str+i) >= 65 && *(str+i) <= 90)
			*(str+i) += 32;
}

void Strupr(char *str)
{
	int i, n;
	
	n = strlen(str);
	
	for (i=0; i<n; i++)
		if (*(str+i) >= 97 && *(str+i) <= 122)
			*(str+i) -= 32;
}

char *Strchr(char *str, char x)
{
	int i, j=0, n;
	char *str2=NULL;
	
	n = Strlen(str)-1;
	str2 = (char *)malloc(n * sizeof(char));
	
	for (i=0; i<n; i++)
		if (x == *(str+i))
		{
			j = i;
			i = n;
		}
	
	if (j>0)
		for (i=0; i<n; i++, j++)
			*(str2+i) = *(str+j);
	
	return str2;
}

char *Strcat(char *str1, char *str2, int n1, int n2)
{
	int i, j=0, nt; 
	char *p=NULL;
	
	nt = n1+n2;
	
	p = (char *)malloc(nt * sizeof(char));
	if (p == NULL)
		printf("SO nao deu memoria!\n");
	
	for (i=0; i<n1; i++)
		*(p+i) = *(str1+i);
	j = i;
	for (i=0;i<nt; i++)
	{
		*(p+j) = *(str2+i);
		j++;
	}
	
	return p;
}
