#include <stdio.h>

int multi(int k, int n);

int main()
{
	int k, n, mul;
	
	do
	{
		printf("Insira k: ");
		scanf("%d", &k);
	} while (k <= 0);
	do
	{
		printf("Insira n: ");
		scanf("%d", &n);
	} while (n <= 0);
	
	mul = multi(k,n);
	
	printf("%d*%d = %d", k, n, mul);
	
	return 0;
}

int multi(int k, int n)
{
	if (n == 1)
		return k;
	else
		return k+multi(k,n-1);
}
