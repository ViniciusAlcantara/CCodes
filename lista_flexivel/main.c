#include <stdio.h>
#include <stdlib.h>
#define NULO = -1

typedef struct Celula
{
    int elemento;
    struct Celula* prox;
}Celula;

Celula* primeiro = NULL;
Celula* ultimo = NULL;

Celula* novaCelula(int elemento, Celula *prox)
{
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->elemento = elemento;
    nova->prox = prox;
    return nova;
}

void start()
{
    primeiro = novaCelula(NULO,NULL);
    ultimo = primeiro;
}

void inserirInicio(int elemento)
{
    Celula *tmp = primeiro->prox;
    primeiro->prox = novaCelula(elemento, tmp);
    tmp = NULL;
    if(primeiro==ultimo)
    {
        ultimo = primeiro->prox;
    }
}

void inserirFim(int elemento)
{
    ultimo->prox = novaCelula(elemento, NULL);
    ultimo = ultimo->prox;
}

void inserirMeio(int elemento, int p)
{
    Celula *i;
    int cont;
    for(i=primeiro->prox;cont=0;(i->prox!=NULL && cont<p);i=i->prox;cont++);
    if(p<0 || p> cont+1)
    {
        printf("Erro ao inserir (posicao %d (cont = %d) invalida)!", p, cont);
    }else if(p == cont+1)
    {
        inserirFim(elemento);
    }else
    {
        Celula *tmp = novaCelula(elemento, NULL);
        tmp->prox = i->prox;
        i->prox = tmp;
        i = tmp = NULL;
    }

}

int removerInicio()
{
    int elemento = NULO;
    if(primeiro==ultimo)
    {
        printf("Erro lista vazia!!!");
    }else
    {
        Celula *tmp = primeiro->prox;
        primeiro->prox = tmp->prox;
        elemento = tmp->elemento;
        tmp->prox = NULL;
        free(tmp);
        tmp = NULL;
    }
    return elemento;
}

int removerFim()
{
    int elemento = NULO;
    if(primeiro==ultimo)
    {
        printf("Erro lista vazia!!!");
    }else
    {
        elemento = ultimo->elemento;
        Celula* i;
        for(i = primeiro; i->prox != ultimo; i = i->prox);
        ultimo = i;
        i = NULL;
        free(ultimo->prox);
        ultimo->prox = NULL
    }
    return elemento;
}

int removerMeio(int posicao)
{
    Celula *i;
    int resp = NULO,cont;
    if (primeiro == ultimo)
    {
        printf("Erro ao remover (vazia)!");
    }else
    {
        for(i=primeiro;cont=0;(i->prox!=NULL && cont<p);i=i->prox;cont++)
        if(p<0 || p>cont+1)
        {
            printf("Erro ao remover (posicao %d invalida)!", posicao);
        }else if(p==cont+1)
        {
            resp = removerFim();
        }else
        {
            Celula *tmp = i->prox;
            resp = tmp->elemento;
            i->prox = tmp->pox;
            free(tmp);
            i = tmp = NULL;
        }
    }
    return resp;
}

void mostrar()
{
    printf("[");
    Celula *c;
    for(c=primeiro->prox;c->prox!=NULL;c=c->prox)
    {
        printf(" %d",c->elemento);
    }
    printf("]\n");
}

int maior()
{
    return maiorRec(primeiro->prox);
}
int maiorRec(Celula *i)
{
    int resp = NULO;
    if(i!-NULL)
    {
        resp = maior(i->prox);
        if(i->elemento>resp)
        {
            resp = i->elemento;
        }
    }
    return resp;
}

void mostrarInverso()
{
    Celula *j, *i;
    for(i=ultimo;i!=primeiro;i=j)
    {
        printf(" %d",i->elemento);
        for(j=primeiro;j->prox!=i;j=j->prox);
    }
}

int main()
{
    int x;
    inserir(5);
    start();
    printf("LISTA DINAMICA SIMPLESMENTE ENCADEADA\n\n");

    inserirInicio(1);
    inserirInicio(0);
    inserirFim(4);
    inserirFim(5);
    inserirMeio(2, 2);
    inserirMeio(3, 3);
    inserirMeio(6, 6);
    inserirMeio(-1, 0);
    inserirFim(7);
    inserirFim(8);

    printf("Apos insercoes: ");
    mostrar();

    removerMeio(3);
    removerMeio(2);
    removerFim();
    removerInicio();
    removerMeio(0);
    removerMeio(4);

    printf("Apos remocoes: ");
    mostrar();
    return 0;
    x = maior();
    mostrarInverso();
}
