// LowestAncestor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include<iostream>
#include<hash_map>
#include<hash_set>
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
Node* lowestAncestor(Node* head, Node* n1, Node* n2)
{
	if (head == NULL || head == n1 || head == n2)
		return head;
	Node* left = lowestAncestor(head->left, n1, n2);
	Node* right = lowestAncestor(head->right, n1, n2);
	if (left != NULL && right != NULL)
		return head;
	return left != NULL ? left : right;
}
void setMap(Node* head, hash_map<Node*, Node*>& map);
Node* record1(Node* head, Node* n1, Node* n2)
{
	hash_map<Node*, Node*> map;
	map.insert(make_pair(head, nullptr));
	hash_map<Node*, Node*>&m = map;
	setMap(head, m);
	hash_set<Node*> path;
	while (map.count(n1) !=0)
	{
		path.insert(n1);
		n1 = map[n1];
	}
	while (path.count(n2) == 0)
	{
		n2 = map[n2];
	}
	return n2;
}
void setMap(Node* head, hash_map<Node*, Node*>& map)
{
	if (head == NULL)return;
	if (head->left)map.insert(make_pair(head->left, head));
	if (head->right)map.insert(make_pair(head->right, head));
	hash_map<Node*, Node*> &m = map;
	setMap(head->left,m);
	setMap(head->right,m);
}
int main()
{
	Node* head = new Node(1);
	head->left = new Node(2);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right = new Node(3);
	head->right->left = new Node(6);
	head->right->right = new Node(7);
	head->right->right->left = new Node(8);
	Node* ancestor = lowestAncestor(head, head->right->left, head->right->right->left);
	cout << ancestor->value << endl;
	Node* ancestor1 = record1(head, head->right->left, head->right->right->left);
	cout << ancestor1->value << endl;
    return 0;
}

