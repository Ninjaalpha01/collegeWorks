#include <stdio.h>

int Fatorial(int n)
{
	int p = 1;
	
	while (n > 0)
	{
		p = p*n;
		n--;
	}
	return p;
}

int Potencia(int base, int exp)
{
	int res = 1;
	for (; exp > 0; exp--)
		res *= base;
	for (; exp < 0; exp++)
		res *= base;
	return res;
}

int SomaFibonacci(int ntermos)
{
	int x=1, y=0, z, sum;
	while (ntermos > 0)
	{
		z = x+y;
		y = x;
		x = z;
		ntermos--;
		sum = sum+z;
	}
	sum++;
	return sum;
}

float MediaAltura(int n)
{
	int sum=0, x;
	float med;
	med = n;

	for (n; n > 0; n--)
	{
		printf("Insira os valores:\n");
		scanf("%d", &x);
		sum += x;
	}
	med = (float)sum/med;
	return med;
}
