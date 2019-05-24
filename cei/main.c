#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    int m,n,i,j;
    int icei[30][30], soma[30], maior,clas[30];
    printf("Entre com o numero de bairros participantes e o numero de modalidades esportivas:");
    scanf(" %d %d", &n, &m);
    for(i=0;i<30;i++)
    {
        soma[i]=0;
    }
    for(i=0;i<n;i++)
    {
        printf("Entre com as medalhas conquistadas pelo bairro %d nessas modalidades: \n", i+1);
        printf("Considere Medalha de Ouro: 3, Prata: 2 e Bronze: 1\n");

        for(j=0;j<m;j++)
        {
            scanf(" %d", &icei[i][j]);
            soma[i] = 0 + soma[i] + icei[i][j];
            clas[i]=soma[i];
        }
    }
    maior = soma[0];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(soma[i]>soma[j])
            {
                maior = soma[i];
                soma[i]=soma[j];
                soma[j]=maior;
            }
        }
        j++;
    }

    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(soma[i]==clas[j])
            {
                printf(" %d", j+1);
            }
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
