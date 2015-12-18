// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
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
int* getNextArray(string s)
{
	int* next = new int();
	if (s.length() == 0)
		return next;
	*next = -1;
	*(next + 1) = 0;
	int pos = 2;
	int cn = 0;
	while (pos < s.length())
	{
		if (s[pos] == s[cn])
		{
			*(next + pos) = ++cn;
			pos++;
		}
		else if (cn>0) {
			cn = *(next + cn);
		}
		else {
			*(next + pos) = 0;
			pos++;
		}
	}
	return next;
}
int getIndexof(string s, string m) {
	if (s.length() < m.length()) {
		return -1;
	}
	int si = 0;
	int mi = 0;
	int* next = getNextArray(m);
	while (si < s.length()&&mi<m.length())
	{
		if (s[si] == m[mi])
		{
			si++;
			mi++;
		}
		else if (*(next + mi) == -1)
		{
			si++;
		}
		else {
			mi = *(next + mi);
		}
	}
	return mi == m.length() ? si - mi : -1;
}
string serialByPre(Node* head)
{
	if (head == NULL)
	{
		return "#!";
	}
	stringstream stream;
	stream << head->value;
	string s = stream.str() + "!";
	s += serialByPre(head->left);
	s += serialByPre(head->right);
	return s;
}
bool isSubTree(Node *t1, Node* t2)
{
	string s = serialByPre(t1);
	string m = serialByPre(t2);
	return getIndexof(s, m) == -1 ? false : true;
}
int main()
{
	/*Node* t1 = new Node(1);
	t1->left = new Node(2);
	t1->left->left = new Node(4);
	t1->left->left->right = new Node(8);
	t1->left->right = new Node(5);
	t1->left->right->left = new Node(9);
	t1->right = new Node(3);
	t1->right->left = new Node(6);
	t1->right->right = new Node(7);
	Node* t2 = new Node(2);
	t2->left = new Node(4);
	t2->left->right = new Node(8);
	t2->right = new Node(5);
	string s = serialByPre(t1);
	string m = serialByPre(t2);
	cout << serialByPre(t1) << endl;
	cout << serialByPre(t2) << endl;*/
	string s = "1!2!4!#!";
	string m = "2!4!";
	int i = getIndexof(s, m);
	cout << i <<endl;
    return 0;
}

