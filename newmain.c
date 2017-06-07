/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.c
 * Author: rodri
 *
 * Created on 16 May 2017, 11:38
 */

// C program for implementation of selection sort
#include <stdio.h>
#include <time.h>

 
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
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[10000], i;
    for (i = 0; i < 10000; i++){
        arr[i] = rand() % 1000;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t tic = clock();

    selectionSort(arr, n);
    
    clock_t toc = clock();
    printf("%lo",toc);
    printf("%lo",tic);
    printf("\n\n\nElapsed: %f seconds\n", (double)(toc - tic) / (double)CLOCKS_PER_SEC);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}