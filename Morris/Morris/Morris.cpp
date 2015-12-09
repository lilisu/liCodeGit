// Morris.cpp : 定义控制台应用程序的入口点。
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
void MorrisPre(Node* head)
{
	if (head == NULL)return;
	Node* cur1 = head;
	Node* cur2 = NULL;
	while (cur1 != NULL)
	{
		cur2 = cur1->left;
		if (cur2 != NULL)
		{
			while (cur2->right != NULL&&cur2->right != cur1)
			{
				cur2 = cur2->right;
			}
			if (cur2->right == NULL)
			{
				cout << cur1->value << endl;
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = NULL;
			}
		}
		else {
			cout << cur1->value << endl;
		}
		cur1 = cur1->right;
	}
}
void MorrisIn(Node *head)
{
	if (head == NULL)return;
	Node* cur1 = head;
	Node* cur2 = NULL;
	while (cur1)
	{
		cur2 = cur1->left;
		if (cur2 != NULL)
		{
			while (cur2->right != NULL&&cur2->right != cur1)
			{
				cur2 = cur2->right;
			}
			if (cur2->right == NULL)
			{
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = NULL;
			}
		}
		cout << cur1->value<<endl;
		cur1 = cur1->right;
	}
}
void printRE(Node* cur1);
void MorrisPos(Node* head)
{
	if (head == NULL)return;
	Node* cur1 = head;
	Node* cur2 = NULL;
	while (cur1 != NULL)
	{
		cur2 = cur1->left;
		if (cur2 != NULL)
		{
			while (cur2->right != NULL&&cur2->right != cur1)
			{
				cur2 = cur2->right;
			}
			if (cur2->right == NULL)
			{
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = NULL;
				printRE(cur1->left);
			}
		}
		cur1 = cur1->right;
	}
	printRE(head);
}
Node* reverse(Node* from);
void printRE(Node* cur1)
{
	Node* head = reverse(cur1);
	while (head)
	{
		cout << head->value << endl;
		cur1 = head;
		head = head->right;
	}
	reverse(cur1);
}
Node* reverse(Node* from)
{
	Node* pre = NULL;
	Node* next = NULL;
	while (from)
	{
		next = from->right;
		from->right = pre;
		pre = from;
		from = next;
	}
	return pre;
}
int main()
{
	Node *head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	MorrisPos(head);
    return 0;
}

