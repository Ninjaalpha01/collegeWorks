#include <stdio.h>
#include "Questão 7 - L8.h"

int main()
{
	int i, h, m, s, seg, t;
	
	do
	{
		system("cls");
		printf("Insira o tempo em segundos:\n");
		scanf("%d", &seg);
		
		if (seg > 0)
		{
			h = hora(seg);
			m = minuto(seg);
			s = segundo(seg);
			
			printf("Tempo total %d:%d:%d\n", h, m, s);
			i = reset();
		}
		else
		{
			printf("Erro. Valor invalido\n");
			i = 0;
		}
	} while (i == 1);
	
	return 0;
}
