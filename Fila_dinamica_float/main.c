#include <stdio.h>
#include <stdlib.h>
#define NULO -1

typedef struct FILA
{
    float elemento;
    struct FILA* prox;
}fila;

int cont=0;
fila* inicio = NULL;
fila* fim = NULL;

fila* novaCelula(float elemento, fila* prox)
{
   fila* nova = (fila*) malloc(sizeof(fila));
   nova->elemento = elemento;
   nova->prox = prox;
   return nova;
}

void start()
{
    inicio = novaCelula(NULO,NULL);
    fim = inicio;
}

void inserir(float x)
{
    fim->prox = novaCelula(x,NULL);
    cont++;
    fim = fim->prox;
}

float remover()
{
    int x;
    x = NULO;
    if(inicio==fim)
    {
        printf("Erro ao remover, nao ha elementos!\n");
    }else
    {
        fila* tmp = inicio;
        inicio = inicio->prox;
        x = inicio->elemento;
        tmp->prox = NULL;
        free(tmp);
        tmp = NULL;
    }
    return x;
}

void mostrar()
{
    system("cls");
    printf("[ ");
    fila* i;
    for (i = inicio->prox; i != NULL; i = i->prox)
    {
         printf("%.2f ", i->elemento);
    }
    printf("] \n");
    system("pause");
}

int main()
{
    start();
    float m,n;
    int op;
    while(1)
    {
        system("cls");
        printf("Entre com a funcao que deseja ser realizada pelo programa:\n\n");
        printf(" 1-Inserir\n 2-Remover\n 3-Mostrar\n 4-Sair\n\n");
        scanf(" %d", &op);
        if(op==1)
        {
            printf("Entre com o numero que deseja inserir:");
            scanf(" %f",&n);
            inserir(n);
        }else if(op==2)
        {
            m = remover();
            printf("O numero removido foi: %.2f\n",m);
            system("pause");
        }else if(op==3)
        {
            mostrar();
        }else
        {
            printf("O programa sera fechado...\n\n");
            return 0;
        }
    }
    system("pause");
    return 0;
}
