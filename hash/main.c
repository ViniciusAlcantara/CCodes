#include <stdio.h>
#include <stdlib.h>
#define M 10
#define n 10

typedef char TipoChave[n];
typedef unsigned int Pesos[n];

typedef struct TipoItem
{
    TipoChave chave;
}Item;

typedef struct Celula
{
    Item x;
    struct Celula* Prox;
} Celula;

typedef struct TipoLista
{
    Celula *Primeiro, *Ultimo;
}TipoLista;

typedef TipoLista Lista[M];

void Inicializa(Lista T)
{
    int i;
    for (i = 0; i < M; i++)
    {
        T[i].Primeiro = NULL;
        T[i].Ultimo = NULL;
    }
}

int h(TipoChave Ch, int t)
{
    int x,i;
    x = 0;
    Pesos p;
    srand(time(NULL));
    for(i=0;i<M;i++)
    {
        p[i] = rand()%10;
        x = x + (Ch[i]*p[i]);
    }
    x = x%M;
    return x;
}

Celula* Pesquisa(TipoChave Ch, Pesos p, Lista T)
{
    int i;
    Celula* Ap;
    i = h(Ch, M);
    if(T[i].Primeiro==NULL)
    {
        printf("Pesquisa sem sucesso!\n");
        return NULL;
    }else
    {
        Ap = T[i].Primeiro;
        while ((Ap->Prox->Prox != NULL) &&
        (strncmp(Ch, Ap->Prox->Item.Chave, sizeof(TipoChave)) ))
        {
            Ap = Ap->Prox;
        }
        if (!strncmp(Ch, Ap->Prox->Item.Chave, sizeof(TipoChave)))
        {
            return Ap;
        }else
        {
            return NULL;
        }
    }

}

void Insere(Item x, Pesos p, Lista T)
{
    if (Pesquisa(x.nome, p, T) == NULL)
    {
        Insere(x,&T[h(x.chave,p)]);
    }else
    {
        printf(" Registro ja esta presente\n");
    }
}

void Retira(Item x, Pesos p, Lista T)
{
    Celula* Ap;
    Ap = Pesquisa(x.nome, p, T);
    if (Ap == NULL)
    {
        printf(" Registro nao esta presente\n");
    }else
    {
        Ret(Ap, &T[h(x.nome, p)], &x);
    }
}



int main()
{
    printf("Hello world!\n");
    return 0;
}
