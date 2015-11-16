// BinaryTree.cpp : 定义控制台应用程序的入口点。
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
	Node(int value)
	{
		this->value = value;
	}
};
void preOrderRecur(Node *head) {
	if (head == NULL)
	{
		return;
	}
	cout << head->value<<endl;
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}
void preOrderUnrecur(Node *head)
{
	if (head != NULL)
	{
		stack<Node*> stack;
		stack.push(head);
		while (!stack.empty())
		{
			head = stack.top();
			cout << head->value<<endl;
			stack.pop();
			if (head->right != NULL)
			{

				stack.push(head->right);
			}
			if (head->left != NULL)
			{
				stack.push(head->left);
			}
		}
	}
}
void InOrderRecur(Node *head)
{
	if (head == NULL)
	{
		return;
	}
	InOrderRecur(head->left);
	cout << head->value<<endl;
	InOrderRecur(head->right);

}
void InOrderUnrecur(Node *head)
{
	if (head != NULL)
	{
		stack<Node*> stack;
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
				cout << head->value << endl;
				head = head->right;
			}
		}
	}
}

void posOrderRecur(Node *head)
{
	if (head == NULL)
	{
		return;
	}
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout << head->value << endl;
}
void posOrderUnrecur(Node *head)
{
	if (head != NULL)
	{
		stack<Node*> s1;
		stack<Node*> s2;
		s1.push(head);
		while (!s1.empty())
		{
			head = s1.top();
			s1.pop();
			s2.push(head);
			if (head->left)
			{
				s1.push(head->left);
			}
			if (head->right)
			{
				s1.push(head->right);
			}
		}
		while (!s2.empty())
		{
			head = s2.top();
			s2.pop();
			cout << head->value << endl;
		}
	}
}
void posOrderUnrecur2(Node *head)
{
	if (head != NULL)
	{
		stack<Node*> stack;
		stack.push(head);
		Node * c = NULL;
		while (!stack.empty())
		{
			c = stack.top();
			if (c->left != NULL&&head != c->left&&head != c->right)
			{
				stack.push(c->left);
			}
			else if (c->right != NULL&&head != c->right)
			{
				stack.push(c->right);
			}
			else {
				head = c;
				stack.pop();
				cout << head->value << endl;
			}
		}
	}
}
int main()
{
	Node *head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	//posOrderRecur(head);
	//preOrderUnrecur(head);
	//InOrderUnrecur(head);
	//posOrderUnrecur(head);
	posOrderUnrecur2(head);
    return 0;
}

