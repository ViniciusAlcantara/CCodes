//Bibliotecas ========================================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
//Declaracao de variaveis ============================================================================================
    int funcionario[10], i=0, n;
    double comissao[10], desvio[10], media=0, maior=0, menor=0, desvio_padrao=0,soma = 0, variancia=0;
    FILE *p = fopen("registro e comissoes.txt", "r");
    if (p != NULL)// teste para verificar se o arquiv
    {
      while(!feof(p))
      {
            fscanf (p, "%d", &funcionario[i]);
            fscanf (p, "%lf", &comissao[i]);
            soma = soma + comissao[i];
            i++;
      }
      fclose(p);
    } else
    {
        printf ("Nao ha arquivo para ser aberto.\n");
        return 0;
    }
    menor = comissao[0];
    for(n=0; n<i; n++)
    {
        if(menor>comissao[n])
        {
            menor = comissao[n];
        }
        n++;
    }
    media = soma / i;
    maior = comissao[0];
    for(n=0; n<i; n++)
    {
        if(comissao[n]>maior)
        {
            maior = comissao[n];
        }
        desvio[n]= comissao[n]-media;
        desvio[n]= desvio[n]*desvio[n];
        variancia = variancia + desvio[n];
    }
    variancia = variancia/n;
    desvio_padrao = sqrt(variancia);
    printf("Media das comissoes: %.2lf\n\n", media);
    printf("Maior valor das comissoes: %.2lf\n\n", maior);
    printf("Menor valor das comissoes: %.2lf\n\n", menor);
    printf("Desvio Padrao do valor das comissoes: %.2lf\n\n", desvio_padrao);
    system("pause");
    return 0;
}
