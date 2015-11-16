// hanoiProblem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<stack>
using namespace std;
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		cout << a << "----->" << c<<endl;
	}
	else {
		hanoi(n - 1, a, c, b);
		cout << a << "----->" << c<<endl;
		hanoi(n - 1, b, a, c);
	}
}
int process(int num, string left, string mid, string right, string from, string to);
int hanoiProblem(int num, string left, string mid, string right)
{
	if (num < 1)
		return 0;
	return process(num, left, mid, right, left, right);
}
int process(int num, string left, string mid, string right, string from, string to)
{
	if (num == 1)
	{
		if (from == mid || to == mid)
		{
			cout << "move from " << from << " to " << to << endl;
			return 1;
		}
		else {
			cout << "move from " << from << " to mid" << endl;
			cout << "move from mid to " << to << endl;
			return 2;
		}
	}
	if (from == mid || to == mid)
	{
		string another = (from == "left" || to == "left") ? right : left;
		int part1 = process(num - 1, left, mid, right, from, another);
		cout << "move from " << from << " to " << to << endl;
		int part2 = process(num - 1, left, mid, right, another, from);
		return part1 + part2 + 1;
	}
	else {
		int part3 = process(num - 1, left, mid, right, from, to);
		cout << "move from " << from << " to  " << mid<< endl;
		int part4 = process(num - 1, left, mid, right, to, from);
		cout << "move from mid to " << to<<endl;
		int part5 = process(num - 1, left, mid, right, from, to);
		return part3 + part4 + part5 + 2;
	}
}
enum Action {
	No,LToM,MToL,RToM,MToR
};
int fStackTotStack(Action *record, Action preNoAct, Action nowAct, stack<int> &fStack, stack<int> &tStack,string from,string to);
int hanioProblem2(int num, string left, string mid, string right)
{
	stack<int> ls;
	stack<int> ms;
	stack<int> rs;
	ls.push(numeric_limits<int>::max());//也可以用INT32_MAX
	ms.push(numeric_limits<int>::max());
	rs.push(numeric_limits<int>::max());
	
	for (int i = num; i > 0; i--)
	{
		ls.push(i);
	}
	Action *record = new Action[1];
	record[0] = { Action::No};
	int step = 0;
	while (rs.size() != num + 1)
	{
		step += fStackTotStack(record, Action::MToL, Action::LToM, ls, ms , left , mid );
		step += fStackTotStack(record, Action::LToM, Action::MToL, ms, ls , mid , left );
		step += fStackTotStack(record, Action::MToR, Action::RToM, rs, ms , right ,mid );
		step += fStackTotStack(record, Action::RToM, Action::MToR, ms, rs , mid , right);
	}
	return step;
}
int fStackTotStack(Action *record, Action preNoAct, Action nowAct, stack<int> &fStack, stack<int> &tStack,string from,string to)
{
	if (record[0] != preNoAct&&fStack.top() < tStack.top())
	{
		tStack.push(fStack.top());
		fStack.pop();
		cout << "move from " << from << " to " << to << endl;
		record[0] = nowAct;
		return 1;
	}
	return 0;
}
int main()
{

	hanoi(3, 'a','b','c');
	hanoiProblem(2, "left", "mid", "right");
	hanioProblem2(2, "left", "mid", "right");
    return 0;
}

