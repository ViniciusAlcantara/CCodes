// Codigo que cria uma Arvore Binaria por Vinicius Avelino Alcantara
//Ciu: 71046

//Bibliotecas=====================================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct No //novo tipo No
{
  int elemento;
  struct No* esq;
  struct No* dir;
}No;

typedef struct No* Apontador;//mudando nome de apontador de no para No
int c = 0;
int v[6];
int i = 0;
int cont[6];

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
        printf("O numero pesquisado existe na estrutura!\n\n");
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
        c++;
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
    c--;
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
        c--;
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
    c--;
}


void Central(Apontador p)//funcao para imprimir na tela a estrutura da arvore binaria
{
    if (p == NULL)
    {
        return;
    }
    Central(p->esq);
    v[i] = p->elemento;
    i++;
    Central(p->dir);
}

void mostrarTARDIS(Apontador Raiz)//funcao para imprimir os tamanhos dos ovos de pascoa dentro das reparticoes da T.A.R.D.I.S
{
    int n;
    for(n=0;n<c;n++)
    {
        v[n] = 0;
    }
    Central(Raiz);
    system("cls");
    system("color 17");
    printf("Organizacao no modelo T.A.R.D.I.S\n\n");
    printf("\t               ||       \n");
    printf("\t              |  |       \n");
    printf("\t             |    |       \n");
    printf("\t             ======        \n");
    printf("\t  =============================\n");
    printf("\t  |                            | \n");
    printf("\t  |   POLICE PUBLIC CALL BOX   | \n");
    printf("\t  |                            | \n");
    printf("\t  |  ==========    ==========  | \n");
    printf("\t  |  |__|__|__|    |__|__|__|  | \n");
    printf("\t  |  |__|__|__|    |__|__|__|  | \n");
    printf("\t  |  |__|__|__|    |__|__|__|  | \n");
    printf("\t  |  |  |  |  |    |  |  |  |  | \n");
    printf("\t  |  ==========    ==========  | \n");
    int i;
    for(i=0;i<c;i=i+2)
    {
        if(i==c-1)
        {
            printf("\t  |                            | \n");
            printf("\t  |                            | \n");
            printf("\t  |  ==========    ==========  | \n");
            printf("\t  |  |        |    |        |  | \n");
            printf("\t  |  |        |    |        |  | \n");
            printf("\t  |  |   %02d   |    |        |  | \n",v[i]);
            printf("\t  |  |   %02d   |    |        |  | \n",cont[i]);
            printf("\t  |  ==========    ==========  | \n");
        }else
        {
            printf("\t  |                            | \n");
            printf("\t  |                            | \n");
            printf("\t  |  ==========    ==========  | \n");
            printf("\t  |  |        |    |        |  | \n");
            printf("\t  |  |        |    |        |  | \n");
            printf("\t  |  |   %02d   |    |  %02d    |  | \n",v[i],v[i+1]);
            printf("\t  |  |   %02d   |    |  %02d    |  | \n",cont[i],cont[i+1]);
            printf("\t  |  ==========    ==========  | \n");
        }
    }
    if(c<=2)
    {
        printf("\t  |                            | \n");
        printf("\t  |                            | \n");
        printf("\t  |  ==========    ==========  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  ==========    ==========  | \n");
        printf("\t  |                            | \n");
        printf("\t  |                            | \n");
        printf("\t  |  ==========    ==========  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  ==========    ==========  | \n");
        printf("\t  |                            | \n");
        printf("\t  |                            | \n");
    }else if(c>2 && c<=4)
    {
        printf("\t  |                            | \n");
        printf("\t  |                            | \n");
        printf("\t  |  ==========    ==========  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  |        |    |        |  | \n");
        printf("\t  |  ==========    ==========  | \n");
        printf("\t  |                            | \n");
        printf("\t  |                            | \n");
    }else
    {
        printf("\t  |                            | \n");
        printf("\t  |                            | \n");
    }
    printf("\t===================================\n");
}

int main()
{
    Apontador Raiz = NULL;
    int x, n,y,op;
    for(n=0;n<6;n++)
    {
        cont[n]=0;
    }
    while(1)
    {
        system("cls");
        printf("Entre com a funcao que deseja realizar na arvore:\n\n");
        printf(" 1-Inserir\n 2-Remover\n 3-Mostrar\n 4-Pesquisar\n 5-Sair\n");
        scanf(" %d",&op);
        if(op==1)//condicao que leva a funcao inserir
        {
            printf("Digite o tamanho do ovo que deseja inserir: (9,10,11,15,20,25): ");
            scanf(" %d",&x);
            if(x==9)
            {
                cont[0]=cont[0]+1;
                insere(x,&Raiz);
            }else if(x==10)
            {
                cont[1]=  cont[1]+1;
                insere(x,&Raiz);
            }else if(x==11)
            {
                cont[2]= cont[2]+1;
                insere(x,&Raiz);
            }else if(x==15)
            {
                cont[3]=cont[3]+1;
                insere(x,&Raiz);
            }else if(x==20)
            {
                cont[4]=cont[4]+1;
                insere(x,&Raiz);
            }else if(x==25)
            {
                cont[5]=cont[5]+1;
                insere(x,&Raiz);
            }else
            {
                printf("Tamanho Invalido!\n\n Voltando ao menu anterior...\n\n");
            }
        }else if(op==2)//condicao que leva a funcao remover
        {
            printf("Entre com o numero que deseja remover:");
            scanf(" %d",&y);
            if(x==9)
            {
                if(cont[0]==1)
                {
                    cont[0]=cont[0]-1;
                    Retira(y,&Raiz);
                }else
                {
                    cont[0]=cont[0]-1;
                }
            }else if(x==10)
            {
                if(cont[1]==1)
                {
                    cont[1]=  cont[1]-1;
                    Retira(y,&Raiz);
                }else
                {
                    cont[1]=  cont[1]-1;
                }

            }else if(x==11)
            {
                if(cont[2]==1)
                {
                    cont[2]=  cont[2]-1;
                    Retira(y,&Raiz);
                }else
                {
                    cont[2]=  cont[2]-1;
                }
            }else if(x==15)
            {
                if(cont[3]==1)
                {
                    cont[3]=  cont[3]-1;
                    Retira(y,&Raiz);
                }else
                {
                    cont[3]=  cont[3]-1;
                }
            }else if(x==20)
            {
                if(cont[4]==1)
                {
                    cont[4]=  cont[4]-1;
                    Retira(y,&Raiz);
                }else
                {
                    cont[4]=  cont[4]-1;
                }
            }else if(x==25)
            {
                if(cont[5]==1)
                {
                    cont[5]=  cont[5]-1;
                    Retira(y,&Raiz);
                }else
                {
                    cont[5]=  cont[5]-1;
                }
            }else
            {
                printf("Tamanho Invalido!\n\n Voltando ao menu anterior...\n\n");
            }

        }else if(op==3)//condicao que leva a funcao mostrar aqui chamada de Central
        {
            system("cls");
            i = 0;
            mostrarTARDIS(Raiz);
            system("pause");
        }else if(op==4)//condicao que leva a funcao pesquisar
        {
            printf("Entre com o numero que deseja pesquisar:");
            scanf(" %d",&y);
            pesquisa(y,&Raiz);
            system("pause");
        }else//fecha e sai do programa
        {
            return 0;
        }
    }
    system("pause");
    return 0;
}
