//ESTUDO AED PROVA
//FAZER FUNÇÕES PARA INSERIR, REMOVER E IMPRIMIR UMA LISTA ESTATICA ENCADEADA

#include <stdlib.h>
#include <stdio.h>

#define N 150

struct info
{
  int valor;
  int prox;
};
typedef struct info tipoInfo;

struct listaEE
{
  int tamanhoLista;
  int primeiro;
  int ultimo;
  //0 ocupado, 1 livre
  int posLivre[N];
  tipoInfo elemento[N];
};
typedef struct listaEE tipoListaEE;

void inicializaLista (tipoListaEE *listaAux)
{
  int i;
  listaAux->tamanhoLista =0;
  listaAux->primeiro =-1;
  listaAux->ultimo =-1;
  for(i=0; i<N; i++)
  {
    //0 ocupado, 1 livre
    listaAux->posLivre[i] = 1;
    listaAux->elemento[i].valor = 0;
    listaAux->elemento[i].prox = -1;
  }
}

int proxPosLivre(tipoListaEE *listaAux)
{
  int i;
  for (i=0; i<N; i++)
  {
    if (listaAux->posLivre[i] == 1)
    {
      return i;
    }
  }
  return -1;
}

void insereElementoFinal(tipoListaEE *listaAux, int valor, int posicao)  //int posicao fornecida pela proxPosLivre() | coloca ela na main logo acima dessa funcao
{
  //Caso o tamanho da lista seja 0
  if(listaAux -> tamanhoLista == 0)
  {
    listaAux->elemento[0].valor=valor;
    listaAux->elemento[0].prox=-1;
    listaAux -> primeiro = posicao;
    listaAux -> ultimo = posicao;
    listaAux -> posLivre[0] = 0;
    listaAux->tamanhoLista++;
  }
  //Caso o tamanho da lista seja != 0
  //INSERE FINAL
  listaAux->elemento[posicao].valor = valor;
  listaAux->elemento[listaAux->ultimo].prox = posicao;
  listaAux->elemento[posicao].prox = -1;
  listaAux->ultimo = posicao;
  listaAux->posLivre[posicao] = 0;
  listaAux->tamanhoLista++;
}

void insereElementoMeio(tipoListaEE *listaAux, int valor, int posicao) //levando em conta que o número de fato existe.
{
  int encontrou = 0;
  tipoInfo atual = listaAux->elemento[listaAux->primeiro];
  int indice = listaAux->primeiro;

  while(encontrou == 0)
  {
    if(atual.valor < /*insira referencia aqui*/ && listaAux->elemento[atual.prox].valor > /*insira referencia aqui*/) //consdição pra especificar onde inserir no meio
      encontrou = 1;
    else
    {
      indice = atual.prox;
      atual = listaAux->elemento[indice];
    }
  }

  listaAux->elemento[posicao].valor = valor;
  listaAux->elemento[posicao].prox = listaAux->elemento[indice].prox;
  listaAux->elemento[indice].prox = posicao;
  listaAux->tamanhoLista++;
  listaAux->posLivre[posicao] = 0;
}

void insereElementoInicio(tipoListaEE *listaAux, int valor, int posicao)
{
  //INSERE INICIO
  listaAux->elemento[posicao].valor = valor;
  listaAux->elemento[posicao].prox = listaAux->primeiro;
  listaAux->primeiro = posicao;
  listaAux->posLivre[posicao] = 0;
  listaAux->tamanhoLista++;
}

void retiraElemento(tipoListaEE *listaAux, int posicao, int valor)
{
  int i=0, anterior=0;
  int indice = listaAux->primeiro;

  //CHECA SE O NUMERO EXISTE, SE EXISTE MOSTRA A POSICAO (MARCADOR)
  while(indice != -1)
  {
    if(valor == listaAux->elemento[indice].valor)
    {
      //CASO SEJA O PRIMEIRO ELEMENTO
      if(indice == listaAux->primeiro)
      {
        listaAux->posLivre[listaAux->primeiro] = 1; //LIBERA A PRIMEIRA POSICAO
        listaAux->primeiro = listaAux->elemento[listaAux->primeiro].prox; //PRIMEIRO FICA SENDO O PROXIMO
        listaAux->tamanhoLista--; //DIMINUI O TAMANHO DA LISTA
      }
      else
      {
        listaAux->elemento[anterior].prox = listaAux->elemento[indice].prox;
        listaAux->posLivre[indice] = 1;
        listaAux->elemento[indice].valor = 0;
        listaAux->elemento[indice].prox = -1;
        listaAux->tamanhoLista--;
        if(listaAux->ultimo == indice)
        {
          listaAux->ultimo = anterior;
        }
        indice = anterior;
      }
    }
    anterior = indice;
    indice = listaAux -> elemento[indice].prox;
  }
}

void imprimeLista (tipoListaEE *listaAux)
{
  int p=0;
  if(listaAux->tamanhoLista != 0)
  {
    for (p = listaAux -> primeiro; p != -1 ; p = listaAux->elemento[p].prox)
    {
      if (listaAux->tamanhoLista == 1)
      {
        printf("%d ", listaAux -> elemento[listaAux->primeiro].valor);
        //printf("\n");
      }
      else
        printf ("%d ", listaAux->elemento[p].valor);
    }
    printf("\n");
  }

}
