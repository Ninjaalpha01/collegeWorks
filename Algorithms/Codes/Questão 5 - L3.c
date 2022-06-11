#include <stdio.h>

int main()
{
	float v, vf, a, b, c, o;
	char cat;
	
	printf("Insira o preco do produto: R$");
	scanf("%f", &v);
	printf("Insira a categoria: ");
	scanf("%s", &cat);
	
	a = 0.5;
	b = 0.25;
	c = 0.15;
	o = 0.05;
	
	switch (cat)
	{
		case 'A':
		case 'a':
			{
				vf = v*a;
				printf("Valor iserido:\nR$%.2f\n", v);
				printf("Percentual de reajuste: 50%%\n");
				printf("Valor final: R$%.2f", vf);
			}
			break;
		case 'B':
		case 'b':
			{
				vf = v*b;
				printf("Valor iserido:\nR$%.2f\n", v);
				printf("Percentual de reajuste: 25%%\n");
				printf("Valor final: R$%.2f", vf);
			}
			break;
		case 'C':
		case 'c':
			{
				vf = v*c;
				printf("Valor iserido:\nR$%.2f\n", v);
				printf("Percentual de reajuste: 15%%\n");
				printf("Valor final: R$%.2f", vf);
			}
			break;
		default:
			{
				vf = v*o;
				printf("Valor iserido:\nR$%.2f\n", v);
				printf("Percentual de reajuste: 5%%\n");
				printf("Valor final: R$%.2f", vf);
			}
			break;
	}
}
