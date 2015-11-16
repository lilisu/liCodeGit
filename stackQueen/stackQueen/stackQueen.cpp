// stackQueen.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "MyStack.h"
using namespace std;
int main()
{
	MyStack1<int> mystack1;// = new MyStack1();
	mystack1.push(3);
	mystack1.push(4);
	mystack1.push(5);
	mystack1.push(1);
	mystack1.push(2);
	mystack1.push(1);
	cout<<mystack1.pop();


    return 0;
}

