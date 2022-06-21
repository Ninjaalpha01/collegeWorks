#include <stdio.h>

void main ()
{
    float sl, sb, pro, des;

    printf("Insira seu salario bruto (em R$): ");
    scanf("%f", &sb);
    printf("Insira o valor relacionado a os proventos (em R$): ");
    scanf("%f", &pro);

    if(sb <= 50)
    {
        des = (sb+pro)*0.05;
        sl = sb+pro-des;
        printf("Seu salario liquido eh de: ");
        printf("R$%.2f", sl);
    }
    if(sb > 50)
    {
        des = (sb+pro)*0.1;
        sl = sb+pro-des;
        printf("Seu salario liquido eh de: ");
        printf("R$%.2f", sl);
    }
}
