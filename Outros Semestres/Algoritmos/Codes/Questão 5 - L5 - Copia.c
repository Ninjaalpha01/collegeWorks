#include <stdio.h>
#include <math.h>

int main()
{
	float c;
	int f = 50;
	
	printf("C = (5/9)(F-32)\n");
	printf("Farenheint\tCentrigrados\n");
	
	do
	{
		c = (5.0/9)*(f-32);
		
		printf("    ");
		printf("%d\t\t   %.2f\n", f, c);
		
		f++;
	} while (f <= 150);
}
