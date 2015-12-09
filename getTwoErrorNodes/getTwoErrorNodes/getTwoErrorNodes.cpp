// getTwoErrorNodes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
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
Node** getTwoErrorNodes(Node *head)
{
	Node** err = new Node*();
	stack<Node*> stack;
	Node *pre = NULL;
	while (!stack.empty() || head != NULL)
	{
		if (head != NULL)
		{
			stack.push(head);
			head = head->left;
		}
		else {
			head = stack.top();
			stack.pop();
			if (pre != NULL&&pre->value > head->value)
			{
				*err = *err == NULL ? pre : *err;
				*(err + 1) = head;
			}
			pre = head;
			head = head->right;
		}
	}
	return err;
}
Node** getTwoErrParent(Node* head, Node* e1, Node* e2)
{
	stack<Node*> stack;
	Node** parent = new Node*();
	while (!stack.empty() || head != NULL)
	{
		if (head != NULL)
		{
			stack.push(head);
			head = head->left;
		}
		else {
			head = stack.top();
			stack.pop();
			if (head->left == e1||head->right==e1)
			{
				*parent = head;
			}
			if (head->left == e2 || head->right == e2)
			{
				*(parent + 1) = head;
			}
			head = head->right;
		}
	}
	return parent;
}
Node* recoverTree(Node* head)
{
	Node** err = getTwoErrorNodes(head);
	Node** parent = getTwoErrParent(head, *err, *(err + 1));
	Node* e1 = *err;
	Node* e2 = *(err + 1);
	Node* e1P = *parent;
	Node* e2P = *(parent + 1);
	Node* e1L = e1->left;
	Node* e1R = e1->right;
	Node* e2L = e2->left;
	Node* e2R = e2->right;
	if (e1 == head)
	{
		if (e2 == e1R)
		{
			e1->left = e2L;
			e1->right = e2R;
			e2->left = e1L;
			e2->right = e1;
		}
		else if (e2 == e2P->left)
		{
			e1->left = e2L;
			e1->right = e2R;
			e2P->left = e1;
			e2->left = e1L;
			e2->right = e1R;
		}
		else {
			e1->left = e2L;
			e1->right = e2R;
			e2P->right = e1;
			e2->left = e1L;
			e2->right = e1R;
		}
		head = e2;
	}
	else if (e2 == head)
	{
		if (e1 == e2L)
		{
			e1->left = e2;
			e1->right = e2R;
			e2->left = e1L;
			e2->right = e2R;
		}
		else if (e1 = e1P->left)
		{
			e2->left = e1L;
			e2->right = e1R;
			e1P->left = e2;
			e1->left = e2L;
			e1->right = e2R;
		}
		else {
			e1->left = e2L;
			e1->right = e2R;
			e1P->right = e2;
			e2->left = e1L;
			e2->right = e1R;
		}
		head = e1;
	}
	else if (e1R == e2) {
		if (e1 == e1P->left)
		{
			e1P->left = e2;
			e2->left = e1L;
			e2->right = e1;
			e1->left = e2L;
			e1->right = e2R;
		}
		else {
			e1P->right = e2;
			e2->left = e1L;
			e2->right = e1;
			e1->left = e2L;
			e1->right = e2R;
		}
	}
	else if (e1 == e2L)
	{
		if (e2 = e2P->left)
		{
			e2P->left = e1;
			e2->left = e1L;
			e2->right = e1R;
			e1->left = e2;
			e1->right = e2R;
		}
		else {
			e2P->right = e1;
			e2->left = e1L;
			e2->right = e1R;
			e1->left = e2;
			e1->right = e2R;
		}
	}
	else {
		if (e1P->left == e1&&e2P->left == e2)
		{
			e1P->left = e2;
			e2P->left = e1;
			e1->left = e2L;
			e1->right = e2R;
			e2->left = e1L;
			e2->right = e2R;
		}
		else if (e1P->left == e1&&e2P->right == e2)
		{
			e1P->left = e2;
			e2P->right = e1;
			e1->left = e2L;
			e1->right = e2R;
			e2->left = e1L;
			e2->right = e2R;
		}
		else if (e1P->right == e1&&e2P->left == e2)
		{
			e1P->right = e2;
			e2P->left = e1;
			e1->left = e2L;
			e1->right = e2R;
			e2->left = e1L;
			e2->right = e2R;
		}
		else {
			e1P->right = e2;
			e2P->right = e1;
			e1->left = e2L;
			e1->right = e2R;
			e2->left = e1L;
			e2->right = e2R;
		}
	}
	return head;
}
void printN(Node *head)
{
	if (head == NULL)return;
	printN(head->left);
	cout << head->value << endl;
	printN(head->right);
}
int main()
{
	Node *head = new Node(4);
    head->left = new Node(2);
	head->left->left = new Node(5);
	head->left->right = new Node(3);
	head->right = new Node(1);
	Node** err = getTwoErrorNodes(head);
	cout << (*err)->value<<endl;
	cout << (*(err + 1))->value << endl;
	Node** parent = getTwoErrParent(head, *err, *(err + 1));
	cout << (*parent)->value << endl;
	cout << (*(parent + 1))->value << endl;
	printN(head);
	head = recoverTree(head);
	printN(head);
    return 0;
}

