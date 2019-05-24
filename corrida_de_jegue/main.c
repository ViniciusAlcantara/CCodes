#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **  argv)
{
    double n, n1, d, d1, v, v1, t, t1;
    printf("Entre com o numero do jegue1, sua velocidade, a distancia da linha de chegada:");
    scanf(" %lf %lf %lf", &n, &v, &d);
    printf("Entre com o numero do jegue2, sua velocidade, a distancia da linha de chegada:");
    scanf(" %lf %lf %lf", &n1, &v1, &d1);
    t = d/v;
    t1 = d1/v1;
    if(t>t1)
    {
        printf("Campeao da corrida de jegues: %4.lf\n", n);
    }else
    {
        printf("Campeao da corrida de jegues: %4.lf\n", n1);
    }
    system("pause");
    return 0;
}
