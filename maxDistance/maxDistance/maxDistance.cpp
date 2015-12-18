// maxDistance.cpp : 定义控制台应用程序的入口点。
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
int posOrder(Node* head, int record[]);
int maxDistance(Node* head)
{
	if (head == NULL)
		return 0;
	int record[1] = { 0 };
	return posOrder(head, record);
}
int posOrder(Node* head, int record[])
{
	if (head == NULL)
	{
		record[0] = 0;
		return 0;
	}
	int leftMax = posOrder(head->left, record);
	int maxFromLeft = record[0];
	int rightMax = posOrder(head->right, record);
	int maxFromRight = record[0];
	int curNodeMax = maxFromLeft + maxFromRight + 1;
	record[0] = maxFromLeft > maxFromRight ? maxFromLeft + 1 : maxFromRight + 1;
	return (leftMax > rightMax ? leftMax : rightMax) > curNodeMax ? (leftMax > rightMax ? leftMax : rightMax) : curNodeMax;
}
int main()
{
	Node* head = new Node(1);
	head->left = new Node(2);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right = new Node(6);
	cout << maxDistance(head);
    return 0;
}

