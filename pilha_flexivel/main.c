/**
 * Pilha Flexivel
 */
#include <stdio.h>
#include <stdlib.h>
#define NULO -1


typedef struct Celula {
    int elemento;        // Elemento inserido na celula.
    struct Celula* prox; // Aponta a celula prox.
} Celula;


Celula* novaCelula(int elemento, Celula* prox) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = prox;
   return nova;
}


Celula* topo = NULL; // Sem celula cabeca.


//Mostra os elementos separados por espacos, comecando do topo.
void mostrar() {
   printf("[ ");

   Celula* c = topo;
   while (c != NULL) {
      printf("%d ", c->elemento);
      c = c->prox;
   }

   printf("] \n");
}


// Insere elemento na pilha (politica FILO).
void inserir(int elemento) {
   Celula* nova = novaCelula(elemento, topo);
   topo = nova;
}

// Remove elemento da pilha (politica FILO).
int remover() {

   int elemento = NULO;

   if (topo == NULL) {
      printf("Erro ao remover!");

   } else {
      elemento = topo->elemento;
      Celula* tmp = topo;
      topo = topo->prox;
      tmp->prox = NULL;
      free(tmp);
      tmp = NULL;
   }

   return elemento;
}

//Exercicio: Faca um metodo que retorne a soma dos elementos da pilha
int soma(){
   int soma = 0;
   Celula* i;

   for(i = topo; i != NULL; i = i->prox){
      soma += i->elemento;
   }
   return soma;
}

//Exercicio: Faca um metodo RECURSIVO que retorne a soma dos elementos da pilha
int somaRec(){
   return somaRecur(topo);
}

int somaRecur(Celula* i){
   int resp;
   if(i == NULL){
      resp = 0;
   } else {
      resp = i->elemento + somaRecur(i->prox);
   }
   return resp;
}

int main(int argc, char** argv) {
   printf("PILHA FLEXIVEL\n\n");

   inserir(0);
   inserir(1);
   inserir(2);
   inserir(3);
   inserir(4);
   inserir(5);

   printf("Apos insercoes: ");
   mostrar();

   remover();
   remover();
   remover();

   printf("Apos remocoes: ");
   mostrar();

   return 0;
}
