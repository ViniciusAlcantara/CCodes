//Codigo de fila circular  por Vinicius Avelino Alcantara
// Ciu: 71046

#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{

	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int nItens;

}FilaC;

void novaFila(FilaC *f, int c)
{

	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;

}

void inserir(FilaC *f, int v)
{

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int remover(FilaC *f)
{ // pega o item do comeco da fila

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

int estaVazia(FilaC *f)
{ // retorna verdadeiro se a fila está vazia

	return (f->nItens==0);

}

int estaCheia(FilaC *f)
{ // retorna verdadeiro se a fila esta cheia

	return (f->nItens == f->capacidade);
}

void mostrarFila(FilaC *f)
{
	int cont, i;
	system("cls");
	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++)
    {
		printf("%d\t",f->dados[i++]);
		if (i == f->capacidade)
        {
            i=0;
        }

	}
	printf("\n\n");
}


int main()
{

	int opcao, x;
	int valor;
	FilaC umaFila;
	// cria a fila
	printf("\nCapacidade da fila? ");
	scanf(" %d",&x);
	novaFila(&umaFila, x);
	// apresenta menu
	while( 1 )
    {
        system("cls");
		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf(" %d", &opcao);
		switch(opcao)
		{
			case 0: exit(0);
			case 1: // insere elemento
				if (estaCheia(&umaFila))
                {
					printf("\nFila Cheia!!!\n\n");
				}
				else
                {
					printf("\nValor do elemento a ser inserido? ");
					scanf(" %d", &valor);
					inserir(&umaFila,valor);
				}
				break;
			case 2: // remove elemento
				if (estaVazia(&umaFila))
                {
					printf("\nFila vazia!!!\n\n");
				}
				else
				{
					valor = remover(&umaFila);
					printf("\n%d removido com sucesso\n\n", valor) ;
				}
				break;
				case 3: // mostrar fila
					if (estaVazia(&umaFila))
                    {
						printf("\nFila vazia!!!\n\n");
					}
					else
                    {
						printf("\nConteudo da fila => ");
						mostrarFila(&umaFila);
					}
					break;

				default:
					printf("\nOpcao Invalida\n\n");
		}
	}
	return 0;
}
