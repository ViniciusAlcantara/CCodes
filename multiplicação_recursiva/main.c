#include <stdio.h>
#include <stdlib.h>

int multiplicacao(int x, int y)
{
    int soma;
    if(y == 1)
    {
      return x;
    }
    else
    {
      soma = x + multiplicacao(x,y-1);
    }
    return soma;
}
int main(int argc, char *argv[])
{
    int i,n, mult;
    printf("Entre com os numeros a serem multiplicados:");
    scanf("%d %d",&i,&n);
    mult = multiplicacao(i,n);
    printf("Multiplicacao: %d\n",mult);
    system("pause");
    return 0;
}
