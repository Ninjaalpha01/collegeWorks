#include <stdio.h>
#include "Questão 9 - L8.h"

int main()
{
	int i, x, m, h, hri, mini, hrf, minf;
	
	do
	{
		do
		{
			printf("Hora de inicio do jogo (hr:min):\n");
			scanf("%d:%d", &hri, &mini);
			x = teste(hri,mini);
			if (x == 1)
				{
					system("cls");
					printf("Erro. Hora invalida. Insira novamente\n");
					x = 0;
				}
		} while (hri < 0 || mini < 0);
		do
		{
			printf("Hora do fim do jogo (hr:min):\n");
			scanf("%d:%d", &hrf, &minf);
			if (teste(hrf,minf) == 1)
				printf("Erro. Hora invalida. Insira novamente\n");
		} while (hrf < 0 || minf < 0);
		
		m = minu(mini,minf);
		
		if (m < 0)
		{
			hrf--;
			h = hora(hri,hrf);
			m += 60;
		}
		else
			h = hora(hri,hrf);
		
		printf("A duracao do jogo foi de %d:%d", h, m);
		
		i = reset();
	} while (i == 1);
	
	return 0;
}
