#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int i=0, n=0, m=0, j;
    double temperaturas[121], desvio[121], media=0, maior=0, menor=0, desvio_padrao=0,soma = 0, variancia=0;
    FILE *p = fopen("temperaturaAtual.txt", "r");
    if (p != NULL)
    {
      while(!feof(p))
      {
            fscanf (p, "%lf", &temperaturas[i]);
            soma = soma + temperaturas[i];
            i++;
      }
      fclose(p);
    } else
    {
        printf ("Nao ha arquivo para ser aberto.\n");
        return 0;
    }
    menor = temperaturas[0];
    for(j=0; j<i; j++)
    {
        if(menor>temperaturas[j])
        {
            menor = temperaturas[j];
        }
        n++;
    }
    media = soma / n;
    maior = temperaturas[0];
    for(j=0; j<i; j++)
    {
        if(temperaturas[j]>maior)
        {
            maior = temperaturas[j];
        }
        desvio[j]= temperaturas[j]-media;
        if(temperaturas[j]-media>0)
        {
            m++;
        }
        desvio[j]= desvio[j]*desvio[j];
        variancia = variancia + desvio[j];
    }
    variancia = variancia/n;
    desvio_padrao = sqrt(variancia);
    printf("Media das temperaturas: %.2lf\n\n", media);
    printf("Maior temperatura: %.2lf\n\n", maior);
    printf("Menor temperatura: %.2lf\n\n", menor);
    printf("Desvio Padrao das temperaturas: %.2lf\n\n", desvio_padrao);
    printf("Numero de dias nos quais a temperatura foi a superior a temperatura media: %d\n", m);
    system("pause");
    return 0;
}

