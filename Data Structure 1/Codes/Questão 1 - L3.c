#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct copolar
{
	float r;
	float a;
	
} Tipocopolar;

typedef struct cocarte
{
	float x;
	float y;
	
} Tipococarte;

void inserepo(Tipocopolar *p);
void insereca(Tipocopolar *p1, Tipococarte *p2);

int main()
{
	Tipocopolar a;
	Tipococarte b;
	
	inserepo(&a);
	insereca(&a,&b);
	
	printf("O ponto eh definido como (%.2f,%.2f)\n", b.x, b.y);
	
	return 0;
}

void inserepo(Tipocopolar *p)
{
	printf("Insira o raio: ");
	scanf("%f", &(p->r));
	printf("Insira o argumento(rad): ");
	scanf("%f", &(p->a));
}

void insereca(Tipocopolar *p1, Tipococarte *p2)
{
	p2->x = (p1->r)*cos(p1->a);
	p2->y = (p1->r)*sin(p1->a);
}
