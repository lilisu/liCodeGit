// Binary.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<stack>
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
void preOrderUnRecur(Node *head)
{
	if (head)
	{
		stack<Node*> stack;
		stack.push(head);
		while (!stack.empty())
		{
			head = stack.top();
			stack.pop();
			cout << head->value<<endl;
			if (head->right) stack.push(head->right);
			if (head->left) stack.push(head->left);
		}
	}
}
void inOrderUnRecur(Node *head)
{
	if (head)
	{
		stack<Node*> stack;
		while (!stack.empty() || head)
		{
			if (head)
			{
				stack.push(head);
				head = head->left;
			}
			else {
				head = stack.top();
				stack.pop();
				cout << head->value << endl;
				head = head->right;
			}
		}
	}
}
void posOrderUnRecur(Node* head)
{
	if (head)
	{
		stack<Node*> s1, s2;
		s1.push(head);
		while (!s1.empty())
		{
			head = s1.top();
			s1.pop();
			s2.push(head);
			if (head->left)s1.push(head->left);
			if (head->right)s1.push(head->right);
		}
		while (!s2.empty())
		{
			head = s2.top();
			s2.pop();
			cout << head->value << endl;
		}
	}
}
void posOrderUnRecur1(Node* head)
{
	if (head)
	{
		stack<Node*>  stack;
		Node *c = NULL;
		stack.push(head);
		while (!stack.empty())
		{
			c = stack.top();
			if (c->left&&head != c->left&&head != c->right)
			{
				stack.push(c->left);
			}
			else if (c->right&&head != c->right)
			{
				stack.push(c->right);
			}
			else {
				head = stack.top();
				cout << head->value << endl;
				stack.pop();
			}
		}
	}
}
int main()
{
	Node *head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	posOrderUnRecur1(head);
    return 0;
}

