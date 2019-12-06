//ESTUDO AED PROVA
//FAZER FUNÇÕES PARA INSERIR, REMOVER E IMPRIMIR UMA LISTA DUPLAMENTE ENCADEADA

#include <stdio.h>
#include <stdlib.h>

struct elemento
{
  int info;
  struct elemento *prox;
};
typedef struct elemento tipoElemento;

struct estruturaLDDE
{
  tipoElemento *primeiro;
  tipoElemento *ultimo;
  int tamanhoLista;
};
typedef struct estruturaLDDE tipoLDDE;

void inicializaLista (tipoLDDE *listaAux)
{
  listaAux->primeiro = NULL;
  listaAux->ultimo = NULL;
  listaAux->tamanhoLista = 0;
}

void insereElementoInicio(tipoLDDE *listaAux, int info)
{
  //aloca
  tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));

  //coloca os valores
  novo->info = info;

  //insere caso a lista não exista
  if(listaAux->tamanhoLista==0)
  {
    novo->prox = NULL;
    novo->ant = NULL;
    listaAux->primeiro = novo;
    listaAux->ultimo = novo;
  }
  else//insere no inicio
  {
    listaAux->primeiro->ant = novo;
    novo->prox = listaAux->primeiro;
    novo->ant = NULL;
    listaAux->primeiro = novo;
  }
  listaAux->tamanhoLista++;
}

void insereElementoMeio(tipoLDDE *listaAux, int info, int posit)
{
  //aloca
  tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));
  //coloca os valores
  novo->info = info;
  novo->posicao = posit;
  //insere no insere no meio
  tipoElemento *aux = listaAux->primeiro;
  while(aux != NULL)
  {
    if(aux->posicao == posit)
    {
      novo->prox = aux;
      novo ->ant = aux-> ant;
      aux->ant->prox = novo;
      aux->ant = novo;
      aux = aux->prox;
  }
  listaAux->tamanhoLista++;
}

void insereElementoFinal(tipoLDDE *listaAux, int info)
{
  //aloca espaco
  tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));

  //coloca os valores
  tipoElemento *novo = novo=(tipoElemento*)malloc(sizeof(tipoElemento));
  novo->info = info;
  novo->prox = NULL;

  //caso seja o primeiro elemento
  if(listaAux->tamanhoLista==0)
  {
    novo->prox = NULL;
    novo->ant = NULL;
    listaAux->primeiro = novo;
    listaAux->ultimo = novo;
  }

  else
  {
    novo->prox = NULL;
    novo->ant = listaAux->ultimo;
    listaAux->ultimo->prox = novo;
    listaAux->ultimo = novo;
  }
  listaAux->tamanhoLista++;
}

void imprime(tipoListaDuplaE *listaAux)
{
  tipoElemento *p = listaAux->primeiro; /* variável auxiliar para percorrer a lista */
  while(p != NULL)
  {
    printf("%d ", p->info);
    p = p->prox;
  }
}
