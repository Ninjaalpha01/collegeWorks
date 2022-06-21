#include <stdio.h>
#include <math.h>

int main()
{
	int n, d, m;
	float s;
	
	s = 0;
	n = 1;
	d = 1;
	m = 1;	
	
	printf("S = 1/1-2/4+3/9-4/16...-10/100\n");
	
	while (d <= 100)
	{
		s = s+m*(n*(1.0)/d);
		n++;
		m = m*(-1);
		d = pow(n,2);
	}
	printf("Portanto S = %f", s);
}
