#include <stdio.h>

int main()
{
	int ano;
	float hf, hc;
	
	hf = 1.5;
	hc = 1.1;
	ano = 0;
	
	do
	{
		printf("%d ano(s), hf = %.2f, hc = %.2f\n", ano, hf, hc);
		
		ano++;
		hf = hf+0.02;
		hc = hc+0.03;
	} while (hf >= hc);
	
	printf("Serao necessarios: %d anos", ano);
}
