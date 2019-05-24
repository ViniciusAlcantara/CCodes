#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m[30][6];
int cont=0;
int n,vet[6];

void CarregaArquivo();
void comparaNumeros();

int inicializar()
{
    int op;
    system("cls");
    printf("PROGRAMA ITAUNA LOTO:\n");
    printf("Opcoes do programa:\n");
    printf(" 1) Carregar novo arquivo de jogos.\n 2) Entrar com numeros sorteados.\n 3) Verificar resultado.\n 4) Sair\n");
    scanf(" %d",&op);
    if(op==1)
    {
        CarregaArquivo();
    }else if(op==2)
    {
        printf("Digite a primeira dezena:");
        scanf(" %d",&vet[0]);
        printf("Digite a segunda dezena:");
        scanf(" %d",&vet[1]);
        printf("Digite a terceira dezena:");
        scanf(" %d",&vet[2]);
        printf("Digite a quarta dezena:");
        scanf(" %d",&vet[3]);
        printf("Digite a quinta dezena:");
        scanf(" %d",&vet[4]);
        printf("Digite a sexta dezena:");
        scanf(" %d",&vet[5]);
        inicializar();
    }else if(op==3)
    {
        printf("Por favor certifique-se de que tenha carregado um arquivo com os jogos realizados e que tenha digitado as dezenas sorteadas.\n");
        comparaNumeros();
    }else
    {
        return 0;
    }
    return 0;
}

void CarregaArquivo()
{
    char x[50];
    int i;
    printf("Entre com o nome do arquivo:(.txt) ");
    fflush(stdin);
    scanf("%s", x);
    FILE *p = fopen(x,"r");
    if(p != NULL)
    {
        while(!feof(p))
        {
            if(cont==0)
            {
                printf("Teste\n\n");
                fscanf(p, "%d", &n);
            }else
            {
                for(i=0;i<6;i++)
                {
                    fscanf(p, " %d", &m[cont][i]);
                }
            }
            cont++;
        }
        printf("Arquivo carregado com sucesso!\n");
        system("pause");
        inicializar();

    }else
    {
        printf("Arquivo nao encontrado!\n");
        system("pause");
        inicializar();
    }
}

void comparaNumeros()
{
    int i,j,a,v=0;
    for(i=0;i<=n;i++)
    {
        a = 0;
        for(j=0;j<6;j++)
        {
            if(m[i][j]==vet[a])
            {
                a++;
            }
        }
        if(a==6)
        {
            printf("Resultado:\n");
            printf("VOCE FOI PREMIADO!\n");
            printf("%02d %02d %02d %02d %02d %02d - Sena\n", m[i][0],m[i][1],m[i][2],m[i][3],m[i][4],m[i][5]);
            v =  v+150000.00;
        }else if(a==5)
        {
            printf("VOCE FOI PREMIADO!\n");
            printf("%02d %02d %02d %02d %02d - Quina\n", m[i][0],m[i][1],m[i][2],m[i][3],m[i][4]);
            v = v + 1500.00;
        }else if(a==4)
        {
            printf("VOCE QUASE FOI PREMIADO!\n");
            printf("%02d %02d %02d %02d %02d - Quadra\n", m[i][0],m[i][1],m[i][2],m[i][3],m[i][4]);
        }else if(a<4)
        {
            printf("INFELIZMENTE VOCE NAO FOI PREMIADO!\n");
        }
    }
    printf("VALOR TOTAL DO PREMIO: %d\n\n",v);
}

int main(int argc, char**argv)
{
    inicializar();
    system("pause");
    return 0;
}
