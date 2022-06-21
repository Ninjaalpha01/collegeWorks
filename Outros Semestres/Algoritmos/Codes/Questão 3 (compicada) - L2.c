#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void main()
{
    int num1, num2, num3, num4, x, y;
    float res1, res2, res3, res4, res_1, res_2, res_3, res_4;

    x = 0;
    y = 0;
    printf("Insira os quatro numeros em sequencia abaixo:\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
    scanf("%d", &num4);

    res1 = num1%2;
    res2 = num2%2;
    res3 = num3%2;
    res4 = num4%2;
    res_1 = num1%3;
    res_2 = num2%3;
    res_3 = num3%3;
    res_4 = num4%3;

    if(res1 == 0 || res2 == 0 || res3 == 0 || res4 == 0)
    {
        printf("Divisiveis por 2:\n");
        x = 1;

        if(res1 == 0)
        {
            printf("%d\t", num1);
        }
        if(res2 == 0)
        {
            printf("%d\t", num2);
        }
        if(res3 == 0)
        {
            printf("%d\t", num3);
        }
        if(res4 == 0);
        {
            printf("%d", num4);
        }
    }
    else
        printf("");

    if(res_1 == 0 || res_2 == 0 || res_3 == 0 || res_4 == 0)
    {
        printf("\nDivisiveis por 3:\n");
        y = 1;

        if(res_1 == 0)
        {
            printf("%d\t", num1);
        }
        if(res_2 == 0)
        {
            printf("%d\t", num2);
        }
        if(res_3 == 0)
        {
            printf("%d\t", num3);
        }
        if(res_4 == 0)
        {
            printf("%d", num4);
        }
    }
    else
        printf("");
    if(x==0 && y==0)
        printf("\nNenhum dos numeros sao divisiveis por 2 ou 3.");
}
