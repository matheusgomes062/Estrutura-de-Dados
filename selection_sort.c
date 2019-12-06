/*
  SELECTION SORT ALGORITHM SORTS AN ARRAY BY REPEATELY FINDING THE MINIMUM ELEMENT (CONSIDERING ASCENDING ORDER) FROM UNSORTED PART AND PUTTING IT AT THE BEGINNNING.
  THE ALGORITHM MAINTAINS TWO SUBARRAYS IN A GIVEN ARRAY
    1-THE SUBARRAY WHICH IS ALREADY SORTED
    2-REMAINING SUBARRAY WHICH IS UNSORTED
  IN EVERY INTERATION OF SELECTION SORT, THE MINIMUM ELEMENT FROM THE UNSORTED SUBARRAY IS PICKED AND MOVED TO THE SORTED SUBARRAY.
  LOGIC: ARRAY IS CONSIDERED INTO TWO PARTS UNSORTED AND SORTED (INITIALLY WHOLE ARRAY IS UNSORTED)
  SELECTION 1. SELECT THE LOWEST ELEMENT IN THE REMAINING ARRAY
  SWAPPING 2. BRING IT TO THE STARTING POSITION

  TIME COMPLEXITY: O(N^2)
  THE GOOD THING ABOUT SELECITON SORT IS IT NEVER MAKES MORE THAN O(N) SWAPS AND CAN BE USEFUL WHEN MEMORY WRITE IS A COSTLY OPERATION

*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Acha o menor elemento de um array desordenado
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx])
            min_idx = j;
        }
        // Troca o elemento de menor valor achado pela primeira posição
        swap(&arr[min_idx], &arr[i]);
    }
}
