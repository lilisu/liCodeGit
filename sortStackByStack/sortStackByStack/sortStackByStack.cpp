// sortStackByStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;
void stackByStack(stack<int> &sta)
{
	stack<int> help;
	while (!sta.empty())
	{
		int cur = sta.top();
		sta.pop();
		while (!help.empty() && cur < help.top())
		{
			sta.push(help.top());
			help.pop();
		}
		help.push(cur);
	}
	while (!help.empty())
	{
		sta.push(help.top());
		help.pop();
	}
}
int main()
{
	stack<int> sta;
	sta.push(3);
	sta.push(2);
	sta.push(1);
	sta.push(4);
	sta.push(5);
	stackByStack(sta);
	while (!sta.empty())
	{
		cout << sta.top() << endl;
		sta.pop();
	}
	return 0;
}

