#include <stdio.h>

int ff(int n);

int main()
{
	printf("%d", ff(11));
	return 0;
}

int ff(int n)
{
	if (n == 1)
		return 1;
	if (n%2 == 0)
		return ff(n/2);
	return ff((n-1)/2)+ff((n+1)/2);
}
