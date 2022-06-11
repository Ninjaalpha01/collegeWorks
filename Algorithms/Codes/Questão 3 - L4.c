#include <stdio.h>

int main()
{
	int x, xp;
	
	printf("Insira o valor:\n");
	
	while (x > 0)
	{
		scanf ("%d", &x);
		if ((x % 2) == 0 && x != 0)
		{
			xp = x+2;
			printf("%d\t%d\n", x, xp);
		}
		else
		{
			if ((x %2) != 0 && x != 0)
			{
				xp = x+1;
				printf("%d\t%d\n", x, xp);
			}
			else
				printf("%d", x);
		}
	}
}


