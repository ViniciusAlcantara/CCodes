//Prova para dia 27/04/2015
//Jogo da forca por Vinicius Avelino Alcantara
//Ciu: 71046

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* palavra(int x)
{
    char p[x][50];
    int i,n;
    char a[50];
    for(i=0;i<x;i++)
    {
        printf("Entre com a palavra que deseja jogar: ");
        fflush(stdin);
        gets(p[i]);
    }
    srand(time(NULL));
    n = rand()%x-1;
    strcpy(a,p[n]);
    return a;
}

void start(char *traco,int n)
{
    int a;
    for(a=0;a<n;a++)
    {
        traco[a] = '_';
        printf(" %c",traco[a]);
    }
    printf("\n");
}

void forca(char *palavra)
{
    int a,i,x=0,c=0,erros=0;
    x = strlen(palavra);
    system("cls");
    char traco[x];
    start(traco,x);
    char ch, boneco[6];
    while(c<x && erros<6)
    {
        printf("Entre com a letra que voce deseja jogar para esta palavra\n");
        scanf(" %c",&ch);
        for(i=0;i<x;i++)
        {
            if(ch==palavra[i])
            {
                c++;
                traco[i]=palavra[i];
            }
        }
        system("pause");
        system("cls");
        for(a=0;a<x;a++)
        {
            printf(" %c",traco[a]);
        }
        printf("\n");
        if(i==x-1 && c==0)
        {
            erros++;
            if(erros==6)
            {
                system("cls");
                printf("--------------------\n");
                printf("|                  / \n");
                printf("|                 /   \n");
                printf("|                0 \n");
                printf("|               /|\  \n");
                printf("|               / \      \n");
                printf("|                        \n ");
                printf("|                         \n");
                printf("|                      \n");
                printf("|  \n");
                printf(" Voce perdeu!!!!\n");
                printf(" A palavra eh: %s",palavra);
            }
        }
    }
}

int main()
{
    int x,op;
    while(1)
    {
        system("cls");
        printf("Jogo da forca(Jogo a ser joga do por duas pessoas): \n 1-Jogar \n 2-Sair\n");
        scanf(" %d",&op);
        if(op==1)
        {
            printf("Entre com o numero de palavras que deseja ter no programa: ");
            scanf(" %d",&x);
            char jogo[50],*h;
            h = palavra(x);
            strcpy(jogo,h);
            forca(jogo);
        }else if(op==2)
        {
            printf("O programa sera fechado...\n");
            return 0;
        }else
        {
            printf("Opcao invalida, voltando ao menu anterior...\n");
        }

    }
    system("pause");
    return 0;
}
