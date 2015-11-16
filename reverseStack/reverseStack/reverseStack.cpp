// reverseStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;
void printStack(stack<int> stack)
{
	while (!stack.empty())
	{
		cout << stack.top();
		stack.pop();
	}
	cout << endl;
}
static int getAndRemove(stack<int> &stack)
{
	int result = stack.top();
	stack.pop();

	if (stack.empty())
	{
		return result;
	}
	else {
		int last = getAndRemove(stack);
		stack.push(result);
		return last;
	}
}
static void reverse(stack<int> &stack)
{
	if (stack.empty())
	{
		return;
	}
	int i = getAndRemove(stack);
	reverse(stack);
	stack.push(i);
}

int main()
{
	stack<int> stack  ;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	printStack(stack);
	reverse(stack);
	printStack(stack);
    return 0;
}

