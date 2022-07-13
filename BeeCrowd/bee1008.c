#include <stdio.h>

int main()
{
    int numId, qntdHr;
    float valorHr;

    scanf("%d", &numId);
    scanf("%d", &qntdHr);
    scanf("%f", &valorHr);

    float salario;

    salario = valorHr*qntdHr;

    printf("NUMBER = %d\n", numId);
    printf("SALARY = U$ %.2f\n", salario);
    
    return 0;
}