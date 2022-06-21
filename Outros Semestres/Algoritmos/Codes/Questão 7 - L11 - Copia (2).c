#include <stdio.h>

int fatorial(int n);

int main()
{
	int n, fat;
	
	do
	{
		printf("Insira n!: ");
		scanf("%d", &n);
	} while (n < 0);
	
	fat = fatorial(n);
	
	printf("%d! = %d", n, fat);
	
	return 0;
}

int fatorial(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	else
		return n*fatorial(n-1);
}
