#include <stdio.h>
#include <math.h>

float me(int ang, float h);
float conv(float ang);
int reset();

int main()
{
	float h, medida;
	int ang, i;
	
	do
	{
		printf("Insira o angulo (em graus) formado pela escada e o chao:\n");
		scanf("%d", &ang);
		printf("Insira a altura da parede onde se encontra a ponta da escada:\n");
		scanf("%f", &h);
		
		if (ang > 0 && h > 0)
		{
			medida = me(ang,h);
			
			printf("A medida da escada eh de: %.2f\n", medida);
			
			i = reset();
		}
		else
		{
			printf("Erro. Valores invalidos!\n");
			i = 1;
		}
		
	} while (i == 1);
	
	return 0;
}

float conv(float ang)
{
	float angr;
	angr = ang/57.2958;
	return angr;
}

float me(int ang, float h)
{
	float angr, seno, res;
	
	angr = conv(ang);
	seno = sin(angr);
	res = h/seno;
	printf("res = %f \t h = %f \t seno = %f\n", res, h, seno);
	return res;
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
