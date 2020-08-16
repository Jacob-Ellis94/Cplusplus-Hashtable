#include "hashNode.h"

hashNode::hashNode(int key, string word, int count) {
	this->key = key;
	this->word = word;
	this->wordCount = count;
}
hashNode::hashNode()
{
	this->key = 0;
	this->word = "EMPTY";
	this->wordCount = 0;
}