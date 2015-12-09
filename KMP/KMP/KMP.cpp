// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int* getNextArray(string s)
{
	int* next = new int();
	if (s.length == 0)
		return next;
	*next = -1;
	*(next + 1) = 0;
	int pos = 2;
	int cn = 0;
	while (pos < s.length)
	{
		if (s[pos] == s[cn])
		{
			*(next + pos) = ++cn;
			pos++;
		}
		else if (cn>0) {
			cn = *(next + cn);
		}
		else {
			*(next + pos) = 0;
			pos++;
		}
	}
	return next;
}
int getIndexof(string s, string m) {
	if (s.length < m.length) {
		return -1;
	}
	int si = 0;
	int mi = 0;
	int* next = getNextArray(m);

}
int main()
{
    return 0;
}

