// preInToTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include<iostream>
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
Node* toTree(int pre[], int pi, int pj, int in[], int ni, int nj, hash_map<int, int> map);
Node* preInToTree(int pre[], int in[], int len)
{
	if (pre == NULL || in == NULL)return NULL;
	hash_map<int, int> map;
	for (int i = 0; i < len; i++)
	{
		map.insert(make_pair(in[i], i));
	}
	return toTree(pre, 0, len-1, in, 0, len-1, map);
}
Node* toTree(int pre[], int pi, int pj, int in[], int ni, int nj, hash_map<int, int> map)
{
	if (pi > pj)return NULL;
	Node* head = new Node(pre[pi]);
	int i = map[pre[pi]];
	head->left = toTree(pre, pi + 1, pi + i - ni, in, ni, i - 1, map);
	head->right = toTree(pre, pi + i - ni + 1, pj, in, i + 1, nj, map);
	return head;
}
Node* ipTree(int in[], int ni, int nj, int pos[], int pi, int pj, hash_map<int, int> map);
Node* inPosToTree(int in[], int pos[], int len)
{
	if (in == NULL || pos == NULL || len < 0)
	{
		return NULL;
	}
	hash_map<int, int> map;
	for (int i = 0; i < len; i++)
	{
		map.insert(make_pair(in[i], i));
	}
	return ipTree(in, 0, len - 1, pos, 0, len - 1, map);
}
Node* ipTree(int in[], int ni, int nj, int pos[], int pi, int pj, hash_map<int, int> map)
{
	if (pi > pj)return NULL;
	Node* head =new Node( pos[pj]);
	int i = map[pos[pj]];
	head->left = ipTree(in, ni, i - 1, pos, pi, pi + i - ni - 1, map);
	head->right = ipTree(in, i + 1, nj, pos, pi + i - ni, pj - 1, map);
	return head;
}
void printTree(Node* head)
{
	if (head == NULL)return;
	cout << head->value << "  ";
	printTree(head->left);
	printTree(head->right);
}
Node* ppTree(int pre[], int pi, int pj, int pos[], int si, int sj, hash_map<int, int> map);
Node* prePosToTree(int pre[], int pos[], int len)
{
	if (pre == NULL || pos == NULL)return NULL;
	hash_map<int, int> map;
	for (int i = 0; i < len; i++)
	{
		map.insert(make_pair(pos[i], i));
	}
	return ppTree(pre,0,len-1,pos,0,len-1,map);
}
Node* ppTree(int pre[], int pi, int pj, int pos[], int si, int sj, hash_map<int, int> map)
{

	Node* head = new Node(pre[pi]);
	if (pi == pj)return head;
	int i = map[pre[++pi]];
	head->left = ppTree(pre, pi, pi + i - si, pos, si, i, map);
	head->right = ppTree(pre, pi + i - si + 1, pj, pos, i  + 1, sj - 1, map);
	return head;
}
int setPos(int p[], int pi, int pj, int n[], int ni, int nj, int s[], int si, hash_map<int, int> map);
int* getPosArray(int pre[], int in[], int len)
{
	if (pre == NULL || in == NULL)
		return NULL;
	hash_map<int, int> map;
	for (int i = 0; i < len; i++)
	{
		map.insert(make_pair(in[i], i));
	}
	int *s=new int[len]();
	setPos(pre,0,len-1,in,0,len-1,s,len-1,map);
	return s;
}
int setPos(int p[], int pi, int pj, int n[], int ni, int nj, int s[], int si, hash_map<int, int> map)
{
	if (pi > pj)return si;
	*(s + si) = p[pi];
	cout << *(s + si) << endl;
	si--;
	int i = map[p[pi]];
	si = setPos(p, pj + i - nj + 1, pj, n, i + 1, nj, s, si, map);
	return setPos(p, pi + 1, pi + i - ni, n, ni, i - 1, s, si, map);
}
int main()
{
	int pre[3] = { 1,2,3};
	int in[3] = { 2,1,3 };
	//int in[9] = { 4,2,8,5,9,1,6,3,7 };
	//Node* head = preInToTree(pre, in, 9);
	//int in[9] = { 4,2,8,5,9,1,6,3,7 };
//	int pos[3] = {2,3,1};
//	Node* head = prePosToTree(pre, pos, 3);
//	printTree(head);
	int *s = getPosArray(pre, in, 3);
	for (int i = 0; i++; i < 3)
	{
		cout << *(s + i) << endl;
	}
    return 0;
}

