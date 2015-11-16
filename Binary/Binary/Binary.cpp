// Binary.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Node {
public:
	int value;
	Node *left;
	Node *right;
	Node(int data)
	{
		this->value = data;
	}
};
void preOrderRecur(Node *head)
{
	if (head == NULL)
		return;
	cout << head->value << endl;
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}
void inOrderRecur(Node *head)
{
	if (head == NULL)
		return;
	inOrderRecur(head->left);
	cout << head->value << endl;
	inOrderRecur(head->right);
}
void posOrderRecur(Node *head) {
	if (head == NULL)
		return;
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout << head->value << endl;
}

int main()
{
    return 0;
}

