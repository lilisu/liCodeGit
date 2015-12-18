// isPostArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
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
bool isPost(int *arr, int start, int end);
bool isPostArray(int *arr,int len)
{
	if (len <= 0 || arr == NULL)
	{
		return false;
	}
	int start = 0;
	int end = len - 1;
	return isPost(arr, start, end);
}
bool isPost(int *arr, int start, int end)
{
	if (start == end)
		return true;
	int less = -1;
	int more = end;
	for (int i = start; i < end; i++) {
		if (*(arr + i) < *(arr + end))
		{
			less = i;
		}
		else {
			more = more == end ? i : more;
		}
	}
	if (less == -1 || more == end)
	{
		return isPost(arr, start, end - 1);
	}
	if (less + 1 != more)
	{
		return false;
	}
	return isPost(arr, start, less) && isPost(arr, more, end - 1);
}
Node* posToBST(int *arr, int start,int end);
Node* posArrayToBST(int *arr, int len)
{
	if (arr == NULL || len <= 0)
		return NULL;
	return posToBST(arr, 0, len - 1);
}
Node* posToBST(int *arr, int start, int end)
{
	if (start > end)
		return NULL;
	Node* head = new Node(*(arr + end));
	int less = -1;
	int more = end;
	for (int i = start; i < end; i++)
	{
		if (*(arr + i) < *(arr + end))
		{
			less = i;
		}
		else {
			more = more == end ? i : more;
		}
	}
	head->left = posToBST(arr, start, less);
	head->right = posToBST(arr, more, end-1);
	return head;
}
void printTree(Node* head)
{
	if (head == NULL)
		return;
	printTree(head->left);
	cout << head->value << endl;
	printTree(head->right);
}
int main()
{
	int arr[7] = { 2,1,3,6,5,7,4 };
	cout << isPostArray(arr, 7)<<endl;
	Node* head = posArrayToBST(arr, 7);
	printTree(head);
    return 0;
}

