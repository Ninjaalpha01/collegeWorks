#include <stdio.h>

int main()
{
    int cont = 0;
    float x[6], pos[6], media = 0;

    int i;
    for(i=0; i < 6; i++)
    {
        scanf("%f", &x[i]);
        if(x[i] >= 0)
        {
            pos[cont] = x[i];
            media += pos[cont];
            cont++;
        }
    }
    media /= (cont);
    printf("%d valores positivos\n", cont);
    printf("%.1f\n", media);

    return 0;
}