#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
    /*num do funcionario = num,
    horas trabalhadas = hrt,
    valor por hr = vph,
    filhos com menos de 14 anos = f
    salário (hrt*vph) = sal,
    adicional por filho = adc,
    salário final = salf*/

    int num, hrt, f;
    float vph, sal, salf, adc;

    printf("Numero do funcionario: ");
    scanf("%i", &num);
    printf("Numero de horas trabalhadas/mes: ");
    scanf("%i", &hrt);
    printf("Valor recebido/hr: ");
    scanf("%f", &vph);
    printf("Numero de filhos com idade menor que 14 anos: ");
    scanf("%i", &f);

    sal = (hrt*vph);
    adc = f*0.10;
    salf = sal*(++adc);

    printf("Funcionario: \n");
    printf("%i", num);
    printf("\nSalario correspondente: \n");
    printf("R$%.2f", salf);
	
	
}
