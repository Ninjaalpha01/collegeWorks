#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gabriel.h"

int MMC(int n1, int n2, int n3)
{
	int mul, t;
	
	mul = 1;
	t = 2;
	
	do
	{	
		do
		{
			if(n1 % t == 0 && n2 % t == 0 && n3 % t == 0)
			{
				n1 = n1/t;
				n2 = n2/t;
				n3 = n3/t;
				
				mul = mul*t;
			}
			else
			{
				if (n1 % t != 0 && n2 % t == 0 && n3 % t == 0)
				{
					n2 = n2/t;
					n3 = n3/t;
					
					mul = mul*t;
				}
				else
				{
					if (n1 % t == 0 && n2 % t != 0 && n3 % t == 0)
					{
						n1 = n1/t;
						n3 = n3/t;
						
						mul = mul*t;
					}
					else
					{
						if(n1 % t == 0 && n2 % t == 0 && n3 % t != 0)
						{
							n1 = n1/t;
							n2 = n2/t;
							
							mul = mul*t;
						}
						else
						{
							if(n1 % t != 0 && n2 % t != 0 && n3 % t == 0)
							{
								n3 = n3/t;
								
								mul = mul*t;
							}
							else
							{
								if(n1 % t != 0 && n2 % t == 0 && n3 % t != 0)
								{
									n2 = n2/t;
									
									mul = mul*t;
								}
								else
								{
									if(n1 % t == 0 && n2 % t != 0 && n3 % t != 0)
									{
										n1 = n1/t;
										
										mul = mul*t;
									}
									else
									{
										if(n1 % t != 0 && n2 % t != 0 && n3 % t != 0)
											goto T;
									}
								}
							}
						}
					}
				}
			}
		} while (n1 % t == 0 || n2 % t == 0 || n3 % t == 0);
	T:
		if (t == 2)
			t++;
		else
			t = t+2;
	} while (n1 != 1 || n2 != 1 || n3 != 1);
	
	return mul;
}

int MDC(int n1, int n2, int n3)
{
	int mul, t;
	
	mul = 1;
	t = 2;
	
	do
	{
		do
		{
			if(n1 % t == 0 && n2 % t == 0 && n3 % t == 0)
			{
				n1 = n1/t;
				n2 = n2/t;
				n3 = n3/t;
				
				mul = mul*t;
			}
			else
			{
				if (n1 % t != 0 && n2 % t == 0 && n3 % t == 0)
				{
					n2 = n2/t;
					n3 = n3/t;
				}
				else
				{
					if (n1 % t == 0 && n2 % t != 0 && n3 % t == 0)
					{
						n1 = n1/t;
						n3 = n3/t;
					}
					else
					{
						if(n1 % t == 0 && n2 % t == 0 && n3 % t != 0)
						{
							n1 = n1/t;
							n2 = n2/t;
						}
						else
						{
							if(n1 % t != 0 && n2 % t != 0 && n3 % t == 0)
								n3 = n3/t;
								
							else
							{
								if(n1 % t != 0 && n2 % t == 0 && n3 % t != 0)
									n2 = n2/t;
									
								else
								{
									if(n1 % t == 0 && n2 % t != 0 && n3 % t != 0)
										n1 = n1/t;
										
									else
									{
										if(n1 % t != 0 && n2 % t != 0 && n3 % t != 0)
											goto T;
									}
								}
							}
						}
					}
				}
			}
		} while (n1 % t == 0 || n2 % t == 0 || n3 % t == 0);
	T:
		if (t == 2)
			t++;
		else
			t = t+2;
			
	} while (n1 != 1 || n2 != 1 || n3 != 1);
	
	return mul;
}

int fat(int x)
{
	int p = 1;
	
	if (x > 0)
		while (x > 0)
		{
			p = p*x;
			x--;
		}
	return p;
}

int maiorvet(int vet[], int tamanho, int term1)
{
	if (tamanho == 0)
		return term1;
	else
		if (term1 < vet[tamanho])
			{
				term1 = vet[tamanho];
				return maiorvet(vet,tamanho-1,term1);
			}
		else
			return maiorvet(vet,tamanho-1,term1);
}

int somavet(int vet[], int tam)
{
	if (tam == 1)
		return vet[0];
	else
		return vet[tam-1]+somavet(vet,tam-1);
}

int *alocaveti(int tam)
{
	int *p=NULL;
	p = (int *)malloc(tam * sizeof(int));
	if(p==NULL)
		printf("\nSO nao liberou memoria!");
    return p; 
}

int *concatint(int *a, int na, int *b, int nb)
{
	int *p,i,j=na;
	
	if(a && b)
	{
		//p = (int *)malloc((na+nb)*sizeof(int));	
		p = alocaveti(na+nb);
		if(p)
		{
			for(i=0;i<na;i++)
		    	*(p+i) = *(a+i);
		    j = na;
			for(i=0;i<nb;i++)
			{
			  *(p+j) = *(b+i);
			  j++;
			}
			return p;
		}
	}
}

void inverte(char str[], int tamanho)
{
	int x, i, buffer;
	
	//Armazena o tamanho-1 para excluir o \0 da string
	x = tamanho-1;
	
	//Inverte os caracteres da string
	for (i=0; i<tamanho/2; i++, x--)
	{
		buffer = *(str+i);
		*(str+i) = *(str+x);
		*(str+x) = buffer;
	}
}

void cesar(char str[])
{
	int i=0;
	
	for (; i<strlen(str); i++)
	{
		if (*(str+i) != ' ')
			*(str+i) += 3;
	}
	strupr(str);
}

void imprimeint(int *vet, int tam)
{
	int i;
	if(vet)
	{
		for(i=0; i<tam; i++)
		   printf("%d ", *(vet+i));	
	}
	else printf("nao tem nada na memoria!");
}

void imprimechr(char *vet)
{
	int i, tam;
	tam = strlen(vet);
	if(vet)
	{
		//printf("%s", vet);
		for(i=0; i<tam && *(vet+i) != '\0'; i++)
			printf("%c", *(vet+i));
	}
	else printf("nao tem nada na memoria!");
}

void desalocai(int **vet)
{
	free(*vet);
	*vet=NULL;
}

void desalocac(char **vet)
{
	free(*vet);
	*vet=NULL;
}

void desalocaf(float **vet)
{
	free(*vet);
	*vet = NULL;
}

void armint(int *vet, int tam)
{
	int i;
	if(vet)
	{
		for(i=0; i<tam; i++)
		{
		  printf("\nDigite valor [%d]: ",i);
		  scanf("%d",(vet+i));
		}
		   	
	}
	else printf("Nao tem espaco na memoria!");
}

float *concaflo(float *v1, float *v2, int n1, int n2)
{
	int i, j;
	float *p=NULL;
	
	p = (float *)malloc((n1+n2) * sizeof(float));
	if(p)
	{
		for (i=0; i<n1; i++)
			*(p+i) = *(v1+i);
		j = i;
		
		for (i=0; i<n2; i++, j++)
			*(p+j) = *(v2+i);
			
		return p;
	}
}

double multvet(int vet[], int tam)
{
	if (tam == 1)
		return vet[0];
	else
		return vet[tam-1]*multvet(vet,tam-1);
}

int reset()
{
	int res;
RESET:
	fflush(stdin);
	printf("\nDeseja refazer o processo? (s/n)\n");
	scanf("%c", &res);
	
	switch (res)
	{
		case 's':
		case 'S':
			return res=1;
			break;
		
		case 'n':
		case 'N':
			printf("Ate mais!\n");
			break;
				
		default:
			printf("Opcao invalida.\n"); goto RESET;
			break;
	}
}
