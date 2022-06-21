#include <stdio.h>
#include <math.h>

float media(int n);
float del(int a, int b, int c);
float r1(int a, int b, int c);
float r2(int a, int b, int c);
int reset();

int main()
{
	int num; //Média
	float md; //Média
	int a, b, c; //Equação
	float raiz1, raiz2; //Equação
	char opc;
	int i=1;
	
	do	
	{
		fflush(stdin);
		printf("Selecione a operacao:\n");
		printf("M - calcular a media\n");
		printf("E - calcular uma equacao de 2 grau\n");
		printf("Q - sair do programa\n");
		scanf("%c", &opc);
			
		switch (opc)
		{
			case 'M':
			case 'm':
			{
				printf("Quantos numeros serao necessarios para a media? ");
				scanf("%d", &num);
				
				md = media(num);
				
				printf("A media dos numeros e de: %f", md);
				
				i = reset();
			} break;
		
			case 'E':
			case 'e':
			{
				printf("Insira os coeficientes da equacao:\nA: ");
				scanf("%d", &a);
				printf("B: ");
				scanf("%d", &b);
				printf("C: ");
				scanf("%d", &c);
				
				raiz1 = r1(a,b,c);
				raiz2 = r2(a,b,c);
					
				printf("Raizes: \nx1 = %f \tx2 = %f", raiz1, raiz2);
				
				i = reset();
			} break;
		
			case 'Q':
			case 'q':
			{
				printf("Obrigado por usar o algoritmo!\n");
				i = 0;
			} break;
			
			default:
				printf("Erro. Opcao invalida!\n");
				break;
		}
	} while (i == 1);
	
	return 0;
}

float media(int n)
{
	int x, i, soma = 0;
	float md;
	
	for (i=n; i > 0; i--)
	{
		printf("Insira os valores:\n");
		scanf("%d", &x);
		soma += x;
	}
	md = soma/n;
	
	return md;
}

float del(int a, int b, int c)
{
	float d;
	
	d = pow(b,2)-4*a*c;
	d = sqrt(d);
	
	return d;
}

float r1(int a, int b, int c)
{
	float x1, d;
	
	d = del(a,b,c);
	x1 = 1.0*(-b+d)/(2*a);
	
	return x1;
}

float r2(int a, int b, int c)
{
	float x2, d;
	
	d = del(a,b,c);
	x2 = (-b-d)/(2*a);
	
	return x2;
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
