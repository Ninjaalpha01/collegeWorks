#include <stdio.h>
#include <math.h>

int main()
{
	int n, d;
	double som, som_p, som_n;
	
	som_p = 0;
	som_n = 0;
	n = 1;
	d = 500;
	
	do
	{
		if (d > 0)
		{
			som_p = 2.0/d;
			printf("+ 2/%d ", d);
			
			d = d-50;
			som_n = 5.0/d;
			printf("- 5/%d ", d);
			
			som = som+(som_p-som_n);
			
			d = d-50;
		}	
		n++;
	} while (n <= 10);
	
	printf("\nA soma de todos os termos acima eh igual a: %lf", som);
}
