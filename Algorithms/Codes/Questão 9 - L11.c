#include <stdio.h>

int mdc(int x, int y);

int main()
{
	int x, y, res;
	
	do
	{
		printf("Insira x: ");
		scanf("%d", &x);
	} while (x <= 0);
	
	do
	{
		printf("Insira y: ");
		scanf("%d", &y);
	} while (y <= 0);
	
	res = mdc(x,y);
	
	printf("MDC de (%d,%d): %d", x, y, res);
	
	return 0;
}

int mdc(int x, int y)
{
	if (x >= y && x%y == 0)
		return y;
	else
		if (x < y)
			return mdc(y,x);
		else
			return mdc(y,x%y);
}
