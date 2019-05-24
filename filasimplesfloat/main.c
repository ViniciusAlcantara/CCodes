#include <stdio.h>
#include <stdlib.h>
#define TAM 100

float v[TAM];
int cont;

void inserir(float x)
{
    v[cont] = x;
    cont++;
}

float remover()
{
    float y;
    int i;
    y = v[0];
    for(i=0;i<cont;i++)
    {
        v[i] = v[i+1];
    }
    cont--;
    return y;
}

void mostrar()
{
    int i;
    system("cls");
    for(i=0;i<cont;i++)
    {
        printf(" %.2f",v[i]);
    }
    printf("\n");
    system("pause");
}

int main()
{
    float n;
    float m;
    int opcao;
    int i =0;
    while(i<100)
    {
        system("cls");
        printf("Entre com a funcao que deseja ser realixada pelo programa:\n\n");
        printf(" 1-Inserir\n 2-Remover\n 3-Mostrar\n 4-Sair\n\n");
        scanf(" %d",&opcao);
        if(opcao==1)
        {
            printf("Entre com o numero que deseja inserir na estrutura:");
            scanf(" %f",&n);
            inserir(n);
        }else if(opcao==2)
        {
            m = remover();
            printf("O numero removido foi: %.2f\n",m);
            system("pause");
        }else if(opcao==3)
        {
            mostrar();
        }else
        {
            return 0;
        }
        i++;
    }
    system("pause");
    return 0;
}
