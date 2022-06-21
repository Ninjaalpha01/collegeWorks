#include <stdio.h>
#include <math.h>

int main()
{
	float v;
	int cod;
	
	printf("Insira o preco do produto: ");
	scanf("%f", &v);
	printf("Codigo de origem: ");
	scanf("%d", &cod);
	
	switch(cod)
	{
		case 1:
			printf("%.2f - Sul", v);
			break;
		case 2:
			printf("%.2f - Norte", v);
			break;
		case 3:
			printf("%.2f - Leste", v);
			break;
		case 4:
			printf("%.2f - Oeste", v);
			break;
		case 5:
		case 6:
			printf("%.2f - Nordeste", v);
			break;
		case 7:
		case 8:
		case 9:
			printf("%.2f - Sudeste", v);
			break;
		case 10 ... 20:
			printf("%.2f - Centro Oeste", v);
			break;
		case 25 ... 50:
			printf("%.2f - Nordeste", v);
			break;
		default:
			printf("Erro");
			break;
	}
}
