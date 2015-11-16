// printEdge.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
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
int getHeight(Node *head, int n)
{
	if (head==NULL)
		return n;
	return getHeight(head->left, n + 1) > getHeight(head->right, n + 1) ? getHeight(head->left, n + 1) : getHeight(head->right, n + 1);
}
void setEdgeMap(Node *head, int n, Node* *edgeMap[2])
{
	if (head == NULL)return;
	edgeMap[n][0] = edgeMap[n][0] == NULL ? head : edgeMap[n][0];
	edgeMap[n][1] = head;
	setEdgeMap(head->left, n + 1, edgeMap);
	setEdgeMap(head->right, n + 1, edgeMap);
}
void printLeafNotInMap(Node *head, int n, Node* *edgeMap[2])
{
	if (head == NULL)return;
	if (head->left == NULL&&head->left == NULL&&head != edgeMap[n][0] && head != edgeMap[n][1])
		cout << head->value << endl;
	printLeafNotInMap(head->left, n + 1, edgeMap);
	printLeafNotInMap(head->right, n + 1, edgeMap);
}
void printEdge1(Node *head)
{
	if (head == NULL)
		return;
	int height = getHeight(head, 0);
	Node* *edgeMap[2];
	for (int j = 0; j < height; j++)
	{
		edgeMap[j] = new Node*[2]();
	}
	setEdgeMap(head, 0, edgeMap);
	//��ӡ��߽�
	for (int i = 0; i < height; i++)
	{
		cout << edgeMap[i][0]->value << endl;
	}
	//��ӡ�Ȳ�����߽��ֲ����ұ߽��Ҷ�ӽڵ�
	printLeafNotInMap(head, 0, edgeMap);
	//��ӡ�ұ߽絫������߽�Ľڵ�
	for (int i = height - 1; i != -1; i--)
	{
		if (edgeMap[i][0] != edgeMap[i][1])
			cout << edgeMap[i][1]->value << endl;
	}
}

int main()
{
	Node *head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	printEdge1(head);
    return 0;
}

