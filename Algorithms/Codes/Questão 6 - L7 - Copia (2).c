#include <stdio.h>
#include <math.h>

int distx(int x1, int x2);
int disty(int y1, int y2);
float dist(int sum);
int reset();

int main()
{
	int x1, x2, y1, y2, soma;
	float dt;
	
	do
	{
		printf("Insira o primeiro ponto (x1,y1):\n");
		scanf("%d,%d", &x1, &y1);
		printf("Insira o segundo ponto (x2,y2): \n");
		scanf("%d,%d", &x2, &y2);
		
		soma = distx(x1,x2)+disty(y1,y2);
		dt = (float)dist(soma);
		
		printf("A distancia entre os pontos eh: %f\n", dt);
	
	} while (reset() == 1);
	
	return 0;
}

int distx(int x1, int x2)
{
	int dx;
	x1 = x2-x1;
	dx = pow(x1,2);
	return dx;
}

int disty(int y1, int y2)
{
	int dy;
	y1 = y2-y1;
	dy = pow(y1,2);
	return dy;
}

float dist(int sum)
{
	float dt;
	dt = sqrt(sum);
	return dt;
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
			printf("Obrigado por usar o algoritmo!\n");
			break;
				
		default:
			printf("Opcao invalida.\n"); goto RESET;
			break;
	}
}
