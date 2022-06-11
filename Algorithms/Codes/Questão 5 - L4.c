#include <stdio.h>
#include <math.h>

int main()
{
	int cont, n, d, i;
	float s;
	
	s = 0;
	n = 1;
	d = 1;
	i = 3;
	cont = 0;	
	
	printf("S = 1/1-2/4+3/9-4/16...-10/100\n");
	
	while (d <= 100)
	{
		s = s+(n*(1.0)/d);
		
		if (n > 0)
			n = -(n+1);
		else
			n = (n-1)*(-1);
			
		d = d+i;
		i = i+2;
	}
	printf("Portanto S = %f", s);
}
