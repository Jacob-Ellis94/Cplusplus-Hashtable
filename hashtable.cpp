#pragma
#include "hashtable.h"
using namespace std;
#include <iostream>
#include "hashNode.h"



hashtable::hashtable(int size)
{
	for (int i = 0; i < 100; i++) // Self explanatory constructor. 
	{
		table[i] = hashNode(0, "EMPTY", 0);
	}
};

hashtable::hashtable()
{
	//cout << "EMPTY HASH CONSTRUCTOR" << endl;  // This was used to track control flow. 

};

void hashtable::insert(string word, int length)
{
	int key = hashFunction(word, length);
	
	if (table[key].word == "EMPTY")
	{
		table[key].word = word;
		table[key].wordCount = 1;
		table[key].key = key;
	}
	else if (table[key].word == word) // checks to see if word already in table, increments count
	{
		table[key].wordCount++;
	}

	else
	{
		while (table[key].wordCount > 0 && table[key].word != word)
		{
			key++;
		}
		table[key].word = word;
		table[key].wordCount ++;
	}


};


bool hashtable::print(int x)
{
	int i = 0;
	while (i < x)
	{
		cout << "Index: " << i << " -- " << table[i].word << " -- COUNT -- " << table[i].wordCount << endl;
		i++;
		}
	return true;
};

long int hashtable::hashFunction(string x, int length)
{
	long int total = 0;

	for (int i = 0; i < x.size(); i++)
	{
		int ascii = x[i] - 96;
		if (ascii < 1 || ascii>27) // This removes strange symbols that may have passed readWords function.
			continue;
		else
			total += ascii;
	}
	return total%length;
}


hashtableLarge::hashtableLarge(int size)
{
	for (int i = 0; i < 200; i++)
	{
		table[i] = hashNode(0, "EMPTY", 0);
	}

}

hashtableHuge::hashtableHuge(int size)
{
	int i = 0;
	for (int i = 0; i < 500; i++)
	{
		table[i] = hashNode(0, "EMPTY", 0);
	}
}