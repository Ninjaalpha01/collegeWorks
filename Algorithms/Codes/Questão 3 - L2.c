#include <stdio.h>
#include <math.h>

int main()
{
	int n1, n2, n3, n4;
	int res2_n1, res3_n1, res2_n2, res3_n2, res2_n3, res3_n3, res2_n4, res3_n4;
	
	printf("Insira os quatro numeros em sequencia abaixo:\n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);
    
    res2_n1 = n1%2;
    res3_n1 = n1%3;
    res2_n2 = n2%2;
    res3_n2 = n2%3;
    res2_n3 = n3%2;
    res3_n3 = n3%3;
    res2_n4 = n4%2;
    res3_n4 = n4%3;
    
    if (res2_n1 == 0 && res3_n1 == 0)
    {
		printf("%d Eh divisivel por 2 e 3\n", n1);
    }
    else
	{
    	if (res2_n1 == 0 && res3_n1 != 0)
    	{
    		printf("%d Eh divisivel apenas por 2\n", n1);
		}
    	if (res2_n1 != 0 && res3_n1 == 0)
    	{
    		printf("%d Eh divisivel apenas por 3\n", n1);
		}
		if (res2_n1 != 0 && res3_n1 != 0)
		{
			printf("%d Nao eh divisivel por 2 ou 3\n", n1);
		}
	}
    if (res2_n2 == 0 && res3_n2 == 0)
    {
		printf("%d Eh divisivel por 2 e 3\n", n2);
	}
	else
	{
		if (res2_n2 == 0 && res3_n2 != 0)
		{
			printf("%d Eh divisivel apenas por 2\n", n2);
		}
		if (res2_n2 != 0 && res3_n2 == 0)
		{
			printf("%d Eh divisivel apenas por 3\n", n2);
		}
		if (res2_n2 != 0 && res3_n2 != 0)
		{
			printf("%d Nao eh divisivel por 2 ou 3\n", n2);
		}
	}
    if (res2_n3 == 0 && res3_n3 == 0)
    {
		printf("%d Eh divisivel por 2 e 3\n", n3);
	}
	else
	{
		if (res2_n3 == 0 && res3_n3 != 0)
		{
			printf("%d Eh divisivel apenas por 2\n", n3);
		}
		if (res2_n3 != 0 && res3_n3 == 0)
		{
			printf("%d Eh divisivel apenas por 3\n", n3);
		}
		if (res2_n3 != 0 && res3_n3 != 0)
		{
			printf("%d Nao eh divisivel por 2 ou 3\n", n3);
		}
	}
    if (res2_n4 == 0 && res3_n4 == 0)
    {
    	printf("%d Eh divisivel por 2 e 3\n", n4);
	}else
	{
		if (res2_n4 == 0 && res3_n4 != 0)
		{
			printf("%d Eh divisivel apenas por 2\n", n4);
		}
		if (res2_n4 != 0 && res3_n4 == 0)
		{
			printf("%d Eh divisivel apenas por 3\n", n4);
		}
		if (res2_n4 != 0 && res3_n4 != 0)
		{
			printf("%d Nao eh divisivel por 2 ou 3\n", n4);
		}
	}
	
	return 0;
}
