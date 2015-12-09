// printByLevel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<queue>
#include<deque>
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
void printByLevel(Node* head)
{
	if (head == NULL)return;
	queue<Node*> queue;
	Node* last = head;
	Node* nlast = NULL;
	int level = 1;
	queue.push(head);
	cout << "level " << level++<<": ";
	while (!queue.empty())
	{
		head = queue.front();
		queue.pop();
		cout << head->value << "  ";
		if (head->left != NULL)
		{
			queue.push(head->left);
			nlast = head->left;
		}
		if (head->right != NULL)
		{
			queue.push(head->right);
			nlast = head->right;
		}
		if (head == last&&!queue.empty())
		{
			cout << endl;
			cout << "level " << level++ << ": ";
			last = nlast;
		}
	}
}
void printLevelAndOrientation(int level, bool lr);
void printByZigzag(Node * head)
{
	if (head == NULL)return;
	deque<Node*> deque;
	int level = 1;
	bool lr = true;
	Node* last = head;
	Node* nlast = NULL;
	deque.push_front(head);
	printLevelAndOrientation(level++, lr);
	while (!deque.empty())
	{
		if (lr) {
			head = deque.front();
			deque.pop_front();
			if (head->left)
			{
				nlast = nlast == NULL ? head->left : nlast;
				deque.push_back(head->left);
			}
			if (head->right)
			{
				nlast = nlast == NULL ? head->right : nlast;
				deque.push_back(head->right);
			}
		}
		else {
			head = deque.back();
			deque.pop_back();
			if (head->right)
			{
				nlast = nlast == NULL ? head->right : nlast;
				deque.push_front(head->right);
			}
			if (head->left)
			{
				nlast = nlast == NULL ? head->left : nlast;
				deque.push_front(head->left);
			}
		}
		cout << head->value<<" ";
		if (head == last&&!deque.empty())
		{
			last = nlast;
			lr = !lr;
			nlast = NULL;
			cout << endl;
			printLevelAndOrientation(level++, lr);
		}
	}
}
void printLevelAndOrientation(int level, bool lr)
{
	cout << "Level " << level << " from ";
	if (lr)
	{
		cout << "left to right: "; 
	}
	else {
		cout<< "right to left:";
	}
	
}
int main()
{
	Node* head = new Node(-3);
	head->left = new Node(3);
	head->left->left = new Node(1);
	head->left->right = new Node(5);
	head->left->right->left = new Node(4);
	head->left->right->right = new Node(6);
	head->right = new Node(-9);
	head->right->left = new Node(2);
	head->right->right = new Node(1);
	printByZigzag(head);
    return 0;
}

