#include <stdio.h>
#include <math.h>

int delta(int a, int b, int c);
int teste(int d);
float raiz1(int a, int b, int d);
float raiz2(int a, int b, int d);
int reset();

int main()
{
	int a, b, c, d, t, i;
	float r1, r2;
	
	do
	{
		printf("Insira os coeficientes da equacao:\nA: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);
		printf("C: ");
		scanf("%d", &c);
		
		d = delta(a,b,c);
		t = teste(d);
		if (t != 1)
		{
			r1 = raiz1(a,b,d);
			r2 = raiz2(a,b,d);
		
			printf("As raizes sao x = %.2f e x' = %.2f\n", r1, r2);
		}
		i = reset();
	} while (i == 1);
	
	return 0;
}

int delta(int a, int b, int c)
{
	int d;
	d = pow(b,2)-(4*a*c);
	d = sqrt(d);
	return d;
}

int teste(int d)
{
	int i=0;
	
	if (d < 0)
	{
		printf("Impossivel calcular \nDelta negativo!\n");
		i = 1;
	}
	return i;
}

float raiz1(int a, int b, int d)
{
	float x;
	x = (-b+d)/(2.0*a);
	//printf("%f = (%d+%d)/2*%d\n", x, b, d, a);
	return x;
}

float raiz2(int a, int b, int d)
{
	float x;
	x = (-b-d)/(2.0*a);
	//printf("%f = (%d-%d)/2*%d\n\n", x, b, d, a);
	return x;
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
