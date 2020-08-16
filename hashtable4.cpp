/*
Author: Jacob Ellis     Date: 16/05/2020

This program is designed to take in a stream of words from a text file and process this for storage in to a hashtable. 
The hash table uses the sum of all ascii codes for each letter within it, in order to determine the key. 
Great care has been taken to try and reduce the size of arrays so that only necessary space is used. 
This hashtable uses linear probing as the basis for rehashing. 
In reference to the second part of this assignment - quicksort is used to order the data, before being output to screen. 
No menu or options have been implemented, as there did not seem to be a need for this. 
I have aimed to keep comments on specific functions with the .h files. 

The files which should accompany this program are: 
hashNode.h/.cpp | hashtable.h/.cpp| quicksort.h | readWords.h | 
*/

#include <iostream>
#include <vector>
#include "readWords.h"
#include "hashtable.h"
#include "quicksort.h"
using namespace std;



int main()
{
    string filename = "";
    cout << "Please enter the name of the file you would like to parse : ";
    cin >> filename;

    filename += ".txt"; // This appends a filepath to the input filename so that custom filenames may be entered. 
    vector<string> words;
    words = readCharFile(filename); // Takes in a string as a filename.

    vector<string> uniqueWords = words;
    removeDuplicate(uniqueWords); // Finds number of unique words. 
    
    cout << endl << endl << "Word count from file:  " << words.size() << endl;
    
    int tableSize = uniqueWords.size();

    hashtable* HT = NULL; // Creates a pointer to the hashtable base class - important for table sizing. 
    int limit; // This limits loops based on which type of hashtable is used. 

    if (tableSize <= 75) // Comparisons used here to choose size of table (using derived classes). 
    {
        HT = new hashtable(100); // Pointer assignment based on number of unique words in file. 
        limit = 100;
    }
    else if ((tableSize > 75) && (tableSize <= 150))
    {
        HT = new hashtableLarge(200);
        limit = 200;

    }
    else if (tableSize > 150 && tableSize<500)
    {
        HT = new hashtableHuge(500); // The assignment was ambigious as to size of text file - largest tested = 500 words.
        limit = 500;
    }
    else if (tableSize > 500)
        cout << "Error - too many unique words - Please re-scale hashtable class!" << endl;


    cout << "Number of unique words present in file: " << tableSize << endl;


    int i=0;
    for (string x: words) // A strange hybrid loop thing, but it worked so decided to keep it (possibly inelegant syntax).
    {
        HT->insert(words[i], uniqueWords.size()); // This inserts words from original text file into the hashtable.
        i++;
    }

    vector <pair<string, int>> copy; // Used to create a copy of the data from hashtable. 
    copy.resize(limit);

    copyArray(HT, copy, tableSize+10); // Takes data from hashtable and places into vector copy.

    quickSort(copy, 0, copy.size()-1);

    cout << "\t\t\t\t\t\t *****<< The results >> ***** " << endl << endl;
    cout << "\t\t\t\t\tWord:\t\t\t\tCount:" << endl << endl;
    for (int i = 0; i < copy.size()-1; i++)
    {
        cout << "\t\t\t\t\t" << copy[i].first << "\t\t\t\t --- \t" << copy[i].second << endl;
    }
    
    cout << endl << endl<< "\t\t\t\t\t\t *****< End of Program >*****" << endl;
}
