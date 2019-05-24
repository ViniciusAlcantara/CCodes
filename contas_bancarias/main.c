#include <stdio.h>
#include <stdlib.h>

typedef struct contas
{
    char numconta[11];
    char nomecliente[51];
    double saldo;
}Contas;

typedef struct movimento
{
    char num1conta[11];
    char movimentacao;
    double valordamovimentacao;
}Movimento;

int main(int argc, char *argv[])
{
    FILE *p = fopen("contas.txt", "a+");
    FILE *out = fopen("movimentacao.txt", "r");
    Contas x[30];
    Movimento y[30];
    int i=0,j=0;
    double n = 0;
    if(p != NULL)
    {
        while(!feof(p))
        {
            fscanf (p, " %s", x[i].numconta);
            fscanf (p, " %s", x[i].nomecliente);
            fscanf (p, " %lf", &x[i].saldo);
            i++;
        }

    } else
    {
        printf ("Nao ha arquivo para ser aberto.\n");
        return 0;
    }
    if(out != NULL)
    {
        while(!feof(out))
        {
            fscanf (out, " %s", y[j].num1conta);
            fscanf (out, " %c", &y[j].movimentacao);
            fscanf (out, " %lf", &y[j].valordamovimentacao);
            j++;
        }
        fclose(out);
    }else
    {
        printf ("Nao ha arquivo para ser aberto.\n");
        return 0;
    }
    for(j=0;j<i-1;j++)
    {
        if(y[j].movimentacao =='D')
        {
            n =  (x[j].saldo) + (y[j].valordamovimentacao);
            printf("%s %s %.2lf\n",x[j].numconta, x[j].nomecliente, n);
            fprintf(p,"%s %s %.2lf\n",x[j].numconta, x[j].nomecliente, n);
        }else if(y[j].movimentacao == 'S')
        {
            n =  (x[j].saldo) - (y[j].valordamovimentacao);
            printf("%s %s %.2lf\n",x[j].numconta, x[j].nomecliente, n);
            fprintf(p,"%s %s %.2lf\n",x[j].numconta, x[j].nomecliente, n);
        }
    }
    fclose(p);
    system("pause");
    return 0;
}
