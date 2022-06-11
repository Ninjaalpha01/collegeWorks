#include <stdio.h>

int main()
{
	float s, n, d;
	int cont;
	
	cont = 1;
	n = 1;
	d = 1;
	s = 0;
	
	printf("S = 1/1+3/2+7/4...+99/50\n");
	
	while (cont <= 50)
	{
		s = s+(n/d);
		n = n+2;
		d++;
		cont++;
	}
	printf("Portanto S = %f\n", s);
}
