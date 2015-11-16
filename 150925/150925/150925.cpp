// 150925.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
template < class T>
class DoubleN;
template<class T>
class DoubleNode
{
	friend DoubleN<T>;

private:
	T data;
	DoubleNode<T> *left, *right;
};
template <class T>
class DoubleN
{
public:
	DoubleN() { LeftEnd = RightEnd = 0; }
	~DoubleN();
	int Length() const;
	bool Find(int k, T& x)const;
	int Search(const T& x)const;
	DoubleN<T>& Delete(int k, T& z);
	DoubleN<T>& Insert(int k, const T& x);
	void Output(ostream& out) const;

private:
	DoubleNode<T> *LeftEnd, *RightEnd;
};


int main()
{
	cout << "haha";
	system("pause");
    return 0;
}

