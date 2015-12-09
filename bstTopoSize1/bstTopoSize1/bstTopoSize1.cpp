// bstTopoSize1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
#include<hash_map>
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
class record {
public:
	int l;
	int r;
	record(int left, int right)
	{
		this->l = left;
		this->r = right;
	}
};
int maxTopo(Node* head, Node* n);
int bstTopoSize1(Node* head)
{
	if (head == NULL)return 0;
	int max = maxTopo(head, head);
	max = bstTopoSize1(head->left) > max ? bstTopoSize1(head->left) : max;
	max = bstTopoSize1(head->right) > max ? bstTopoSize1(head->right) : max;
	return max;
}
bool isBSTNode(Node* head, Node* n, int value);
int maxTopo(Node *head, Node *n)
{
	if (head != NULL&&n != NULL&&isBSTNode(head, n, n->value))
	{
		return maxTopo(head, n->left) + maxTopo(head, n->right) + 1;
	}
	return 0;
}
bool isBSTNode(Node *head, Node *n, int value)
{
	if (head == NULL)
		return false;
	if (head == n)
		return true;
	return isBSTNode(head->value > value ? head->left : head->right, n, value);
}
int posOrder(Node* head, hash_map<Node*, record> &map);
int bstTopoSize2(Node *head)
{
	if (head == NULL)return 0;
	hash_map<Node*, record> map;
	return posOrder(head, map);
}
int modifyMap(Node* n, int v, hash_map<Node*, record> &map, bool s);
int posOrder(Node* head, hash_map<Node*, record> &map)
{
	if (head == NULL)return 0;
	int ls = posOrder(head->left, map);
	int rs = posOrder(head->right, map);
	modifyMap(head->left, head->value, map, true);
	modifyMap(head->right, head->value, map, false);
	hash_map<Node*,record>::iterator lr = map.find(head->left);
	hash_map<Node*, record>::iterator rr = map.find(head->right);
	int bstl = lr ==  map.end()? 0 : lr->second.l + lr->second.r + 1;
	int bstr = rr == map.end() ? 0 : rr->second.l + rr->second.r + 1;
	map.insert(make_pair(head,  record(bstl, bstr)));
	return (ls > rs ? ls : rs) > (bstl + bstr + 1) ? (ls > rs ? ls : rs) : (bstl + bstr + 1);
}
int modifyMap(Node* n, int v, hash_map<Node*, record> &map, bool s)
{
	if (n == NULL && (map.find(n) == map.end()))
		return 0;
	record rec = map[n];
	if ((s&&v<n->value) || (!s&&v>n->value))
	{
		map.erase(n);
		return rec.l + rec.r + 1;
	}
	else {
		int minus = modifyMap(s ? n->right : n->left, v, map, s);
		if (s)
		{
			rec.r = rec.r - minus;
		}
		else {
			rec.l = rec.l - minus;
		}
		map.insert(make_pair(n, rec));
		return minus;
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
	int maxlen = bstTopoSize1(head);
	cout << maxlen << endl;
    return 0;
}

