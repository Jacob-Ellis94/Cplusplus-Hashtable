#pragma once
#include <iostream>
using namespace std;

class hashNode
{
public:
	int key;
	string word;
	int wordCount;
	hashNode(int key, string word, int count);
	hashNode();
};

