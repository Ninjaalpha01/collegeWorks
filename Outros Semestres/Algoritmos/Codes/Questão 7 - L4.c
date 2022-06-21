#include <stdio.h>
#include <math.h>
#define e 2.7182818

int main()
{
	int f, d;
	double x;
	
	printf("e = %f\n", e);
	d = 1;
	f = 1;
	x = 0;
	
	while (f <= 15)
	{
		d = d*f;
		f++;
		x = x+(1.0/d);
	}
	printf("Calculado e = %f", x);
}
