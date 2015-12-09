// biggestSubBST.cpp : 定义控制台应用程序的入口点。
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
Node *posOrder(Node* head, int record[]);
Node* biggestSubBST(Node* head)
{
	int record[3];
	return posOrder(head, record);
}
Node* posOrder(Node* head, int record[])
{
	if (head == NULL)
	{
		record[0] = 0;
		record[1] = INT32_MAX;
		record[2] = INT32_MIN;
		return NULL;
	}
	int value = head->value;
	Node* left = head->left;
	Node* right = head->right;
	Node* lBST = posOrder(left, record);
	int lSize = record[0];
	int lMin = record[1];
	int lMax = record[2];
	Node* rBST = posOrder(right, record);
	int rSize = record[0];
	int rMin = record[1];
	int rMax = record[2];
	record[1] = lMin < value ? lMin : value;
	record[2] = rMax > value ? rMax : value;
	if (left == lBST&&right == rBST&&lMax<value&&rMin>value)
	{
		record[0] = lSize + rSize + 1;
		return head;
	}
	record[0] = lSize > rSize ? lSize : rSize;
	return lSize > rSize ? lBST : rBST;
}
int main()
{

	Node* head = new Node(-3);
	head->left = new Node(3);
	head->left->left = new Node(1);
	head->left->right = new Node(2);
	head->left->right->left = new Node(1);
	head->left->right->right = new Node(6);
	head->right = new Node(-9);
	head->right->left = new Node(2);
	head->right->right = new Node(1);
	cout << biggestSubBST(head)->value;
    return 0;
}

