#include <stdio.h>

int main()
{
    int cod, qntd;
    float total;

    scanf("%d", &cod);
    scanf("%d", &qntd);

    if(cod == 1)
        total = 4 * qntd;
    else
        if(cod == 2)
            total = 4.5 * qntd;
        else
            if(cod == 3)
                total = 5 * qntd;
            else
                if(cod == 4)
                    total = 2 * qntd;
                else
                    if(cod == 5)
                        total = 1.5 * qntd;

    printf("Total: R$ %.2f\n", total);

    return 0;
}