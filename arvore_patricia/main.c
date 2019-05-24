#include <stdio.h>
#include <stdlib.h>
#define n 8

// depende de TipoChave
typedef unsigned char TipoChave;
// a definir , depende da aplicacao
typedef unsigned char TipoIndexAmp;
typedef unsigned char TipoDib;

typedef enum
{
    Interno, Externo
}No;

typedef struct PatNo
{
    No nt;
    union
    {
        struct
        {
            TipoIndexAmp Index;
            struct PatNo *Esq, *Dir ;
        }NInterno;
        TipoChave Chave;
    }NO;
}PatNo;

typedef PatNo* Arvore;

TipoDib Bit(TipoIndexAmp i,TipoChave k)
{
// Retorna o i−esimo bit da chave k a partir da esquerda
    int c,j;
    if (i==0)
    {
        return 0;
    }else
    {
        c = k;
        for(j=1;j<=n-i;j++)
        {
            c = c/2;
        }
    }
    return (c & 1);
}

short EExterno(Arvore p)
{
// Verifica se p^ e no do externo
    return (p->nt == Externo);
}

Arvore CriaNoInt(int i, Arvore *Esq, Arvore *Dir)
{
    Arvore p;
    p = (Arvore)malloc(sizeof(PatNo));
    p->nt = Interno;
    p->NO.NInterno.Esq = *Esq;
    p->NO.NInterno. Dir = *Dir ;
    p->NO.NInterno.Index = i ;
    return p;
}

Arvore CriaNoExt(TipoChave k)
{
    Arvore p;
    p = (Arvore)malloc(sizeof(PatNo));
    p->nt = Externo ;
    p->NO.Chave = k;
    return p;
}

void Pesquisa(TipoChave k, Arvore t )
{
    if (EExterno( t ))
    {
        if (k == t->NO.Chave)
        {
            printf ( "Elemento encontrado\n" );
        }else
        {
            printf ( "Elemento nao encontrado\n" );
        }
        return;
    }
    if ( Bit(t->NO.NInterno.Index , k)==0)
    {
        Pesquisa(k, t->NO.NInterno.Esq);
    }else
    {
        Pesquisa(k, t->NO.NInterno.Dir );
    }
}

Arvore InsereEntre(TipoChave k, Arvore *t , int i)
{
    Arvore p;
    if (EExterno(*t )||i<(*t)->NO.NInterno.Index)
    { // cria um novo no externo
        p = CriaNoExt(k);
        if ( Bit ( i , k) == 1)
        {
            return ( CriaNoInt( i , t , &p));
        }else
        {
            return ( CriaNoInt( i , &p, t ));
        }
    }
    else
    {
        if ( Bit ((*t)->NO.NInterno.Index , k) == 1)
        {
            (*t)->NO.NInterno. Dir = InsereEntre(k,&(*t)->NO.NInterno.Dir, i );
        }else
        {
            (*t)->NO.NInterno.Esq = InsereEntre(k,&(*t)->NO.NInterno.Esq, i );
        }
        return ( *t );
    }
}

Arvore Insere(TipoChave k, Arvore *t)
{
    Arvore p;
    int i ;
    if (*t == NULL)
    {
        return (CriaNoExt(k));
    }else
    {
        p = *t;
    }while(!EExterno(p))
    {
        if (Bit(p->NO.NInterno.Index,k)==1)
        {
                p = p->NO.NInterno.Dir ;
        }else
        {
            p = p->NO.NInterno.Esq;
        }
    }
// acha o primeiro bit diferente

    i = 1;
    while (( i<= n) & ( Bit(( int)i,k) == Bit(( int)i,p->NO.Chave)))
    {
        i++;
        if (i>n)
        {
            printf ("Erro : chave ja esta na arvore\n");
            return (*t);
        }
        else
        {
            return(InsereEntre(k,t,i));
        }
    }
}

void mostrar(Arvore t)
{

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
