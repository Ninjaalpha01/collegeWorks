#include <stdio.h>
#include <math.h>

int t=0, r, s;
char res;

void R(int a, int b)
{
	r = pow(a+b,2);
}

void S(int b, int c)
{
	s = pow(b+c,2);
}

void D()
{
	float d;
	
	d = ((float)r+s)/2;
	printf("\nO resultado da expressao e: %.2f\n\n", d);
}

void teste(int x, int y, int z)
{
	if (x >= 0 && y >= 0 && z >= 0)
		t = 1;
}

void reset()
{
RESET:
	fflush(stdin);
	printf("Deseja refazer o processo? (s/n)\n");
	scanf("%c", &res);
	
	switch (res)
	{
		case 's':
		case 'S':
			res = 1;
			break;
		
		case 'n':
		case 'N':
			printf("Obrigado por usar o algoritmo!\n");
			break;
				
		default:
			printf("Opcao invalida.\n"); goto RESET;
			break;
	}
}

void main()
{
	int x, y, z;
	
	do
	{
		do
		{
			printf("Insira 3 numeros inteiros e positivos:\n");
			scanf("%d %d %d", &x, &y, &z);
			teste(x,y,z);
		} while (t!=1);
		
		R(x,y);
		S(y,z);
		D();
		
		reset();
	} while (res == 1);
}
