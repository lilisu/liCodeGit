// t1ContainsT2.cpp : 定义控制台应用程序的入口点。
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
bool check(Node* t1, Node* t2);
bool contains(Node* t1, Node* t2)
{
	return check(t1, t2) || check(t1->left, t2) || check(t1->right, t2);
}
bool check(Node* t1, Node* t2)
{
	if (t2 == NULL)
	{
		return true;
	}
	if (t1 == NULL || t1->value != t2->value)
	{
		return false;
	}
	return check(t1->left, t2->left) && check(t1->right, t2->right);
}
int main()
{
	Node* head = new Node(1);
	head->left = new Node(2);
	head->left->left = new Node(4);
	head->left->left->left = new Node(8);
	head->left->left->right = new Node(9);
	head->left->right = new Node(5);
	head->left->right->left = new Node(10);
	head->right = new Node(3);
	head->right->left = new Node(6);
	head->right->right = new Node(7);
	Node* head1 = new Node(2);
	head1->left = new Node(4);
	head1->left->left = new Node(8);
	head1->right = new Node(5);
	if (contains(head, head1))
	{
		cout << "t1树包含t2树";
	}
	else {
		cout << "t1树不包含t2树";
	}
    return 0;
}

