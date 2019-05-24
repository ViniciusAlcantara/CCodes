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

void Cadastra()
{
    FILE *arquivo = fopen("agenda.txt", "w");
    int i;
    for(i=0;i<num_fichas;i++)
    {
        fprintf(arquivo,"%s %s %s\n", agenda[i].nome, agenda[i].telefone, agenda[i].endereco);
    }
    fclose(arquivo);
}

void Listar()
{
    system("cls");
    printf("\n\n\t\tCONTATOS\n\n");
    int i;
    for(i=0;i<num_fichas;i++)
    {
        printf(" Nome: %s\n Telefone: %s\n Endereco: %s\n\n", agenda[i].nome,agenda[i].telefone,agenda[i].endereco);
    }
}

void Apagar()
{
    int opcao;
    system("cls");
    printf("\n\nTODOS OS SERAO APAGADOS! TEM CERTEZA QUE QUER CONTINUAR? (1 - SIM) (2 - NAO)\n\n");
    scanf(" %d", &opcao);
    if(opcao == 1)
    {
        FILE *arquivo = fopen("agenda.txt", "w");
        fclose(arquivo);
        printf("\n\n\t\tCONTATOS APAGADOS COM SUCESSO!!!\n\n");
        system("pause");
    }
}

void Procurar()
{
    FILE *arquivo = fopen("agenda.txt", "r");
    char nome1[30], nome2[30], telefone[30], endereco[50];
    int n;
    system("cls");
    printf("\nInforme o nome do contato desejado: ");
    setbuf(stdin,NULL);
    gets(nome1);
    while(!feof(arquivo) && n != 1)
    {
        fscanf(arquivo,"%s %s %s",nome2,telefone, endereco);
        if(strcasecmp(nome1,nome2) == 0)
        {
            printf("\n\nO telefone deste contato eh: %s\n\n", telefone);
            n = 1;
        }
    }
    if(n != 1)
    {
        printf("\n\nNao foi possivel encontrar este contato.\nO contato nao existe.\n\n");
    }

    system("pause");
    fclose(arquivo);
}

int main(int argc, char ** argv)
{
    int opcao;
    FILE *arquivo = fopen("agenda.txt", "r");
    char p[30];
    if(!feof(arquivo))
    {
        while(!feof(arquivo))
        {
            fscanf(arquivo,"%s %s %s", agenda[num_fichas].nome,agenda[num_fichas].telefone,agenda[num_fichas].endereco);
            num_fichas++;
        }
    } else
    {
        printf("\nNao ha contatos para serem listados!\n\n");
    }
    fclose(arquivo);
    do
    {
        system("cls");
        printf("\n\n\t\tBem Vindo ao programa AGENDA\n");
        printf("\nMENU");
        printf("\n 1 - Cadastrar Nome e Telefone");
        printf("\n 2 - Listar Nomes e Telefones");
        printf("\n 3 - Apagar contatos");
        printf("\n 4 - Procurar Contato");
        printf("\n 5 - Sair");
        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);
        if(opcao == 1)
        {
            system("cls");
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
            Cadastra();
        } else if (opcao == 2)
        {
            Listar();
            system("pause");
        } else if(opcao == 3)
        {
            Apagar();
        }else if (opcao == 4)
        {
            Procurar();
        }else if(opcao==5)
        {
            printf("Entre com o nome do novo arquivo:");
            gets(p);
            carregaArquivo(p);
        }else if (opcao == 6)
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
        } else
        {
            printf("Opcao invalida! Tente novamente!");
        }
    } while (opcao != 5);
    return 0;
}
