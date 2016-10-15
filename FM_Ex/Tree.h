#pragma once

#include "DataTransform.h"

class Node
{
	vectorBit tData;
	map<unsigned char, int> allist;
	char ch;
	Node *l, *r, *p;
public:
	Node();
	Node(Node& parentNode);
};
class Tree
{
	Node* root;
public:
	Tree();
	~Tree();
	Node* getRoot() const;
};

