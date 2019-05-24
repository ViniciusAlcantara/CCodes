#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

typedef struct ficha
{
    int numregistro;
    char nome[30];
    char telefone[14];
    char endereco[50];
}Ficha;

Ficha agenda[TAM];
int num_fichas=0;

void Cadastra(FILE *arquivo)
{
    int i=0,j;
    j = num_fichas;
    arquivo = fopen("agenda.dat","r+b");
    printf("Numero de fichas: %d",num_fichas);
    if(num_fichas<=1)
    {
        fprintf(arquivo,"%d %s %s %s\n",agenda[j].numregistro, agenda[j].nome, agenda[j].telefone, agenda[j].endereco);
    }else if(num_fichas>1)
    {
        while(!feof(arquivo))
        {
            fscanf(arquivo,"%d %s %s %s",&agenda[i].numregistro, agenda[i].nome, agenda[i].telefone, agenda[i].endereco);
            if(agenda[j].numregistro == agenda[i].numregistro)
            {
                printf("\nNumero de registro duplicado. Dados nao inseridos.\n");
                system("pause");
                num_fichas--;
                return;
            }
            i++;
        }
        for(j=0;j<num_fichas-1;j++)
        {
            fprintf(arquivo,"%d %s %s %s\n",agenda[j].numregistro, agenda[j].nome, agenda[j].telefone, agenda[j].endereco);
        }
        fclose(arquivo);
        printf("Dados incluidos com sucesso!\n");
        system("pause");
    }
    printf("Dados incluidos com sucesso!\n");
    system("pause");
}

void Listar()
{
    system("cls");
    printf("\n\n\t\tCONTATOS\n\n");
    int i;
    if(num_fichas>0)
    {
        for(i=0;i<num_fichas;i++)
        {
            printf(" Numero de registro: %d\n Nome: %s\n Telefone: %s\n Endereco: %s\n\n", agenda[i].numregistro, agenda[i].nome,agenda[i].telefone,agenda[i].endereco);
        }
    }else
    {
        printf("Agenda vazia!\n");
    }
}

void Apagar(FILE *arquivo)
{
    int n,num_reg1;
    int i,j;
    arquivo = fopen("agenda.dat","r+b");
    printf("\nInforme o numero do registro do contato desejado: ");
    setbuf(stdin,NULL);
    scanf(" %d",&num_reg1);
    if(num_fichas==1)
    {
        num_fichas--;
    }else
    {
        for(i=0;i<num_fichas;i++)
        {
            if(agenda[i].numregistro==num_reg1)
            {
                n=i;
                for(j = n; j < num_fichas-1; j++)
                {
                    agenda[j] = agenda[j+1];
                }
                num_fichas--;
            }
            i++;
        }
        for(j=0;j<num_fichas-1;j++)
        {
            fprintf(arquivo,"%d %s %s %s\n", agenda[j].numregistro, agenda[j].nome, agenda[j].telefone,agenda[j].endereco);
        }
        fclose(arquivo);
    }

    system("pause");
}

void Procurar(FILE *arquivo)
{
    char nome[30], telefone[30], endereco[50];
    int n,num_reg1,num_reg2;
    arquivo = fopen("agenda.dat","r+b");
    system("cls");
    printf("\nInforme o numero do registro do contato desejado: ");
    setbuf(stdin,NULL);
    scanf(" %d",&num_reg1);
    while(!feof(arquivo) && n != 1)
    {
        fscanf(arquivo," %d %s %s %s", &num_reg2, nome, telefone, endereco);
        if(num_reg1==num_reg2)
        {
            printf("\nNumero de registro: %d\nNome: %s\nTelefone: %s\nEndereco: %s\n\n",num_reg2,nome, telefone, endereco);
            n = 1;
        }
    }
    if(n != 1)
    {
        printf("\n\nNao foi possivel encontrar este contato.\nO contato nao existe.\n\n");
    }
    fclose(arquivo);
    system("pause");
}

void inicializar(FILE *arquivo)
{
    int opcao;
    char p[30];
    if(arquivo!=NULL)
    {
        while(!feof(arquivo))
        {
            fscanf(arquivo,"%d %s %s %s", &agenda[num_fichas].numregistro,agenda[num_fichas].nome,agenda[num_fichas].telefone,agenda[num_fichas].endereco);
            num_fichas++;
        }
    }else
    {
        printf("\nNao ha contatos para serem listados!\n\n");
    }
    do
    {
        system("cls");
        printf("\n\n\t\tBem Vindo ao programa AGENDA\n");
        printf("\nMENU");
        printf("\n 1 - Cadastrar Nome e Telefone");
        printf("\n 2 - Listar Nomes e Telefones");
        printf("\n 3 - Apagar contato");
        printf("\n 4 - Procurar Contato");
        printf("\n 5 - Carregar novo arquivo de dados");
        printf("\n 6 - Sair");
        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);
        if(opcao == 1)
        {
            system("cls");
            printf("\nDigite o numero de registro:");
            scanf(" %d",&agenda[num_fichas].numregistro);
            printf("\nDigite o nome: ");
            setbuf(stdin,NULL);
            gets(agenda[num_fichas].nome);
            printf("\nDigite o telefone: ");
            setbuf(stdin,NULL);
            gets(agenda[num_fichas].telefone);
            printf("\nDigite o endereco:");
            setbuf(stdin,NULL);
            gets(agenda[num_fichas].endereco);
            num_fichas++;
            Cadastra(arquivo);
        }else if (opcao == 2)
        {
            Listar();
            system("pause");
        }else if(opcao == 3)
        {
            Apagar(arquivo);
        }else if (opcao == 4)
        {
            Procurar(arquivo);
        }else if(opcao==5)
        {
            printf("Entre com o nome do novo arquivo:(.dat)");
            scanf(" %s", p);
            setbuf(stdin,NULL);
            FILE *arquivo = fopen( p,"w+b");
            printf("\nNovo arquivo aberto.\n");
            inicializar(arquivo);
        }else
        {
            system("cls");
            printf("\nTem certeza que deseja sair? (1 - SIM) (2 - NAO)\n");
            scanf(" %d", &opcao);
            if(opcao == 1)
            {
                system("cls");
                printf("\n\nFinalizando...\n\n");
                exit(0);
            }
        }
    } while (opcao != 5);
}

int main(int argc, char ** argv)
{
    FILE *arquivo = fopen("agenda.dat", "r+b");
    inicializar(arquivo);
    return 0;
}
