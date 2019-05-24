
/**
 * Lista Simples Flexivel
 * @author Max do Val Machado
 * @version 1.1 01/2013
 */
#include <stdio.h>
#include <stdlib.h>

#define NULO -1
#define bool      short
#define true      1
#define false     0


//TIPO CELULA ===================================================================
typedef struct Celula
{
    int elemento;        // Elemento inserido na celula.
    struct Celula* prox; // Aponta a celula prox.
} Celula;


//DECLARACOES E INICIALIZACOES ==================================================
Celula* primeiro = NULL;                              //FIG (1)
Celula* ultimo = NULL;                                //FIG (2)

Celula* novaCelula(int elemento, Celula* prox)
{
   Celula* nova = (Celula*) malloc(sizeof(Celula));   //FIG (3)
   nova->elemento = elemento;                         //FIG (4)
   nova->prox = prox;                                 //FIG (5)
   return nova;
}

void start ()
{
   primeiro = novaCelula(NULO, NULL);
   ultimo = primeiro;
}


//INSERIR =======================================================================
void inserirInicio(int elemento)
{
    Celula* tmp = primeiro->prox;
    primeiro->prox = novaCelula(elemento, tmp);
    tmp = NULL;
    if(primeiro == ultimo)
    {
      ultimo = primeiro->prox;
    }
}

void inserirFim(int elemento)
{
   ultimo->prox = novaCelula(elemento, NULL);
   ultimo = ultimo->prox;
}

void inserirMeio(int elemento, int posicao)
{
    Celula* i;
    int cont;
    // Caminhar ate chegar na posicao anterior a insercao
    for(i = primeiro, cont = 0; (i->prox != ultimo && cont < posicao); i = i->prox, cont++);
    // Se indice for incorreto:
    if (posicao < 0 || posicao > cont + 1)
    {
      printf("Erro ao inserir (posicao %d (cont = %d) invalida)!", posicao, cont);
    }else if (posicao == cont + 1)
    {
      inserirFim(elemento);
    }else
    {
      Celula* tmp = novaCelula(elemento, NULL);
      tmp->prox = i->prox;
      i->prox = tmp;
      tmp = i = NULL;
    }
}

//REMOVER =======================================================================
int removerInicio()
{
    int elemento = NULO;
    if(primeiro == ultimo)
    {
      printf("Erro lista vazia!!!");
    } else
    {
      /*******************************************
       * PRIMEIRA OPCAO
       * ****************************************/
      /*
      Celula* tmp = primeiro;
      primeiro = primeiro->prox;
      tmp->prox = NULL;
      free(tmp);
      tmp = NULL;
      elemento = primeiro->elemento;
      */
      /*******************************************
       * SEGUNDA OPCAO
       * ****************************************/
      Celula* tmp = primeiro->prox;
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
    if(primeiro == ultimo)
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
        ultimo->prox = NULL;
    }
    return elemento;
}

int removerMeio(int posicao)
{
    Celula* i;
    int resp = NULO, cont;
    if (primeiro == ultimo)
    {
        printf("Erro ao remover (vazia)!");
    }else
    {
        // Caminhar ate chegar na posicao anterior a insercao
        for(i = primeiro, cont = 0; (i->prox != ultimo && cont < posicao); i = i->prox, cont++);
        // Se indice for incorreto:
        if (posicao < 0 || posicao > cont + 1)
        {
            printf("Erro ao remover (posicao %d invalida)!", posicao);
        } else if (posicao == cont + 1)
        {
            resp = removerFim();
        }else
        {
            Celula* tmp = i->prox;
            resp = tmp->elemento;
            i->prox = tmp->prox;
            tmp->prox = NULL;
            free(tmp);
            i = tmp = NULL;
        }
    }
    return resp;
}

//MOSTRAR =======================================================================
void mostrar()
{
    printf("[ ");
    Celula* i;
    for (i = primeiro->prox; i != NULL; i = i->prox)
    {
         printf("%d ", i->elemento);
    }
    printf("] \n");
}

//PESQUISAR =====================================================================
bool pesquisar(int x)
{
    bool retorno = false;
    Celula* i;
    for (i = primeiro->prox; i != NULL; i = i->prox)
    {
      if(i->elemento == x)
      {
         retorno = true;
         i = ultimo;
      }
    }
    return retorno;
}

int main(int argc, char** argv)
{
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
}
