#include <stdio.h>
#include <stdlib.h>

/*
    Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself
    for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two
    sorted sub-arrays into one. See following C implementation for details.

    MergeSort(arr[], l,  r)
    If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)

    Time Complexity: Sorting arrays on different machines. Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.
    T(n) = 2T(n/2) + O(n)

    The above recurrence can be solved either using Recurrence Tree method or Master method. It falls in case II of Master Method and solution of the recurrence is 
    O(nLogn)

    Time complexity of Merge Sort is O(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array in two halves and take linear time to merge two halves.
*/

void mergeSort(int low, int high)
{
    //check if low is smaller than highm if not the the array is sorted
    if (low < high)
    {
        //Get the index of the element which is in the middle
        int middle = low + (high - low) / 2;
        //Sort the left side of the array
        mergesort(low, middle);
        //Sort the right side of the array
        mergesort(middle + 1, high);
        //Combine them both
        merge(low, middle, high);
    }
}

void merge(int low, int middle, int high)
{
    //Copy both parts into the helper array
    for (int i = low; i <= high; i++)
    {
        helper[i] = numbers[i];
    }

    int i = low;
    int j = middle + 1;
    int k = low;

    // Copy the smallest values from either the left or the right side back
    //to the original array
    while (i <= middle && j <= high)
    {
        if (helper[i] <= helper[j])
        {
            numbers[k] = helper[i];
            i++;
        }
        else
        {
            number[k] = helper[j];
            j++;
        }
        k++;
    }
    // Copy the rest of the left side of the array into the target array
    while (i <= middle)
    {
        numbers[k] = helper[i];
        k++;
        i++;
    }
}