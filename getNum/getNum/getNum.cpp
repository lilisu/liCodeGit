// getNum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<deque>
using namespace std;
int getNum(int arr[], int num,int len)
{
	if (len==0||arr == NULL || num < 0)
	{
		return 0;
	}
	deque<int> qmin;
	deque<int> qmax;
	int i = 0, j = 0, res = 0;
	while (i < len)
	{
	
		while (j < len)
		{
			while (!qmin.empty() && arr[qmin.back()]>=arr[j])
			{
				qmin.pop_back();
			}
			qmin.push_back(j);
			while (!qmax.empty() && arr[qmax.back()] <= arr[j])
			{
				qmax.pop_back();
			}
			qmax.push_back(j);
			if ((arr[qmax.front()] - arr[qmin.front()]) > num)
			{
				break;
			}
			j++;
		}
		if (qmin.front() == i)
		{
			qmin.pop_front();
		}
		if (qmax.front() == i)
		{
			qmax.pop_front();
		}

		res += j - i;
		i++;
	}
	return res;
}

int main()
{
	int arr[5] = { 3,4,5,2,6 };//, 8, 1, 7, 9, 10
	int num = 3;
	int res=getNum(arr, num,5);
	cout << res;
    return 0;
}

