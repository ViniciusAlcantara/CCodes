#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    int n,m;
    printf("Entre com o numero de saltos possiveis:");
    scanf(" %d", &n);
    printf("Entre com o numero da pedra onde esta o presente:");
    scanf(" %d", &m);
    if(n==0 && m==0)
    {
        printf("O programa será fechado por falta de dados:\n");
        return 0;
    }else
    {
        if(m%2==0)
        {
            system("cls");
            printf("Deixe-me tentar!\n\n");
        }else
        {
            system("cls");
            printf("Nao tirar sarro de mim!\n\n");
        }
    }
    system("pause");
    return 0;
}
