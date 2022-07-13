#include <stdio.h>

int main()
{
    float salario, perReajuste, reajuste;

    scanf("%f", &salario);
    
    if(salario >= 0 && salario <= 400)
        perReajuste = 0.15;
    else
        if(salario > 400 && salario <= 800)
            perReajuste = 0.12;
        else
            if(salario > 800 && salario <= 1200)
                perReajuste = 0.1;
            else
                if(salario > 1200 && salario <= 2000)
                    perReajuste = 0.07;
                else
                    if(salario > 2000)
                        perReajuste = 0.04;

    reajuste = salario * perReajuste;
    salario += reajuste;
    
    printf("Novo salario: %.2f\n", salario);
    printf("Reajuste ganho: %.2f\n", reajuste);
    printf("Em percentual: %.0f %%\n", (perReajuste * 100));

    return 0;
}