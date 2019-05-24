#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Autor: Vinicius Avelino Alcantara

int main(int argc, char ** argv)
{
    //declaracao de variaveis

    int x,y,a,b;
    char mina[100];
    //inicialiazição

    printf("Entre com os dados a serem avaliados:");
    scanf("%s",mina);
    b = strlen(mina);
    for(a=0;a<b;a++)
    {
        if(mina[a]=='<')
        {
            x++;
        }else if(mina[a]=='>')
        {
            y++;
        }
    }
    if(x>y)
    {
        printf("Numero de diamantes: %d\n",y);
    }else if(x<y)
    {
        printf("Numero de diamantes: %d\n",x);
    }else if(x==y)
    {
        printf("Numero de diamantes: %d\n",y);
    }else
    {
        printf("Nenhum diamante encontrado!\n");
    }
    system("pause");
    return 0;
}
