#include <stdio.h>
#include <math.h>

float D(int a, int b, int c);
int R(int a, int b);
int S(int b, int c);
int reset();

int main()
{
	int A, B, C, r, s, i;
	float d;
		
	do
	{
		printf("Insira tres valores inteiros e positivos:\n");
		scanf("%d %d %d", &A, &B, &C);
		
		if (A > 0 && B > 0 && C > 0)	
		{
			d = D(A,B,C);
			printf("O resultado da expressao eh: %.2f\n\n", d);
			i = reset();
		}
		else 
		{
			printf("Erro. Numero invalido!\n");
			i = 1;
		}
	} while (i == 1);
	
	return 0;
}

int R(int a, int b)
{
	int total;
	total = pow(a+b,2);
	return total;
}

int S(int b, int c)
{
	int total;
	total = pow(b+c,2);
	return total;
}

float D(int a, int b, int c)
{
	float total;
	int r, s;
	
	r = R(a,b);
	s = S(b,c);
	total = (r+s)/2.0;
	
	return total;
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
