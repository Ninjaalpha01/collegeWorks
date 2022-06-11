#include <stdio.h>

int main()
{
	/*
	x = divisor;
	n = valor inserido pelo usuário;
	a = contador de expoentes;
	b = contador de troca de divisor;
	*/
	
	int x, n, a, b;
	
	scanf("%d", &n);
	x = 2;
	a = 0;
	b = 0;
	
	while (x <= n)
	{
		if (n%x == 0)
			b++;
		
		while (n%x == 0)
		{
			n = n/x;
			a++;
		}
		if (x == 2)
			x++;
		else
			x += 2;
	}
	
	
	if (a%b == 0 && a%2 == 0 && a != b)
		printf("Quadrado perfeito!\n");
	else
		printf("Nao e quadrado perfeito!\n");
	
	return 0;
}
