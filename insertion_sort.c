/*
  INSERTION SORT ALGORITHM
  1- SET A MARKER FOR THE SORTED SECTION AFTER THE FIRST ELEMENT
  2- REAPEAT THE FOLLOWING UNTIL UNSORTED SECTION IS EMPTY:
      -SELECT THE FIRST UNSORTED ELEMENT
      -SWAP OTHER ELEMENTS TO THE RIGHT TO CREATE THE CORRECT POSITION AND SHIFT THE UNSORTED ELEMENT.
      -ADVANCE THE MARKER TO THE RIGHT ONE ELMENT

  INSERTION SORT TAKES MAXIMUM TIME TO SORT IF ELEMENTS ARE SORTED IN REVERSE ORDER. AND IT TAKES MINIMUM TIME (ORDER OF N) WHEN ELEMENTS ARE ALREADY SORTED.
  TIME COMPLEXITY: O(N*2)

  Problema com o algoritmo de ordenação por inserção: 
  – Troca itens adjacentes para determinar o ponto de inserção. 
  – São efetuadas n − 1 comparações e movimentações quando o menor item está na posição mais à direita no vetor.

*/

#include <stdio.h>
#include <stdlib.h>

//INSERTION_SORT
void insertionSort(int arr *, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1; //vai valer para o valor do array original

        /* Move os elementos do arr[0..i-1], que são
          maiores que a chave, para uma posição na frente
          de sua localização atual, sempre sobrepondo */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; //coloca o valor no lugar certo, se for o valor errado, mantem
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 11, 1, 5, 6};
    insertionSort(arr[], 5);
    return 0;
}
