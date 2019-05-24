// Codigo da Arvore Binaria por Vinicius Avelino Alcantara
//Ciu: 71046

//Bibliotecas=====================================================================================================================

#include <stdio.h>
#include <stdlib.h>

typedef struct No //novo tipo No
{
  int elemento;
  struct No* esq;
  struct No* dir;
}No;

typedef struct No* Apontador;//mudando nome de apontador de no para No

void pesquisa(int x, Apontador *p)//funcao recursiva para realizar pesquisa na estrutura
{
    if(*p==NULL)//condicao que testa se o ponteiro se anulou, se tiver anulado, a pesquisa foi sem sucesso
    {
        printf("Pesquisa sem sucesso!!! Elemento inexistente nessa estrutura!\n\n");
        return;
    }else if(x<(*p)->elemento)//testa se o elemento pesquisado eh menor que o elemento apontado por p, se for roda a funcao de novo
    {
        pesquisa(x,&(*p)->esq);
        return;
    }else if(x>(*p)->elemento)//testa se o elemento pesquisado eh maior que o apontado por p,se for roda a funcao de novo
    {
        pesquisa(x,&(*p)->dir);
    }else//elemento igual a chave de pesquisa
    {
        x = (*p)->elemento;
    }
}

void insere(int x, Apontador *p)//funcao recursiva para inserir o elemento na posicao vaga
{
    if(*p==NULL)//condicao que testa se o ponteiro se anulou, se tiver anulado, essa a posicao de insercao
    {
        *p = (No*)malloc(sizeof(No));
        (*p)->elemento = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        return;
    }
    if(x<(*p)->elemento)//testa se o elemento pesquisado eh menor que o elemento apontado por p, se for roda a funcao de novo
    {
        insere(x,&(*p)->esq);
        return;
    }
    if(x>(*p)->elemento)//testa se o elemento pesquisado eh maior que o apontado por p,se for roda a funcao de novo
    {
        insere(x,&(*p)->dir);
        return;
    }else//registro igual ao apontado por p,sendo assim nao eh necessario inserir novamente
    {
        printf("Erro ao Registrar! Registro ja existente.\n");
    }
}


void Antecessor(Apontador q, Apontador *r)//funcao recursiva para achar o antecessor do registro pesquisado
{
    if ( (*r)->dir != NULL)//se a direita de r for diferente de NULL ele roda a funcao de novo
    {
        Antecessor(q, &(*r)->dir);
        return;
    }
    q->elemento = (*r)->elemento;
    q = *r;
    *r = (*r)->esq;
    free(q);
}

void Retira(int x, Apontador *p)//funcao para retirar elemento
{
    Apontador Aux;
    if (*p == NULL)//se o ponteiro chegar a NULL significa que o numero a ser removido nao existe na estrututra
    {
        printf("Erro : Registro nao esta na arvore\n");
        return;
    }else if (x < (*p)->elemento)//condicao para testar se o elemento a ser removido eh menor que o apontadopor p
    {
        Retira(x, &(*p)->esq);
        return;
    }else if (x > (*p)->elemento)//condicao para testar se o elemento a ser removido eh maior que o apontadopor p
    {
        Retira(x, &(*p)->dir);
        return;
    }else if ((*p)->dir == NULL)//condicao que testa se o ponteiro que aponta o numero a direita eh igual a NULL
    {
        Aux = *p;
        *p = (*p)->esq;
        free(Aux);
        return;
    }
    if ((*p)->esq != NULL)//condicao que testa se o ponteiro que aponta o numero a esquerda eh diferente de NULL, se for ele chama a funcao antecessor para descobrir o numero a esquerda
    {
        Antecessor(*p, &(*p)->esq);
        return;
    }
    Aux = *p;
    *p = (*p)->dir;
    free(Aux);
}

void Central(Apontador p)//funcao para imprimir na tela a estrutura da arvore binaria
{
    if (p == NULL)
    {
        return;
    }
    Central(p->esq);
    printf("\n%d\n", p->elemento);
    Central(p->dir);
}

int main()
{
    Apontador Raiz = NULL;
    int x, y,op;
    while(1)
    {
        system("cls");
        printf("Entre com a funcao que deseja realizar na arvore:\n\n");
        printf(" 1-Inserir\n 2-Remover\n 3-Mostrar\n 4-Pesquisar\n 5-Sair\n");
        scanf(" %d",&op);
        if(op==1)//condicao que leva a funcao inserir
        {
            printf("Entre com o numero que deseja inserir:");
            scanf(" %d",&x);
            insere(x,&Raiz);
        }else if(op==2)//condicao que leva a funcao remover
        {
            printf("Entre com o numero que deseja remover:");
            scanf(" %d",&y);
            Retira(y,&Raiz);
        }else if(op==3)//condicao que leva a funcao mostrar aqui chamada de Central
        {
            system("cls");
            Central(Raiz);
            system("pause");
        }else if(op==4)//condicao que leva a funcao pesquisar
        {
            printf("Entre com o numero que deseja pesquisar:");
            scanf(" %d",&y);
            pesquisa(y,&Raiz);
            printf("O numero pesquisado eh: %d\n",y);
            system("pause");
        }else//fecha e sai do programa
        {
            return 0;
        }
    }
    system("pause");
    return 0;
}
