#pragma once
#include "hashNode.h"
class hashtable
{
public:
	hashNode table[100]; // Normal table size.
	hashtable(int size);
	hashtable();
	void insert(string word, int length);
	bool print(int x);
	long int hashFunction(string x, int length);
};

class hashtableLarge :public hashtable
{
public:
	hashNode table[200]; // For larger numbers of unique words.
	hashtableLarge(int size);
};

class hashtableHuge : public hashtable
{
public:
	hashNode table[500]; // This is for an extreme stress test, though could have been made larger.
	hashtableHuge(int size);
};