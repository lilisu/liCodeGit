// isBST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<queue>
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
bool MorrisIsSearchBST(Node *head)
{
	if (head == NULL)
	{
		return true;
	}
	bool res = true;
	Node* pre = NULL;
	Node* cur1 = head;
	Node* cur2 = NULL;
	while (cur1)
	{
		cur2 = cur1->left;
		if (cur2)
		{
			while (cur2->right&&cur2->right!=cur1)
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
		if (pre != NULL&&pre->value > cur1->value)
		{
			res = false;
		}
		pre = cur1;
		cur1 = cur1->right;
	}
	return res;
}
bool InIsBST(Node* head)
{
	if (head == NULL)
		return true;
	stack<Node*> stack;
	Node* pre = NULL;
	bool res = true;
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
				res = false;
				break;
			}
			pre = head;
			head = head->right;
		}
	}
	return res;
}
bool isCompleteBST(Node* head)
{
	if (head == NULL)
		return true;
	bool leaf = false;
	Node* left = NULL;
	Node* right = NULL;
	queue<Node*> queue;
	queue.push(head);
	while (!queue.empty())
	{
		head = queue.front();
		queue.pop();
		left = head->left;
		right = head->right;
		if ((leaf && (left != NULL || right != NULL)) || (left == NULL&&right != NULL))
			return false;
		if (left)
			queue.push(left);
		if (right)
			queue.push(right);
		else
			leaf = true;
	}
	return true;
}
int main()
{
	Node* head = new Node(2);
	head->left = new Node(1);
	head->right = new Node(3);
	cout << InIsBST(head);
    return 0;
}

