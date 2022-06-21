#include <stdio.h>
#include <math.h>

int main()
{
	int c, n, d;
	float som, som_p, som_n;
	
	som = 0;
	som_p = 0;
	som_n = 0;
	n = 1000;
	d = 1;
	c = 1;
	
	do
	{
		som_p = som_p+((float)n/d);
		n = n-3;
		d++;
		
		som_n = som_n+((float)n/d);
		n = n-3;
		d++;
		
		som = som+(som_p-som_n);
		
		c++;
	} while (c <= 50);
	
	printf("A soma total eh igual a %f", som);
}
