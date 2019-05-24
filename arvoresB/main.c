//Codigo de arvore B com busca em arquivo
//Por Vinicius Avelino Alcantara
//Universidade de Itauna
//Ciu: 71046

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define m 50
#define file "_arquivo.txt"

int cont = -1, count = 0;

typedef struct Registro
{
    int chave;
    char nome[20];
    int idade;
    int ApPage[2];
    int rank;
}Registro;

typedef struct Pagina
{
    int n;
    int pageNum;
    int num;
    Registro r[2*m];
    struct Pagina* p[2*m+1];
}Pagina;

typedef struct Pagina *Apontador;

typedef struct Node
{
    Registro info;
    struct Node *prox;
}node;

typedef Apontador TipoDicionario;

void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir);

void Inicializa(TipoDicionario *Dicionario)
{
    *Dicionario = NULL;
}

void inicia(node *LISTA)
{
    LISTA->prox = NULL;
}

void Reconstitui(Apontador ApPag, Apontador ApPai, int PosPai, int *Diminuiu)
{
    Apontador Aux;
    int DispAux, j;
    if(PosPai<ApPai->n)
    {
        Aux = ApPai->p[PosPai+1];
        DispAux = (Aux->n-m+1)/2;
        ApPag->r[ApPag->n]=ApPai->r[PosPai];
        ApPag->p[ApPag->n+1]=Aux->p[0];
        ApPag->n++;
        if(DispAux>0)
        {
            for (j=1;j<DispAux;j++)
            {
                InsereNaPagina(ApPag,Aux->r[j-1],Aux->p[j]);
            }
            ApPai->r[PosPai]=Aux->r[DispAux-1];
            Aux->n -= DispAux;
            for (j = 0; j < Aux->n; j++)
            {
                Aux->r[j] = Aux->r[j + DispAux];
            }
            for (j = 0; j <= Aux->n; j++)
            {
                Aux->p[j] = Aux->p[j + DispAux];
                *Diminuiu = 0;
            }
        }else
        {
            for (j = 1; j <=m; j++)
            {
                InsereNaPagina(ApPag, Aux->r[j - 1], Aux->p[j]);
            }
            free(Aux);
            for (j = PosPai + 1; j < ApPai->n; j++)
            {   // Preenche vazio em ApPai
                ApPai->r[j - 1] = ApPai->r[j];
                ApPai->p[j] = ApPai->p[j + 1];
            }
            ApPai->n--;
            if (ApPai->n >= m)
            {
                *Diminuiu = 0;
            }
        }
    }else// Aux = Pagina a esquerda de ApPag
    {
        Aux = ApPai->p[PosPai - 1];
        DispAux = (Aux->n - m + 1) / 2;
        for (j = ApPag->n; j >= 1; j--)
        {
            ApPag->r[j] = ApPag->r[j - 1];
        }
        ApPag->r[0] = ApPai->r[PosPai - 1];
        for(j=ApPag->n;j>=0;j--)
        {
            ApPag->p[j + 1] = ApPag->p[j];
        }
        ApPag->n++;
        if(DispAux > 0) // Existe folga: transfere de Aux para ApPag
        {
            for (j = 1; j < DispAux; j++)
            {
                InsereNaPagina(ApPag, Aux->r[Aux->n - j], Aux->p[Aux->n - j + 1]);
            }
            ApPag->p[0] = Aux->p[Aux->n - DispAux + 1];
            ApPai->r[PosPai - 1] = Aux->r[Aux->n - DispAux];
            Aux->n -= DispAux;
            *Diminuiu = 0;
        }else// Fusao: intercala ApPag em Aux e libera ApPag
        {
            for(j = 1; j <=m; j++)
            {
                InsereNaPagina(Aux, ApPag->r[j - 1], ApPag->p[j]);
            }
            free(ApPag);
            ApPai->n--;
            if(ApPai->n >=m)
            {
                *Diminuiu = 0;
            }
        }
    }
}

void Antecessor(Apontador Ap, int Ind, Apontador ApPai, int *Diminuiu) // Antecessor
{
    if (ApPai->p[ApPai->n] != NULL)
    {
        Antecessor(Ap, Ind, ApPai->p[ApPai->n], Diminuiu);
        if(*Diminuiu)
        {
            Reconstitui(ApPai->p[ApPai->n], ApPai, ApPai->n, Diminuiu);
        }
        return;
    }
    Ap->r[Ind - 1] = ApPai->r[ApPai->n - 1];
    ApPai->n--;
    *Diminuiu = ApPai->n <m;
}

