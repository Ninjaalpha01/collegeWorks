#include <stdio.h>
#include <math.h>
#define pi 3.14

int main()
{
	float r, v;
	
	printf("Volume para\n");
	r = 0;
	
	do
	{
		v = (4.0/3)*pi*pow(r,3);
		
		printf("R = %.1fcm:\t%.3fcm3\n", r, v);
		
		r = r+0.5;
	} while (r > 0 && r <= 20);
}
