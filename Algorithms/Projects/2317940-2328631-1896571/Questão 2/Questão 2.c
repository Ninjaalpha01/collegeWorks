/*
Função para ordernar e determinar os elementos de vetEventos[m]##;
Função para que a matImplicacao][2] armazene as implicações##;
Função para pesquisar k, sendo k = n° de vezes que v aparece na matriz;
Função para conseguir o vetor final;
*/

#include <stdio.h>
#include <math.h>

void elementos(int e, int vetEventos[]);
void implicacoes(int i, int matImplicacao[i][2]);
void verdadeiros(int v, int vetVerdade[]);
int pesquisa(int v, int vetVerdade[], int i, int matImplicacao[i][2],int vetK[], int e);
void resultado(int k, int i, int matImplicacao[i][i], int vetK[]);
int teste(int k, int i, int matImplicacao[i][2], int vetK[]);

int main()
{
	int a, b, c; //para testes;
	int e, i, v, k;
	
	do
	{
		scanf("%d %d %d", &e, &i, &v);
	} while (e<1 || e>pow(10,3) || i<1 || i>pow(10,5) || v<1 || v>e);
	
	int vetEventos[e], vetVerdade[e], vetImplicacoes[i], vetK[e];
	int matImplicacao[i][2];
	
	elementos(e,vetEventos);
	implicacoes(i,matImplicacao);
	verdadeiros(v,vetVerdade);
	k = pesquisa(v,vetVerdade,i,matImplicacao,vetK,e);
	
	teste(0,i+1,matImplicacao,vetK);
	//resultado(k,i,matImplicacao,vetK);
		
	for (a=0; a < e; a++)
		printf("%d ", vetK[a]);
	
	return 0;
}

void elementos(int e, int vetEventos[])
{
	int i;
	for (i=0; i < e; i++)
		vetEventos[i] = i+1;
}

void implicacoes(int i, int matImplicacao[i][2])
{
	int a;
	
	fflush(stdin);
	for (a=0; a < i; a++)
		scanf("%d %d", &matImplicacao[a][0], &matImplicacao[a][1]);
}

void verdadeiros(int v, int vetVerdade[])
{
	int a;
	for (a=0; a < v; a++)
	{
		scanf("%d", &vetVerdade[a]);
	}
}

int pesquisa(int v, int vetVerdade[], int i, int matImplicacao[i][2], int vetK[], int e)
{
	int a, b, c, k=0;
	
	for (a=0; a < v; a++)
		for (c=0; c < e; c++)
		{
			for (b=0; b < e; b++)
				if (vetVerdade[a] == matImplicacao[b][1])
				{
					vetK[k] = b;
					k++;
					if (b < i)
						vetVerdade[c] = matImplicacao[b][0];
					else
						vetVerdade[c] = matImplicacao[b][1];
				}
		}
	
	return k;
}

int teste(int x, int i, int matImplicacao[i][2], int vetK[])
{
	if (i == 0)
	{
		return 1;
	}
	
	else
	{
		vetK[x] = matImplicacao[vetK[x]][1];
		return teste(x+1,i-1,matImplicacao,vetK);
	}
}
