#include <stdio.h>
#include <stdbool.h>

int main()
{
    int x;
    bool senha = false;

    do
    {
        scanf("%d", &x);
        if(x == 2002)
            senha = true;
        else
            printf("Senha Invalida\n");
    } while (senha == false);
    printf("Acesso Permitido\n");
}