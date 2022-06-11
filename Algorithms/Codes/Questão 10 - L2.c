#include <stdio.h>
#include <math.h>

int main()
{
	float ip;
	
	printf("Indice de Poluicao atual: ");
	scanf("%f", &ip);
	
	if (ip >= 0.05 && ip <= 0.25)
	{
		printf("Indice de Poluicao: aceitavel");
	}
	if (ip > 0.25 && ip < 0.4)
	{
		printf("Indice de Poluicao: medio\n");
		printf("Enviar intimacoes ao grupo 1!");
	}
	if (ip >= 0.4 && ip < 0.5)
	{
		printf("Indice de Poluicao: alto\n");
		printf("Enviar intimacoes ao grupo 1 e grupo 2!");
	}
	if (ip >= 0.5)
	{
		printf("Indice de Poluicao: critico\n");
		printf("ATENCAO! ENVIAR INTIMACOES A TODOS OS GRUPOS!\a");
	}
	if (ip < 0.05 && ip >= 0)
		printf("Indice de Poluicao: Ideal");
	
	return 0;
}
