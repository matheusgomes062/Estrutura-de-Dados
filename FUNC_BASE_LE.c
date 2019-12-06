//ESTUDO AED PROVA
//FAZER FUNÇÕES PARA INSERIR, REMOVER E IMPRIMIR UMA LISTA ESTATICA

#include <stdio.h>
#include <stdlib.h>

#define N 150

struct listaES
{
  int ultimo;
  int tamanhoLista;
  int lista[N];
};
typedef struct listaES tipoListaES;

void inicializaLista(tipoListaES *listaAux)
{
  int i;
  listaAux->tamanhoLista = 0;
  for(i=0; i<N; i++)
  {
    listaAux->lista[i] = 0;
  }
  listaAux->ultimo = 0;
}

// void insereElementoInicio(tipoListaES *listaAux, int info)
// {
//   int i=0;
//
//   listaAux->tamanhoLista++;
//
//   //empurra geral pra frente
//   for(i=listaAux->tamanhoLista; i>1; i--)
//   {
//     listaAux->lista[i]=listaAux->lista[i-1];
//   }
//   //insere elemento ao comeco da lista
//   listaAux->lista[0] = info;
// }

// void insereElementoMeio(tipoListaES *listaAux, int info)
// {
//   int i=0, j=0;
//
//   listaAux->tamanhoLista++;
//
//   for(i=0; i<listaAux->tamanhoLista; i++)
//   {
//     if(listaAux->lista[i] == info)
//     {
//       //substitui os seguintes
//       for(j=listaAux->tamanhoLista; i>listaAux->lista[i]; i--)
//       {
//         listaAux->lista[j]=listaAux->lista[j-1];
//       }
//       //insere elemento ao meio da lista
//       listaAux->lista[i] = info;
//     }
//   }
//   listaAux->ultimo = listaAux -> tamanhoLista-1;
// }

void insereElementoFinal(tipoListaES *listaAux, int info)
{
  listaAux->tamanhoLista++;

  //insere elemento ao final da lista
  listaAux->lista[listaAux -> tamanhoLista-1] = info;

  listaAux->ultimo = listaAux -> tamanhoLista-1;
}

void removeElemento(tipoListaES *listaAux, int info)
{
  int i=0, j=0;
  //percorre a lista pra ver se existe o elemento em questão
  for(i=0; i<listaAux->tamanhoLista; i++)
  {
    //se existe remove
    if(listaAux->lista[i] == info)
    {
      //substitui os seguintes
      for(j=i; j<listaAux->tamanhoLista; j++)
      {
        listaAux -> lista[j] = listaAux -> lista[j+1];
      }
      listaAux->tamanhoLista--;
    }
  }
}

void imprimeLista(tipoListaES *listaAux)
{
  int i;
  for(i=0; i< listaAux -> tamanhoLista; i++)
  {
    printf("%d ", listaAux -> lista[i]);
  }
}
