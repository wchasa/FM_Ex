#include "stdafx.h"
#include "Tree.h"


Node::Node()
{
	l = nullptr;
	r = nullptr;
	p = nullptr;
}

Node::Node(Node& parentNode): Node()
{
	p = &parentNode;
}



Tree::Tree()
{
	root = new Node();
}

Tree::~Tree()
{
}

Node* Tree::getRoot() const
{
	return root;
}
