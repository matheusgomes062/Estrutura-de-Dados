//ESTUDO AED PROVA
//FAZER FUNÇÕES PARA INSERIR, REMOVER E IMPRIMIR UMA LISTA DINAMICA

#include <stdio.h>
#include <stdlib.h>

struct elemento
{
  int info;
  struct elemento *prox;
};
typedef struct elemento tipoElemento;

struct lista
{
  tipoElemento *primeiro;
  tipoElemento *ultimo;
  int tamanhoLista;
};
typedef struct lista tipoLista;

void iniciaLista(tipoLista *listaAux)
{
  listaAux->primeiro=NULL;
  listaAux->ultimo=NULL;
  listaAux->tamanhoLista=0;
}

int buscaInfo(tipoLista *listaAux, tipoElemento *novoElemento)
{
  tipoElemento *p = listaAux->primeiro;
  while(p != NULL)
  {
    if(p->info == novoElemento->info)
      return 1;
    p = p->prox;
  }
  return 0;
}

void insereElemento(tipoLista *listaAux, int info)
{
  tipoElemento* novoElemento = (tipoElemento*)malloc(sizeof(tipoElemento));

  novoElemento->bloco.info = info;
  //VE SE O ELEMENTO EXISTE NA LISTA, SE EXISTE NÃO INSERE
  if(buscaInfo(listaAux, novoElemento) == 1)
    return;

  //INSERINDO INICIO LISTA TAM 0
  if(listaAux->tamanhoLista == 0)
  {
    novoElemento->prox = NULL;
    listaAux->primeiro = novoElemento;
    listaAux->ultimo = novoElemento;
  }
  else
  {
    //INSERINDO FIM
    novoElemento->prox = NULL;
    listaAux->ultimo->prox = novoElemento;
    listaAux->ultimo = novoElemento;
  }
  listaAux->tamanhoLista++;
}

void removeElemento(tipoLista *listaAux, int info)
{
  //REMOVE O PRIMEIRO
  if(listaAux->primeiro->info == info)
  {
    tipoElemento *p = listaAux->primeiro;
    listaAux->primeiro = p->prox;
    p = NULL;
    listaAux->tamanhoLista--;
    free(p);
    return;
  }

  //REMOVE O ULTIMO
  else if(listaAux->ultimo->info == info)
  {
    tipoElemento *p = listaAux->primeiro;
    tipoElemento *n = listaAux->ultimo;
    while(p != NULL)
    {
      if(p->prox == n)
      {
        p->prox = NULL;
        listaAux->ultimo = p;
        n = NULL;
        listaAux->tamanhoLista--;
        free(n);
        return;
      }
      p = p->prox;
    }
  }

    //REMOVE DO MEIO
    else if(id != listaAux->ultimo->info && info != listaAux->primeiro->info)
    {
      tipoElemento *p = listaAux->primeiro;
      tipoElemento *aux = listaAux->primeiro->prox;
      while(aux != NULL)
      {
        if(aux->info == info)
        {
          p->prox = aux->prox;
          aux= NULL;
          listaAux->tamanhoLista--;
          free(aux);
          return;
        }
        p = p->prox;
        aux = aux->prox;

      }
    }
}

void imprimir(tipoLista *listaAux)
{
  tipoElemento *p = listaAux->primeiro;

  while(p != NULL)
  {
    printf("info: %d\n", p->info);
    p = p->prox;
  }
}
