#include "recursividade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int multiplicacao(int a, int b)
{
	if (b == 1)
		return a;
	else
		return a+multiplicacao(a,b-1);
}

void decrescente(int n)
{
	if (n == 0)
	{
		printf("0\nfim\n");
		system("pause");
		return;
	}
	
	else
	{
		printf("%d\n", n);
		return decrescente(n-1);
	}
}

void impares(int n)
{
	if (n==0)
	{
		printf("fim\n");
		system("pause");

		return;
	}
	else if(n%2!=0){
		printf("%d\n",n);
		n=n-1;
		return impares(n);
	}
	else
	{
		n=n-1;
		return impares(n);
	}

}

unsigned int pares(int n, int aux)
{
	if(n%2==0){
		if (n<=1)
		{
		return aux;
		}
		else
		{
		aux=aux*n;
		n=n-2;
		return pares(n, aux);
		}
	}

	else{
		n=n-1;
		return pares(n, aux);
	}
}

int palindromo(char p[], int tam, int pos) 
{

    if (pos < tam / 2)
	{
        if (p[pos] == p[tam - pos - 1])
		{
            return 1 * palindromo(p, tam, pos+1);
        }
        else{
            return 0;
        }
    }
	
    else{
        return 1;
    }
}

int somanaturais(int a, int b)
{
	if (b==0)
	{
		return a;
	}
	else
	a=a+1;
	b=b-1;
	return somanaturais(a,b);
}

int devolveindice(int *v, int k, int n)
{
	int i;
	for(i=0; i<=n; i++)
	{
		if(v[i]==k){
			return i;
		}
	}
	return -1;

}
