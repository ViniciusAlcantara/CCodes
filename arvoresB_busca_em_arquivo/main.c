//Codigo de arvore B com busca em arquivo
//Por Vinicius Avelino Alcantara
//Universidade de Itauna
//Ciu: 71046

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define file "arquivo.txt"
#define m 100

int aumentou, diminuiu;

typedef struct Aluno
{
    char* nome;
    char* ciu;
}Aluno;

typedef struct Pagina
{
    int n;
    Aluno k[2*m];
    struct Pagina* l[2*m+1];
}Pagina;

typedef Pagina* Apontador;

void inicializa(Apontador *Raiz);
void insere(int chave,Apontador *x);
void ins(int chave, Apontador*x,int c, Apontador apr,Aluno ar);

void inicializa(Apontador *Raiz)
{
    *Raiz = NULL;
}

Aluno aluno[2*m];

void insere(int chave,Apontador *x)
{
    int c;
    Apontador apr;
    Apontador temp;
    Aluno ar;
    ins(chave,*x,&c,&apr,&temp,&ar);
}

void ins(Aluno chave, Apontador*x,int c, Apontador *apr,Aluno *ar)
{
    Apontador temp;
    Aluno aux;
    int i, j;
    if(x==NULL)
    {
        *c = 1
        ar =
    }
}

void mostrar()
{
    int i;
    for(i=0;i<2*m;i++)
    {
        printf("O nome do aluno eh: %s", aluno[i].nome);
        printf("O Ciu desse aluno eh: %s",aluno[i].ciu);
    }
}



int main()
{
    Apontador *Raiz=NULL;
    Aluno reg;
    int op;
    int chave, i, num = 0;
    Inicializa(Raiz);
    while(1)
    {
        printf("Entra com a funcao que deseja ser realizada pelo programa:\n");
        printf(" 1-Inserir\n 2-Remover\n 3-Mostrar\n 4-Pesquisar\n 5-Sair\n");
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
            busca(chave,*Raiz);
        }else if(op==5)
        {
            printf("O programa sera fechado...\n\n");
        }else
        {
            printf("Opcao Invalida. Voltando ao menu anterior...");
        }

    }
    fflush(stdin);
    system("pause");
    return 0;
}