void busca(Registro Reg, Apontador pagina)
{
    Registro reg[2*m];
    int i;
    FILE *arq = fopen(file,"r");
    if (arq == NULL)
    exit(1);
    fseek(arq, pagina->pageNum*(2*m*sizeof(Registro)), SEEK_SET);
    fread(reg, (2*m*sizeof(Registro)),1,arq);
    fclose(arq);
    for(i=0;i<2*m;i++)
    {
        if (Reg.chave == reg[i].chave)
        {
            printf("%s%d\n",reg[i].nome,reg[i].idade);
        }
    }
}

void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir)
{
    int k;
    int NAP;
    k = Ap->n;
    NAP = k > 0;
    while(NAP)
    {
        if (Reg.chave >= Ap->r[k - 1].chave)
        {
            NAP = 0;
            break;
        }
        Ap->r[k] = Ap->r[k - 1];
        Ap->p[k + 1] = Ap->p[k];
        k--;
        if(k < 1)
        {
            NAP = 0;
        }
    }
    Ap->r[k] = Reg;
    Ap->p[k + 1] = ApDir;
    Ap->n++;
}

void Ins(Registro Reg, Apontador Ap, int *Cresceu, Registro *RegRetorno, Apontador *ApRetorno)
{
    Apontador ApTemp;
    Registro Aux;
    int i, j;
    if(Ap == NULL)
    {
        *Cresceu = 1;
        *RegRetorno = Reg;
        *ApRetorno = NULL;
        return;
    }
    i = 1;
    while (i < Ap->n && Reg.chave > Ap->r[i - 1].chave)
    {
        i++;
    }
    if (Reg.chave == Ap->r[i - 1].chave)
    {
        printf("chave ja existente: %d \n", Reg.chave);
        *Cresceu = 0;
        return;
    }
    if (Reg.chave < Ap->r[i - 1].chave)
    {
        Ins(Reg, Ap->p[i-1], Cresceu, RegRetorno, ApRetorno);
    }else
    {
        Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);
    }
    if (!*Cresceu)
    {
        return;
    }
    if (Ap->n < 2*m)
    {  //Verificando se a pagina tem espaco
        InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
        *Cresceu = 0;
        return;
    }
    ApTemp = (Apontador) malloc(sizeof(Pagina));
    ApTemp->n = 0;
    ApTemp->p[0] = NULL;
    cont++;
    ApTemp->pageNum = cont;
    if(i<=m+1)
    {
        InsereNaPagina(ApTemp, Ap->r[2*m-1], Ap->p[2*m]);
        Ap->n--;
        InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    }else
    {
        InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);
    }
    for (j=m+2;j<=2*m;j++)
    {
        InsereNaPagina(ApTemp, Ap->r[j - 1], Ap->p[j]);

    }
    Ap->n = m;
    ApTemp->p[0] = Ap->p[m + 1];
    *RegRetorno = Ap->r[m];
    *ApRetorno = ApTemp;
    for(j = m; j < Ap->n+2; j++)
    {
        Aux.chave = 0;
        Aux.rank = 0;
        Ap->r[j] = Aux;
    }
}

void Insere(Registro Reg, Apontador *Ap)
{
    int Cresceu;
    Registro RegRetorno;
    Apontador ApRetorno;
    Apontador ApTemp;

    Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);
    if (Cresceu)// Se arvore cresce na altura pela raiz
    {
        ApTemp = (Apontador) malloc(sizeof(Pagina));
        ApTemp->n = 1;
        ApTemp->r[0] = RegRetorno;
        ApTemp->p[1] = ApRetorno;
        cont++;
        ApTemp->pageNum = cont;
        ApTemp->p[0] = *Ap;
        *Ap = ApTemp;
    //save in file
    }
}

int Imprime2(Apontador p, int Nivel, int aux, int n)
{
    int i;

    if (p == NULL)
    {
        return 0;
    }
    if(Nivel == aux)
    {
        n++;
        printf("No: %d : ",p->pageNum);
        for (i = 0; i < p->n; i++)
        {
            if (p->p[i] !=NULL)
            {
                printf("Apontador: %d ", p->p[i]->pageNum);
            }else
            {
                printf("Apontador: null ");
                printf("chave: %d ", p->r[i].chave);
            }
        }
        printf("\n");
        return n;
    }else
    {
        aux++;
        for (i = 0; i <= p->n; i++)
        {
            Imprime2(p->p[i], Nivel, aux, n);
        }
     }
    return 0;
}

