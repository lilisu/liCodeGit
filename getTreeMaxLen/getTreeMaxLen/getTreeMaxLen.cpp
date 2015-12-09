// getTreeMaxLen.cpp : 定义控制台应用程序的入口点。
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
int preOrder(Node* head, int sum, int preSum, int level, int& maxlen, hash_map<int, int> &sumMap);
int getMaxLength(Node* head, int sum)
{
	hash_map<int, int> sumMap;
	sumMap.insert(make_pair(0, 0));
	int maxlen = 0;
	return preOrder(head,sum,0,1,maxlen,sumMap);
}
int preOrder(Node* head, int sum, int preSum, int level, int &maxlen, hash_map<int, int> &sumMap)
{
	if (head == NULL)
		return maxlen;
	int curSum = preSum + head->value;
	if (sumMap.count(curSum - sum) == 1)
	{
		maxlen = (level - sumMap[curSum - sum]) > maxlen ? (level - sumMap[curSum - sum]) : maxlen;
	}
	if (sumMap.count(curSum) == 0)
	{
		sumMap.insert(make_pair(curSum, level));
	}
	maxlen = preOrder(head->left, sum, curSum, level + 1, maxlen, sumMap);
	maxlen = preOrder(head->right, sum, curSum, level + 1, maxlen, sumMap);
	if (level == sumMap[curSum])
	{
		sumMap.erase(curSum);
	}
	return maxlen;
}
int main()
{
	Node* head = new Node(-3);
	head->left = new Node(3);
	head->left->left = new Node(1);
	head->left->right = new Node(0);
	head->left->right->left = new Node(1);
	head->left->right->right = new Node(6);
	head->right = new Node(-9);
	head->right->left = new Node(2);
	head->right->right = new Node(1);
	int maxlen = getMaxLength(head, -9);
	cout << maxlen << endl;
    return 0;
}

