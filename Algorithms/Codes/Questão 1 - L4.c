#include <stdio.h>
#include <math.h>

int main ()
{
	int x, cont;
	
	x = 1000;
	
	while (x <= 1999)
	{
		if ((x % 11) == 5)
			printf("%i\n", x);
		x++;
	}
}
