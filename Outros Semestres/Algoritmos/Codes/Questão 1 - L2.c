#include <stdio.h>
#include <math.h>

void main()
{
    float alt, pes;
    int sex;

    printf("Digite sua altura (em metros): ");
    scanf("%f", &alt);
    printf("Agora digite seu sexo (1 - masculino e 0 - feminino):\n");
    scanf("%d", &sex);

    if(sex == 1)
    {
        pes = 72.7*alt-58;
        printf("Seu peso ideal eh de: ");
        printf("%.3fKg", pes);
    }
    if(sex == 0)
    {
        pes = (62.1*alt)-44.7;
        printf("Seu peso ideal eh de: ");
        printf("%.3fKg", pes);
    }
}
