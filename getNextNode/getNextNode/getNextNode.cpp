// getNextNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node* parent;
	Node(int data)
	{
		this->value = data;
	}
};
Node* Mostleft(Node *node);
Node* getNextNode(Node* node)
{
	if (node == NULL)
		return node;
	if (node->right != NULL)
		return Mostleft(node->right);
	else {
		Node* parent = node->parent;
		while (parent != NULL&&parent->left!=node)
		{
			node = parent;
			parent = node->parent;
		}
		return parent;
	}
}
Node* Mostleft(Node* node)
{
	if (node == NULL)
		return node;
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}
int main()
{
    return 0;
}

