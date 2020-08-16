
#pragma once
#include <stdio.h>
#include <iostream>
#include <cstring>
#include "hashtable.h"
#include <vector>
using namespace std;


// This quicksort algorithm is based on an integer quicksort algorithm that can be found here: 
// https://www.geeksforgeeks.org/quick-sort/
// Adaptations were needed in order to swap paired vectors in the later stages of this program. 

void swap(string* a, int* b, string* c, int* d) // Used to swap the values
{
    string t = *a;
    *a = *c;
    *c = t;
    int s = *b;
    *b = *d;
    *d = s;

}


int partition(vector<pair<string, int>>& vect, int low, int high) // Used to determine partitions
{
    string pivot = vect[high].first;    // pivot 
    int i = (low - 1);  // Index of smaller element 

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or 
        // equal to pivot 

        if ((vect[j].first.compare(pivot) < 0))
        {
            i++;    // increment index of smaller element 
            swap(&vect[i].first, &vect[i].second, &vect[j].first, &vect[j].second);
        }
    }
    swap(&vect[i + 1].first, &vect[i + 1].second, &vect[high].first, &vect[high].second);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(vector<pair<string, int>>& vect, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(vect, low, high);

        // Separately sort elements before 
        // partition and after partition 
        quickSort(vect, low, pi - 1);
        quickSort(vect, pi + 1, high);
    }
}

void copyArray(hashtable* first, vector<pair<string, int>>& second, int x) // Copies data from all occupied elements of hashtable into a vector.
{
    int copyIndex = 0;
    for (int i = 0; i < x; i++)
    {
        if (first->table[i].wordCount == 0)
        {
            continue;
        }
        else if (first->table[i].wordCount > 0)
        {

            second[copyIndex].first = first->table[i].word;
            second[copyIndex].second = first->table[i].wordCount;
            copyIndex++;
        }
    }

    second.resize(copyIndex);


}

