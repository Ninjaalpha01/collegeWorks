#include <stdio.h>
#include <math.h>

int main()
{
	int x, d, e;
	double som;
	
	printf("Insira x: ");
	scanf("%d", &x);
	
	e = 25;
	d = 1;
	
	do
	{
		printf(" (%d^%d)/%d +", x, e, d);
		
		som = som+(pow(x,e)/(float)d);
		
		d++;
		e--;
	} while (d <= 25);
	
	printf("\b \nSoma igual: %lf", som);
}
