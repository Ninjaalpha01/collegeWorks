#include <stdio.h>

float pp(float pes);
float pj(float pes);
float pm(float pes);
int reset();

int main()
{
	int i;
	float p, pol, jar, mil;
	
	do
	{
		printf("Insira a medida em pes: ");
		scanf("%f", &p);
		
		if (p > 0)
		{
			pol = pp(p);
			jar = pj(p);
			mil = pm(p);
			
			printf("\n%f pes equivale a:\n", p);
			printf("%f polegadas\n", pol);
			printf("%f jardas\n", jar);
			printf("%f milhas\n", mil);
			
			i = reset();
		}
		else
		{
			printf("Erro. Medida invalida\n");
			i = 0;
		}
	} while (i == 1);
	
	return 0;
}

float pp(float pes)
{
	float pol;
	pol = pes*12;
	return pol;
}

float pj(float pes)
{
	float jar;
	jar = pes/3;
	return jar;
}

float pm(float pes)
{
	float mil, jar;
	jar = pj(pes);
	mil = jar/1760;
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
