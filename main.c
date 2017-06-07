/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: rodri
 *
 * Created on 30 May 2017, 14:43
 */

// C program for insertion sort
#include <stdio.h>
#include <math.h>
#include <time.h>
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}



/* Driver program to test insertion sort */
int main()
{
    

    int arr[10000], i;
    for (i = 0; i < 10000; i++){
        arr[i] = rand() % 1000;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t tic = clock();

    insertionSort(arr, n);
    
    clock_t toc = clock();
    printf("%lo",toc);
    printf("%lo",tic);
    printf("\n\n\nElapsed: %f seconds\n", (double)(toc - tic) / (double)CLOCKS_PER_SEC);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
    
    return 0;
}