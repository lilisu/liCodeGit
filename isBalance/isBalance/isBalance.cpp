// isBalance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->value = data;
	}
};
int getHeight(Node* head, int level, bool& res);
bool isBalance(Node* head)
{
	bool res = true;
	getHeight(head, 1, res);
	return res;
}
int getHeight(Node* head, int level, bool& res)
{
	if (head == NULL)
		return level;
	int left = getHeight(head->left, level+1, res);
	if (!res)return level;
	int right = getHeight(head->right,level+1, res);
	if (!res)return level;
	if (abs(left - right) > 1)
		res = false;
	return left > right ? left : right;
}
int main()
{
	Node *head = new Node(1);
	head->left = new Node(2);
	head->left->left = new Node(3);
	cout << isBalance(head);
    return 0;
}

