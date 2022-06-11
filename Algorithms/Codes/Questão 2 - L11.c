#include <stdio.h>
#include <time.h>

float menor_elem(float A[], int n, float menor);

int main ()
{
	srand(time(NULL));
	int c, i, n=15, opc;
	float A[n], menor;
	
	do
	{
		printf("Insira os elementos do vetor:\n");
		for (i=0; i < n; i++)
		{
			//printf("[%d]: ", i);
			//scanf("%f", &A[i]);
			A[i] = rand()%10;
			printf("[%d]: %f\n", i, A[i]);
		}
		
		menor = menor_elem(A,n-1,A[0]);
		printf("O menor elemento eh: %f\n", menor);
		
		printf("Voce deseja refazer? (1-sim/0-nao)\n");
		scanf("%d", &opc);
		if (opc == 1)
			{
				c = 1;
				system("cls");
			}
		else
			{
				printf("Ate mais!\n");
				c = 0;
			}
	} while (c == 1);
	
	return 0;
}

float menor_elem(float A[], int n, float menor)
{
	if (n == 0)
		return menor;
	else
		if (menor >= A[n])
			{
				menor = A[n];
				return menor_elem(A,n-1,menor);
			}
		else
			return menor_elem(A,n-1,menor);
}
