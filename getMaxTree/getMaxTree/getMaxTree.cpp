// getMaxTree.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<map>
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include<hash_map>




using namespace std;
using namespace stdext;
class Node
{
public:
	Node* left;
	Node* right;
	int value;
	Node(int data)
	{
		this->value = data;
	}
};
void popStackSetMap(stack<Node*> &stack, map<Node*, Node*> &map)
{
	Node *node = stack.top();
	stack.pop();
	if (stack.empty())
	{
		map.insert(make_pair(node,nullptr));
	}
	else {
		map.insert(make_pair(node, stack.top()));
	}
}
Node* getMaxTree(int *arr,int size)
{
	Node*  *narr = new Node*[size];
	for (int i = 0; i < size; i++)
	{
		narr[i] = new Node(*arr++);
	}
	stack<Node*> stack;
	map<Node*, Node*> lBigMap;
	map<Node*, Node*> rBigMap;
	for (int i = 0; i != size; i++)
	{
		Node* curNode = narr[i];
		while ((!stack.empty()) && stack.top()->value < curNode->value)
		{
			popStackSetMap(stack, lBigMap);
		}
		stack.push(curNode);
	}
	while (!stack.empty())
	{
		popStackSetMap(stack, lBigMap);
	}
	for (int i = size - 1; i != -1; i--)
	{
		Node *curNode = narr[i];
		while (!stack.empty() && stack.top()->value < curNode->value)
		{
			popStackSetMap(stack, rBigMap);
		}
		stack.push(curNode);

	}
	while (!stack.empty())
	{
		popStackSetMap(stack, rBigMap);
	}
	Node *head = NULL;
	for (int i = 0; i < size; i++)
	{
		Node *curNode = narr[i];
		Node *leftBigNode = lBigMap[curNode];
		Node *rightBigNode = rBigMap[curNode];
		if (leftBigNode == nullptr&&rightBigNode == nullptr)
		{
			head = curNode;
		}
		else if (leftBigNode == nullptr)
		{
			if (rightBigNode->left == NULL)
			{
				rightBigNode->left = curNode;
			}
			else {
				rightBigNode->right = curNode;
			}
		}
		else if (rightBigNode == nullptr)
		{
			if (leftBigNode->left == NULL)
			{
				leftBigNode->left = curNode;
			}
			else {
				leftBigNode->right = curNode;
			}
		}
		else {
			Node* parent = leftBigNode->value < rightBigNode->value ? leftBigNode : rightBigNode;
			if (parent->left == NULL)
			{
				parent->left = curNode;
			}
			else {
				parent->right = curNode;
			}
		}
	}
	return head;
}
void printPreOrder(Node *head)
{
	if (head == NULL)
		return;
	cout << head->value << endl;
	printPreOrder(head->left);
	printPreOrder(head->right);
}
int main()
{
	//int uniqueArr[5] = { 3,4,5,1,2 };
	//int size = sizeof(uniqueArr) / sizeof(uniqueArr[0]);
	//Node* head = getMaxTree(uniqueArr,size);
	//printPreOrder(head);
	//if (head->right == NULL)cout << "sdfsdf";
	hash_map<int,int> hash;
	hash[1] = 123;
    return 0;
}

