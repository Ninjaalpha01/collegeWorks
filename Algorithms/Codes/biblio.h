#include <stdio.h>

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
