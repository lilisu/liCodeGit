// generateTree.cpp : 定义控制台应用程序的入口点。
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
Node* generateTree(int sortArr[], int start, int end);
Node* generate(int sortArr[], int len)
{
	if (sortArr == NULL || len < 1)
		return NULL;
	return generateTree(sortArr, 0, len - 1);
}
Node* generateTree(int sortArr[], int start, int end)
{
	if (start > end)
		return NULL;
	Node* head = new Node(sortArr[(start + end) / 2]);
	head->left = generateTree(sortArr, start, (start + end) / 2 - 1);
	head->right = generateTree(sortArr, (start + end) / 2 + 1, end);
	return head;
}

int main()
{
	int sortArr[3] = { 1,2,3 };
	Node* head = generate(sortArr, 3);
	cout << head->value << endl;
	return 0;
}

