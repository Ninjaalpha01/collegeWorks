#include <stdio.h>
#include <math.h>

int main()
{
	int unsigned long n;
	int unsigned long x;
	double s, z;
	
	printf("Insira x: ");
	scanf("%lu", &x);
	printf("1\n");
	
	s = 1;
	n = 1;
	z = x;
	
	while (n < 20)
	{
		s = s+1.0/pow(x,n); 
		x = x*z;
		n = n+1;
		
		printf("+ 1/%lu \t %lf\n", x, s);
	}
	printf("A soma eh: %lf", s);
}
