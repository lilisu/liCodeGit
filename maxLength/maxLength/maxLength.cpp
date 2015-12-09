// maxLength.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 
#include<iostream>
#include<hash_map>
using namespace std;

int maxLength(int arr[], int k,int arrlen)
{
	hash_map<int, int> map;
	int sum = 0;
	int len = 0;
	map.insert(make_pair(0 ,-1));
	for (int i = 0; i < arrlen; i++)
	{
		sum = sum + *(arr+i);
		if (map.count(sum - k)==1)
		{
			len = (i - map[sum - k])>len ? (i - map[sum - k]) : len;
		}
		if(map.count(sum)==0) {
			map.insert(sum, i);
		}
	}
	return len;
}

int main()
{
	int arr[4] = {1,2,3,3};
	 int len = maxLength(arr, 6, 4);
	cout << len << endl;
    return 0;
}