int Imprime(Apontador p, int N, int aux, int n)
{
    int i;

    if(p == NULL)
    {
        return 0;
    }
    if(p->pageNum != aux)
    {
        p->num = N;
        aux = p->pageNum;
        return aux;
    }else
    {
        aux++;
        for (i = 0; i <= p->n; i++)
        {
            Imprime(p->p[i], N, aux, n);
        }
     }
     return 0;
}


void Ret(int Ch, Apontador *Ap, int *Diminuiu)
{
    int Ind, j;
    Apontador WITH;
    Registro Reg;
    if(*Ap == NULL)
    {
        printf("chave nao encontrada: %i\n", Ch);
        *Diminuiu = 0;
        return;
    }
    WITH = *Ap;
    Ind = 1;
    while (Ind < WITH->n && Ch > WITH->r[Ind - 1].chave)
    Ind++;
    if(Ch == WITH->r[Ind - 1].chave)
    {
        Reg.chave = 0;
        Reg.rank = 0;
        WITH->r[Ind -1] = Reg;
        if (WITH->p[Ind - 1] == NULL)
        {  /* Pagina folha */
            WITH->n--;
        }
        *Diminuiu = WITH->n < m;
        for (j = Ind; j <= WITH->n; j++)
        {
            WITH->r[j - 1] = WITH->r[j];
            WITH->p[j] = WITH->p[j + 1];
        }
        return;
    }
    Antecessor(*Ap, Ind, WITH->p[Ind - 1], Diminuiu);
    if(*Diminuiu)
    {
         Reconstitui(WITH->p[Ind - 1], *Ap, Ind - 1, Diminuiu);
    }
    return;
    if(Ch > WITH->r[Ind - 1].chave)
    {
        Ind++;
    }
    Ret(Ch, &WITH->p[Ind - 1], Diminuiu);
    if (*Diminuiu)
    {
        Reconstitui(WITH->p[Ind - 1], *Ap, Ind - 1, Diminuiu);
    }
}

void Retira(int Ch, Apontador *Ap)
{
    int Diminuiu;
    Apontador Aux;
    Ret(Ch, Ap, &Diminuiu);
    if (Diminuiu && (*Ap)->n == 0)
    { /* Arvore diminui na altura */
        Aux = *Ap;
        *Ap = Aux->p[0];
        free(Aux);
    }
}

int main()
{
    Apontador *arv;
    Registro reg;
    int op;
    int chave, i, num = 0;
    arv=(Apontador*) malloc(sizeof(Apontador));
    node *LISTA = (node *) malloc(sizeof(node));
    Inicializa(arv);
    inicia(LISTA);
    while(1)
    {
        printf("Entra com a funcao que deseja ser realizada pelo programa:\n");
        printf(" 1-Inserir\n 2-Remover\n 3-Pesquisar\n 4-Mostrar\n 5-Sair\n");
        scanf("%d", &op);
        if (op==1)
        {
            printf("Entre com a chave primaria:");
           scanf("%d", &chave);
           reg.chave = chave;
           count++;
           reg.rank = count;
           fflush(stdin);
           printf("Entre com o nome:");
           fgets(reg.nome, sizeof(reg.nome), stdin);
           printf("Entre com a idade:");
           scanf("%d", reg.idade);
           if (reg.chave <= 0)
            {
               count--;
            }
            Insere(reg,arv);
        }else if(op==2)
        {
           scanf("%d", &chave);
           reg.chave = chave;
           Retira(reg.chave, arv);
           remove(file);
        }else if(op==3)
        {
            for(i=0; i < 2*m; i++)
            {
                num = Imprime2(*arv, i, 0, num);
            }
        }else if(op==4)
        {
            scanf("%d", &chave);
            reg.chave = chave;
            busca(reg,*arv);
        }else if(op==5)
        {
            printf("O programa sera fechado...\n\n");
        }else
        {
            printf("Opcao Invalida. Voltando ao menu anterior...");
        }

    }
    fflush(stdin);
    return 0;
}
