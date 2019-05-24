#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x[1000];

void start()
{
    int i;
    srand(time(NULL));
    for(i=0;i<1000;i++)
    {
        x[i]=rand()%1000;
    }
}

int busca(int y)
{
    int i;
    for(i=0;i<1000;i++)
    {
        if(y==x[i])
        {
            printf("Valor encontrado!!\n\n");
        }else
        {
            printf("Valor não encontrado!!\n\n");
        }
    }
}

int main()
{
    int a;
    printf("Entre com o valor que quer buscar:");
    scanf(" %d",&a);
    system("pause");
    return 0;
}
