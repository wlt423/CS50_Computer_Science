/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"
bool BinarySearch(int value, int values[], int min, int max)
{
int mid =(min + max)/2;
    if(values[mid]==value)
        return true;
    else if (value<values[mid])
        {
        max=mid-1;
        return BinarySearch(value, values, min, max);
        }   
     else
        {
        min=mid+1;
        return BinarySearch(value, values, min, max);
        }
return false;        
        
}

void swap(int* a, int* b)
{
    int temp = *a;
    *b = *a;
    *b = temp;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
int min = 0;
int max = n;
return BinarySearch(value, values, min, max);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
int swaps;   
   do 
    {
   swaps=0;
    for(int i=0; i<n; i++)
        {
        if(values[i]>values[i+1])
            {
            swap(&values[i], &values[i+1]);
            swaps = swaps + 1;
            }
         }
     } 
     while (swaps>0);  
    for(int j=0; j<n; j++)
    {
    printf("%i\n", values[j]);
    }
    return;
}
