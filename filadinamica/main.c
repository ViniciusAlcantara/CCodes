//Programa de fila flexivel, por Vinicius Avelino Alcantara
//Ciu: 71046

#include <stdio.h>
#include <stdlib.h>
#define NULO -1

typedef struct fila
{
    int elemento;//guarda elemento
    struct fila *prox;//guarda endereco de memoria
}Fila;

Fila* primeiro = NULL;//variavel global, aponta o primeiro da fila
Fila* ultimo = NULL;//variavel global, aponta o ultimo da fila

Fila* novaCelula(int elemento, Fila* prox)//funcao para criar nova celula
{
    Fila* nova = (Fila*)malloc(sizeof(Fila));
    nova->elemento = elemento;
    nova->prox = NULL;
    return nova;
}

void start()
{
    primeiro = novaCelula(NULO,NULL);
    ultimo = primeiro;
}

void inserir(int elemento)
{
    ultimo->prox = novaCelula(elemento,NULL);
    ultimo = ultimo->prox;
}

int remover()
{
    int x;
    x = NULO;
    if(primeiro==ultimo)
    {
        printf("Erro ao remover, nao ha elementos!\n");
    }else
    {
        Fila* tmp = primeiro;
        primeiro = primeiro->prox;
        x = primeiro->elemento;
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
    Fila* i;
    for (i = primeiro->prox; i != NULL; i = i->prox)
    {
         printf("%d ", i->elemento);
    }
    printf("] \n");
    system("pause");
}

int main()
{
    int x,y,op;
    start();
    printf("Bem vindo ao programa de Fila Dinamica!!!");
    do
    {
        system("cls");
        printf("Entre com o numero da instrucao que deseja realizar:\n");
        printf(" 1-Inserir\n 2-Remover\n 3-Mostrar\n 4-Sair\n");
        scanf(" %d",&op);
        if(op==1)
        {
            printf("Entre com o numero que deseja inserir:");
            scanf(" %d",&x);
            inserir(x);
        }else if(op==2)
        {
            y = remover();
            printf("Numero removido: %d\n",y);
        }else if(op==3)
        {
            mostrar();
        }else
        {
            return 0;
        }
    }while(1);
    system("pause");
    return 0;
}
