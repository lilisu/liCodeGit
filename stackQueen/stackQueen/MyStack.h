#pragma once
#ifndef MyStack1_
#define MyStack1_
#include"stdafx.h"
#include<stack>
#include"stdexcept"
#include<iostream>
using namespace std;
template <class T>
class MyStack1
{
private:
	stack<int> stackData;
	stack<int> stackMin;
public:
	//MyStack1(); 
	void push(T newNum);
	T pop();
	T getMin();
};
//template<class T>
//MyStack1<T>::MyStack1()
//{
//	 this->stackData = new stack<int>();
//	 this->stackMin = new stack<int>(); 
//}
template <class T>
void MyStack1<T>:: push(T newNum)
{
	if (this->stackMin.empty())
	{
		this->stackMin.push(newNum);
	}
	else if (newNum <= this->getMin())
	{
		this->stackMin.push(newNum);
	}
	this->stackData.push(newNum);
}
template <class T>
T MyStack1<T>:: pop()
{
	if (this->stackData.empty())
	{
		throw new runtime_error("your stack is empty");
	}
	int value = this->stackData.top();
	this->stackData.pop();
	if (value == this->getMin())
	{
		this->stackMin.pop();
	}
	return value;
}
template <class T>
T MyStack1<T>:: getMin()
{
	if (this->stackMin.empty())
	{
		throw new runtime_error("your stack is empty");
	}
	int value = this->stackMin.top();
	this->stackMin.pop();
	return value;
}
#endif