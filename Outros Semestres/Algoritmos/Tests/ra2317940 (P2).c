#include <stdio.h>

void magico(int quadrado[3][3], int n);

int main()
{
	int n, i, j;
	
	printf("Insira N: ");
	scanf("%d", &n);
	
	int quadrado[n][n];
	
	for (i=0; i < n; i++)
		for (j=0; j < n; j++)
			{
				printf("[%d][%d]: ", i, j);
				scanf("%d", &quadrado[i][j]);
			}
	
	magico(quadrado,n);
}

void magico(int quadrado[3][3], int n)
{
	int M, a, b, si, sj, veta[n], vetb[n];
	int i, j, original, laura;
	
	si = 0;
	sj = 0;
	
	for (a=0; a < n; a++)
		{
			for (b=0; b < n; b++)
				{
					si = si+quadrado[a][b];
					veta[a] = si;
				}
			si = 0;
		}
	
	for (b=0; b < n; b++)
		{
			for (a=0; a < n; a++)
				{
					sj = sj+quadrado[a][b];
					vetb[b] = sj;
				}
			sj = 0;
		}
	
	for (a=0; a < n; a++)
		for (b=0; b < n; b++)
		{
			if (veta[a] == vetb[b] && a != 0 && b != 0)
			{
				if (veta[a-1] == veta[a] || vetb[b-1] == vetb[b])
					{
						M = veta[a];
					}
				else
					{
						M = veta[a-1];
					}
			}
		}
		
	for (a=0; a < n; a++)
	{
		if (veta[a] != M)
			i = a;
	}
	
	for (b=0; b < n; b++)
		if (vetb[b] != M)
			j = b;
	
	if (veta[i] < M && vetb[j] < M)
		original = M-veta[i]+quadrado[i][j];
	else
		if (veta[i] > M && vetb[j] > M)
			original = M-veta[i]+quadrado[i][j];
	
	
	laura = quadrado[i][j];
	
	printf("%d %d %d %d %d", i, i, j, original, laura);
}
