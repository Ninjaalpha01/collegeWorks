#include <stdio.h>
#include "Questão 8 - L8.h"

int main()
{
	int i, anos, meses, dias, total;
	
	do
	{
		do
		{
			printf("Insira sua idade \nAnos:");
			scanf("%d", &anos);
		} while (anos < 0);
		
		do
		{
			printf("Meses: ");
			scanf("%d", &meses);
		} while (meses < 0 || meses >= 12);
		
		do
		{
			printf("Dias: ");
			scanf("%d", &dias);
		} while (dias < 0 || dias >= 30);
		
		total = anod(anos)+mesd(meses)+dias;
		printf("O total da sua idade em dias eh de: %d dias", total);
		
		i = reset();
	} while (i == 1);
	return 0;
}
