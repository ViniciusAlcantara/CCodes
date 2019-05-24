#include <stdio.h>
#include <stdlib.h>
#define TAM 100

float v[TAM];
int cont=0;

void inserirInicio(float x)
{
    if(cont==0)
    {
        v[0]= x;
    }else
    {
        int i;
        for(i=cont;i>0;i--)
        {
            v[i]= v[i-1];
        }
        v[0]=x;
        cont++;
    }
}

void inserirFim(float x)
{
    v[cont]= x;
    cont++;
}

void inserirMeio(float x, int p)
{
    if(p==0)
    {
        inserirInicio(x);
    }else if(p==cont-1)
    {
        inserirFim(x);
    }else
    {
        int i;
        for(i=cont;i>p;i--)
        {
            v[i]=v[i-1];
        }
        v[p]=x;
        cont++;
    }
}

float removerInicio()
{
    float y;
    y = v[0];
    int i;
    for(i=0;i<cont;i++)
    {
        v[i]= v[i+1];
    }
    cont--;
    return y;
}

float removerFim()
{
    float y;
    y = v[cont-1];
    cont--;
    return y;
}

float removerMeio(int p)
{
    float y;
    y = v[p];
    if(p==0)
    {
        removerInicio();
    }else if(p==cont-1)
    {
        removerFim();
    }else
    {
        int i;
        for(i=p;i<cont;i++)
        {
            v[i]=v[i+1];
        }
        cont--;
    }
    return y;
}

void mostrar()
{
    int i=0;
    system("cls");
    do
    {
        printf(" %.2f",v[i]);
        i++;
    }while(i<cont);
    printf("\n");
    system("pause");
}

int main()
{
    float m,n;
    int i,op,p;
    i=0;
    while(i<TAM)
    {
        system("cls");
        printf("Entre com a opcao que deseja ser realizada pelo programa:\n\n");
        printf(" 1-Inserir\n 2-Remover\n 3-Mostrar\n 4-Sair\n\n");
        scanf(" %d",&op);
        if(op==1)
        {
            system("cls");
            printf("Entre com o numero que deseja inserir:");
            scanf(" %f",&n);
            printf("Entre com o lugar onde deseja inserir:\n");
            printf(" 1-Inserir no inicio\n 2-Inserir no meio\n 3-Inserir no Fim\n");
            scanf(" %d",&op);
            if(op==1)
            {
                inserirInicio(n);
            }else if(op==2)
            {
                printf("Entre com a posicao onde deseja inserir:");
                scanf(" %d",&p);
                inserirMeio(n,p);
            }else if(op==3)
            {
                inserirFim(n);
            }
        }else if(op==2)
        {
            system("cls");
            printf("Entre com o lugar onde deseja remover:\n");
            printf(" 1-Remover no inicio\n 2-Remover no meio\n 3-Remover no Fim\n");
            scanf(" %d",&op);
            if(op==1)
            {
                m = removerInicio();
            }else if(op==2)
            {
                printf("Entre com a posicao onde deseja remover:");
                scanf(" %d",&p);
                m = removerMeio(p);
            }else if(op==3)
            {
                m = removerFim();
            }
            printf("O numero removido foi: %.2f\n\n", m);
            system("pause");
        }else if(op==3)
        {
            mostrar();
        }else
        {
            return 0;
        }
        i++;
    }
    system("pause");
    return 0;
}
