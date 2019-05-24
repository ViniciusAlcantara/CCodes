#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char matricula[5];
    char nome[31];
    double notas[3];

}Aluno;

int main(int argc, char *argv[])
{
    Aluno x[80];
    double media[80], soma;
    int i,j;
    i = 0;
    FILE *p = fopen ("registro de alunos.txt", "r");
    if(p!= NULL)
    {
        while(!feof(p))
        {
            soma = 0;
            fscanf(p, "%s", x[i].matricula);
            fscanf(p, "%s", x[i].nome);
            for(j=0;j<3;j++)
            {
                fscanf(p, "%lf", &x[i].notas[j]);
                soma = soma + x[i].notas[j];
            }
            media[i]=soma / 3;
            i++;
        }
        fclose(p);
    }else
    {
        printf("Arquivo nao aberto.\n");
        return 0;
    }
    for(j=0;j<i-1;j++)
    {
        printf("Matricula: %s\n", x[j].matricula);
        printf("Nome: %s\n", x[j].nome);
        if(media[j]>=8.5)
        {
            printf("Media de notas: %.2lf\n",media[j]);
            printf("Muito Bom!\n");
        }else if(media[j]>=7 && media[j]<8.5)
        {
            printf("Media de notas: %.2lf\n",media[j]);
            printf("Bom!\n");
        }else if(media[j]<7)
        {
            printf("Media de notas: %.2lf\n",media[j]);
            printf("Muito preocupante!\n");
        }
    }
    printf("");
    system("pause");
    return 0;
}
