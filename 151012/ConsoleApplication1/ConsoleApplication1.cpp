// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;
void CollectElement(int *L, int temp[10][10])
{
	int t = 0;
	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
		{
			if (temp[i][j] == 0)break;
			else
			{
				*L = temp[i][j];
				L++;
			}
		}
}
void RadixSort(int L[], int length, int maxradix)
{
	int m, n=0, k, lsp;
	k = 1; m = 1;
	int temp[10][10] = {};
	while (k<maxradix)
	{
		for (int i = 0; i<length; i++)
		{
			if (L[i]<m)
				temp[0][n] = L[i];
			else
			{ 
				lsp = (L[i] / m) % 10;
			    temp[lsp][n] = L[i];
			}
			n++;
		}
		CollectElement(L, temp);
		n = 0;
		m = m * 10;
		k++;
	}
}

int main()
{
	int L[10] = { 216,521,425,116,91,515,124,34,96,24 };
	for (int i = 0; i<10; i++)
	{
		cout << L[i]<<endl;
	}
	RadixSort(L, 10, 3);
	for (int i = 0; i<10; i++)
	{
		cout << L[i]<<" ";
	}
	return 0;
}




