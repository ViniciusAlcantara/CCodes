#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    int a,b,c,vcm;
    printf("Entre com a pontuacao dos concorrentes:");
    scanf(" %d %d %d", &a, &b, &c);
    vcm = 0;
    if(a>b && a<c || a<b && a>c)
    {
        vcm = a;
    }else if(b>a && b<c || b<a && b>c)
    {
         vcm = b;
    }else
    {
        vcm = c;
    }
    printf("Segundo Colocado: %d\n", vcm);
    system("pause");
    return 0;
}
