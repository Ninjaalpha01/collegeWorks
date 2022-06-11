#include <stdio.h>
#include <math.h>

/*
e = exponencial,
d = denominador,
f = helper pra não alterar d,
g = fatorial do denominador,
t = termos em ordem crescente.
*/

int main()
{
	int x, n, d, e, t, f;
	long int g;
	float som;
	
	printf("Insira o valor de X: ");
	scanf("%d", &x);
N:
	printf("Insira a quantidade de termos n: ");
	scanf("%d", &n);
	
	if (n > 0)
	{
		d = 1;
		e = 1;
		som = 0;
		
		for (t=1; t <= n; t++)
		{
			f = d;
			g = 1;
			
			for (; f > 0; f--)
				g = g*f;
				
			
			if (t%2 == 1)
				som = som+((float)pow(x,e)/g);
			else
				som = som-((float)pow(x,e)/g);
			
			if (e == 1)
				e++;
			else
				e = e+2;
			
			d = d+2;
		}
		
		printf("Soma total = %f", som);
	}
	else
	{
		printf("Erro. Tente novamente\n");
		goto N;
	}
}
