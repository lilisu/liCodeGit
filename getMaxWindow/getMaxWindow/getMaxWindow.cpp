// getMaxWindow.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<deque>
using namespace std;
int* getMaxWindow(int arr[], int w,int len)
{
	if (arr == NULL&&w < 1 &&  len < w)
	{
		return NULL;
	}
	deque<int> qmax;
	int index = 0;
	int* res = new int[len - w + 1];
	for (int i = 0; i < len; i++)
	{
		while (!qmax.empty() && arr[qmax.back()] <= arr[i])
		{
			qmax.pop_back();
		}
		qmax.push_back(i);
		if (qmax.front() == i - w)
		{
			qmax.pop_front();
		}
		if (i >= w - 1)
		{

			res[index] = arr[qmax.front()];
			index++;
		}
	}
	return res;
}

int main()
{
	int arr[] = { 4,2,5,4,3,3,6,7 };
	int w = 3;
	int len = sizeof(arr) / sizeof(arr[0]) ;
	int *res = getMaxWindow(arr, 3 , len);
	for (int i = 0; i < len - w + 1;i++)
	{
		cout << res[i] << "  ";
	}
    return 0;
}

