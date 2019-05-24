/*  Fila Estatica por Vinicius Avelino Alcantara
    Ciu: 71046
*/

#include <stdio.h>
#include <stdlib.h>
#define Maxtam 100

//Variaveis Globais =====================================================================================================================================================================================================================================

int vet[Maxtam];
int primeiro;
int ultimo;
primeiro = 0;
ultimo = 0;

void inserir(int x)//funcao inserir
{
    vet[ultimo] = x;
    ultimo++;
}

int remover()//funcao para remover
{
    int x,i;
    x = primeiro;
    for(i=0;i<ultimo;i++)
    {
        vet[primeiro+i]=vet[i+1];
    }
    ultimo--;
    return x;
}

void mostrar()//funcao para mostrar vetor na tela
{
    system("cls");
    int i;
    for(i=0;i<ultimo;i++)
    {
        printf("%d\n", vet[i]);
    }
    system("pause");
    return;
}

int main()
{
    int op;
    int x,y,i;
    do
    {
        system("cls");
        printf("Escolha o que o programa fara:\n");
        printf(" 1-Inserir\n 2-Remover\n 3-Mostrar\n 4-Sair\n");
        scanf(" %d", &op);
        if(op==1)
        {
            printf("Digite o numero que deseja inserir:");
            scanf(" %d",&x);
            inserir(x);
        }else if(op==2)
        {
            y = remover();
        }else if(op==3)
        {
            mostrar();
        }else
        {
            return 0;
        }
        i++;
    }while(i<Maxtam);
    system("pause");
    return 0;
}
