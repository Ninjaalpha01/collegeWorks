#include <stdio.h>
#include <math.h>

int main()
{
	int di, hi, mi, si, df, hf, mf, sf, ad;
	int ht, mt, st;
	
	printf("Insira a hora de inicio:\n");
	scanf("%d:%d:%d", &hi, &mi, &si);
	printf("Insira o dia de inicio: ");
	scanf("%d", &di);
	printf("Insira a hora de termino:\n");
	scanf("%d:%d:%d", &hf, &mf, &sf);
	printf("Insira o dia de termino: ");
	scanf("%d", &df);
	
	ad = df-di;
	
	if(ad == 1 || ad == 0)
	{
		ht = (hf+ad*24)-hi;
		mt = mf-mi;
		st = sf-si;
		
		if (mt >= 0 && st >= 0)
		{
			printf("Duracao do jogo foi de:\n");
			printf("%d:%d:%d", ht, mt, st);
		}
		if (st < 0)
		{
			mt = mt-1;
			st = (st*-1)+(60-si);
			
			if (mt < 0)
			{
			//	st = (sf+mt*-1)-si;
				mt = mt+60;
				ht = ht-1;
				printf("Duracao do jogo foi de:\n");
				printf("%d:%d:%d", ht, mt, st);
			}
		}
		if (mt < 0 && st >= 0)
		{
		//	st = (sf+mt*-1)-si;
			mt = mt+60;
			ht = ht-1;
			printf("Duracao do jogo foi de:\n");
			printf("%d:%d:%d", ht, mt, st);
		}
	}
	else
		printf("Horario invalido");	
	
	return 0;
}
