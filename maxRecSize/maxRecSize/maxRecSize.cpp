// maxRecSize.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;
int maxRecFromBottom(int height[]);
int maxRecSize(int map[][4],int rsize,int csize)
{
	if (map == NULL || csize == 0 || rsize == 0)
	{
		return 0;
	}
	int maxArea = 0;
	int *height = new int[rsize];
	for (int i = 0; i < rsize; i++)
	{
		for (int j = 0; j < csize; j++)
		{
			height[j] = 0;
		}
	}
	for (int i = 0; i < rsize; i++)
	{
		for (int j = 0; j < csize; j++)
		{
			height[j] = map[i][j] == 0 ? 0 : height[j]+1;
		}
		int max = maxRecFromBottom(height);
		maxArea = max > maxArea ? max : maxArea;
	}
	return maxArea;
}
int maxRecFromBottom(int *height)
{
	int len = 4;
	if (height == NULL || len == 0)
	{
		return 0;
	}
	stack<int> stack;
	int maxArea = 0;
	for (int i = 0; i < len; i++)
	{
		while (!stack.empty() && height[i] <= height[stack.top()])
		{
			int j = stack.top();
			stack.pop();
			int k = stack.empty() ? -1 : stack.top();
			int curArea = (i - k - 1)*height[j];
			maxArea = curArea > maxArea ? curArea : maxArea;
		}
		stack.push(i);
	}
	while (!stack.empty())
	{
		int j = stack.top();
		stack.pop();
		int k = stack.empty() ? -1 : stack.top();
		int curArea = (len - k - 1)*height[j];
		maxArea = curArea > maxArea ? curArea : maxArea;
	}
	return maxArea;
}
int height[4];
int main()
{
	int map[3][4] = { 1,0,1,1,1,1,1,1,1,1,1,0 };
	cout<< maxRecSize(map,3,4)<<endl;
	// = new int[3];
	cout << height[1];
    return 0;
}

