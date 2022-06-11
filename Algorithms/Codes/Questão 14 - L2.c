#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	float a, b, c, ab, ac, ba, bc, ca, cb;
	
	printf("Insira i: ");
	scanf("%i", &i);
	printf("Insira a, b e c:\n");
	scanf("%f%f%f", &a, &b, &c);
	
	ab = a-b;
	ac = a-c;
	bc = b-c;
	ba = b-a;
	ca = c-a;
	cb = c-b;
	
	if(i == 1)
	{		
		if (ab > 0 && bc > 0)
			printf("%f\n%f\n%f", c, b, a);
			
		if (ac > 0 && cb > 0)
			printf("%f\n%f\n%f", b, c, a);
			
		if (ba > 0 && ac > 0)
			printf("%f\n%f\n%f", c, a, b);
			
		if (bc > 0 && ca > 0)
			printf("%f\n%f\n%f", a, c, b);
			
		if (ca > 0 && ab > 0)
			printf("%f\n%f\n%f", b, a, c);
			
		if (cb > 0 && ba > 0)
			printf("%f\n%f\n%f", a, b, c);
	}
	if (i == 2)
	{
		if (ab > 0 && bc > 0)
			printf("%f\n%f\n%f", a, b, c);
			
		if (ac > 0 && cb > 0)
			printf("%f\n%f\n%f", a, c, b);
			
		if (ba > 0 && ac > 0)
			printf("%f\n%f\n%f", b, a, c);
			
		if (bc > 0 && ca > 0)
			printf("%f\n%f\n%f", b, c, a);
			
		if (ca > 0 && ab > 0)
			printf("%f\n%f\n%f", c, a, b);
			
		if (cb > 0 && ba > 0)
			printf("%f\n%f\n%f", c, b, a);
	}
	if (i == 3)
	{
		if (ab > 0 && bc > 0)
			printf("%f\n%f\n%f", b, a, c);
			
		if (ac > 0 && cb > 0)
			printf("%f\n%f\n%f", c, a, b);
			
		if (ba > 0 && ac > 0)
			printf("%f\n%f\n%f", b, c, a);
			
		if (bc > 0 && ca > 0)
			printf("%f\n%f\n%f", b, a, c);
			
		if (ca > 0 && ab > 0)
			printf("%f\n%f\n%f", a, c, b);
			
		if (cb > 0 && ba > 0)
			printf("%f\n%f\n%f", c, a, b);
	}
	
	return 0;
}
