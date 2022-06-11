#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void main()
{
    int n, a, b, c, d, x, y;

    x=0;
    y=0;
    printf("Insira n: ");
    scanf("%d", &n);
    printf("Insira intervalo entre a e b:\n");
    scanf("%d %d", &a, &b);
    printf("Insira intervalo entre c e d:\n");
    scanf("%d %d", &c, &d);

    if (a < b && c < d && a < c)
    {
        if (n >= a && n <= b && n >= c && n <= d)
        {
            printf("n pertence aos dois intervalos [%d,%d] e [%d,%d].\n", a, b, c, d);
        }
        else 
        {
        	if (n >= a && n <= b)
            {
				printf("n pertence somente ao intervalo [%d,%d].\n", a, b);
        	}
        	else
        	{
        		if (n >= c && n <= d)
        		{
            		printf("n pertence somente ao intervalo [%d,%d].\n", c, d);
        		}
        		else
        		{
        			printf("n nao pertence a nenhum dos intervalos.\n");
            	}
			}
        }
    }
    else
        printf("Esse intervalo eh impossivel.");
}
