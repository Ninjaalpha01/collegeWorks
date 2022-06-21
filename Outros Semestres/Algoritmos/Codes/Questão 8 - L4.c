#include <stdio.h>
#include <math.h>

int main()
{
	int sum, n, x, y, z;
	
	printf("Insira a quantidade de termos desejada: ");
	scanf("%d", &n);
	
	x = 1;
	y = 0;
	
	printf("Sequencia: %d", x);
		
	while (n > 0)
	{
		z = x+y; 
		printf(", %d", z);
		y = x;
		x = z;
		n--;
		sum = sum+z;
	}
	sum++;
	printf("\nSoma: %d", sum);
}
