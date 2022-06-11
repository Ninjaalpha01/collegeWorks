#include <stdio.h>
#include <math.h>

int main()
{
	float x, y, z;
	
	printf("Insira x, y e z:\n");
	scanf("%f %f %f", &x, &y, &z);
	
	if (x > 0 && y > 0 && z > 0)
	{
		if (x == y && y == z && x == z)
		{
			printf("xyz formam um triangulo equilatero");
		}
		if ((x == y && x != z) || (x == z && x != y) || (y == z && y != x))
		{
			printf("xyz formam um triangulo isoceles");
		}
		if (x != y && x != z && y != z)
		{
			printf("xyz formam um triangulo escaleno");
		}
	}
	else
		printf("xyz nao formam um triangulo");
	
	return 0;
}
