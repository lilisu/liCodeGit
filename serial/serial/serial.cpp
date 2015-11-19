// serial.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cstdlib>
#include<sstream>
using namespace std;
class Node {
public :
	int value;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->value = data;
	}
};
string serialByPre(Node* head)
{
	if (head == NULL)
		return "#!";
	stringstream s;
	s << head->value;
	string res = s.str() + "!";
	res += serialByPre(head->left);
	res += serialByPre(head->right);
	return res;
}
vector<string> SplitString(const string& s, const string& c);
Node* reconPreOrder(queue<string> queue);
Node* reconByPreString(string preStr)
{
	vector<string> value = SplitString(preStr, "!");
	queue<string> queue;
	for (vector<string>::size_type i = 0; i != value.size(); i++)
	{
		queue.push(value[i]);
	}
	return reconPreOrder(queue);
}
Node* reconPreOrder(queue<string> queue)
{
	string value = queue.front();
	queue.pop();
	if (value == "#")
		return NULL;
	Node* head = new Node(atoi(value.c_str()));
	head->left = reconPreOrder(queue);
	head->right = reconPreOrder(queue);
	return head;
}
vector<string> SplitString(const string& s, const string& c)
{
	vector<string> v;
	string::size_type pos1, pos2;
	pos2 = s.find(c);//返回c在s中的下标位置
	pos1 = 0;
	while (string::npos != pos2)//
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
	return v;
}
string serialByLevel(Node *head)
{
	if (head == NULL)
	{
		return "#!";
	}
	stringstream s;
	s << head->value;
	string res = s.str() + "!";
	queue<Node*> queue;
	queue.push(head);
	while (!queue.empty())
	{
		head = queue.front();
		queue.pop();
		if (head->left)
		{
			s.str("");
			s << head->left->value;
			 res += s.str() + "!";
			queue.push(head->left);
		}
		else {
			res += "#!";
		}
		if (head->right)
		{
			s.str("");
			s << head->right->value;
			res += s.str() + "!";
			queue.push(head->right);
		}
		else {
			res += "#!";
		}
	}
	return res;
}
Node* generateNodeByString(string val)
{
	if (val == "#")
		return NULL;
	return new Node(atoi(val.c_str()));
}
Node *reconByLevelString(string levelStr)
{
	vector<string> value = SplitString(levelStr,"!");
	int index = 0;
	Node* head = generateNodeByString(value[index++]);
	queue<Node*> queue;
	if (head != NULL)
		queue.push(head);
	Node *node = NULL;
	while (!queue.empty())
	{
		node = queue.front();
		queue.pop();
		node->left = generateNodeByString(value[index++]);
		node->right = generateNodeByString(value[index++]);
		if (node->left != NULL)queue.push(node->left);
		if (node->right != NULL)queue.push(node->right);
	}
	return head;
}
int main()
{
	Node *head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	string s = serialByLevel(head);
	cout << s << endl;
    return 0;
}

