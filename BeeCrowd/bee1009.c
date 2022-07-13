#include <stdio.h>
#include <math.h>

int main()
{
    float comissao = 0.15;
    char nome[20];
    float salario, montante;

    scanf("%s", nome);
    scanf("%f", &salario);
    scanf("%f", &montante);

    comissao = montante * comissao;
    float total = salario + comissao;

    printf("TOTAL = R$ %.2f\n", total);

    return 0;
}