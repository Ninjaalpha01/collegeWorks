#include <stdio.h>
#include <math.h>

int main()
{
	float x, y;
	
	printf("Insira o ponto (X,Y):\n");
	scanf("%f,%f", &x, &y);
	
	if (x < 0 && y > 0)
		printf("O ponto (%.2f,%.2f) pertence ao 1o quadrante", x, y);
	
	if (x > 0 && y > 0)
		printf("O ponto (%.2f,%.2f) pertence ao 2o quadrante", x, y);
	
	if (x < 0 && y < 0)
		printf("O ponto (%.2f,%.2f) pertence ao 3o quadrante", x, y);
		
	if (x > 0 && y < 0)
		printf("O ponto (%.2f,%.2f) pertence ao 4o quadrante", x, y);
	
	if (x == 0 && y != 0)
		printf("O ponto (%.2f,%.2f) esta sobre o eixo y", x, y);
		
	if (x != 0 && y == 0)
		printf("O ponto (%.2f,%.2f) esta sobre o eixo x", x, y);
		
	if (x == 0 && y == 0)
		printf("O ponto (%.2f,%.2f) esta localizado na origem", x, y);
	
	return 0;
}
