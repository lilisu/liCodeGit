// Chain151014.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
#include<stack>
#include<deque>
//#include<hash_map>
using namespace std;
//������
class  Node
{
public:
	int data;
	Node *next;
	Node(int data) { this->data = data; }
};
//��������ڵ�ĵ�����
class randNode
{
public:
	int data;
	randNode *next;
	randNode *rand;
	randNode(int data) { this->data = data; }
};
//˫����
class DoubleNode
{
public:
	int data;
	DoubleNode *next;
	DoubleNode *last;
	DoubleNode(int data) { this->data = data; }
};
//��ӡ������������Ĺ�������
void printCommonPart(Node *head1, Node *head2)
{
	while (head1 != NULL&&head2 != NULL)
	{
		if (head1->data < head2->data)
		{
			head1 = head1->next;
		}
		else if(head2->data < head1->data)
		{
			head2 = head2->next;
		}
		else {
			cout << head1->data << "   ";
			head1 = head1->next;
			head2 = head2->next;
		}
	}
}
//ɾ���������е�����k��Ԫ��
Node *removeLastKthNode(Node *head, int lastKth)
{
	if (head == NULL || lastKth < 1)
	{
		return head;
	}
	Node *cur = head;
	while (cur != NULL)
	{
		lastKth--;
		cur = cur->next;
	}
	if (lastKth == 0)
	{
		return head;
	}
	if (lastKth < 0)
	{
		cur = head;
		while (++lastKth != 0)
		{
			cur = cur->next;
		}
		cur->next = cur->next->next;
	}
	return head;
}
//ɾ��˫�����е�����k��Ԫ��
DoubleNode *removeLastKthDoubleNode(DoubleNode *head, int lastKth)
{
	if (head == NULL || lastKth < 1)
	{
		return head;
	}
	DoubleNode *cur = head;
	while (cur != NULL)
	{
		cur = cur->next;
		lastKth--;
	}
	if (lastKth == 0)
	{
		head = head->next;
		head->last = NULL;
	}
	if (lastKth < 0)
	{
		cur = head;
		while (++lastKth != 0)
		{
			cur = cur->next;
		}
		DoubleNode *newNext = cur->next->next;
		cur->next = newNext;
		if(newNext!=NULL)
		{ 
		    newNext->last = cur;
		}

	}
	return head;
}
//��ӡ˫����
void printDoubleNodeList(DoubleNode *head)
{
	DoubleNode *cur = head;
	while (cur != NULL)
	{
		cout << cur->data<<"  ";
		cur = cur->next;
	}
	cout << endl;
}
//��ӡ������
template<class T>
void printNodeList(T *head)
{
	T *cur = head;
	while (cur != NULL)
	{
		cout << cur->data << "  ";
		cur = cur->next;
	}
	cout << endl;
}
void printCircleNodeList(Node *head)
{
	Node *cur = head;
	while (cur->next!= head)
	{
		cout << cur->data << "  ";
		cur = cur->next;
	}
	cout << cur->data;
	cout << endl;
}
//ɾ���м�λ�ýڵ�
Node *removeMidNode(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	if (head->next->next == NULL)
	{
		return head->next;
	}
	Node *p = head;
	Node *cur = head->next->next;
	while (cur->next != NULL&&cur->next->next != NULL)
	{
		p = p->next;
		cur = cur->next->next;
	}
	p->next = p->next->next;
	return head;
}
//ɾ��a/b���Ľڵ�
Node *removeByRatio(Node *head, int a, int b)
{
	if (a<1 || a>b)
		return head;
	Node *cur = head;
	int n = 0;
	while (cur != NULL)
	{
		n++;
		cur = cur->next;
	}
	n = (int)ceil((double)(a*n) / (double)b);//ceil������ȡ��
	cout << "Ӧ��ɾ����" << n << "��" << endl;
	if (n == 1)
	{
		head = head->next;
	}
	if (n > 1)
	{
		cur = head;
		while (--n>1)
		{
			cur = cur->next;
		}
		cur->next = cur->next->next;
	}
	return head;

}
//��ת������
Node *reverseList(Node *head)
{
	Node *pre = NULL;
	Node *next = NULL;
	while (head)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}
//��ת˫������
DoubleNode *reverseDoubleList(DoubleNode *head)
{
	DoubleNode *pre = NULL;
	DoubleNode *next = NULL;
	while (head)
	{
		next = head->next;
		head->next = pre;
		head->last = next;
		pre = head;
		head = next;
	}
	return pre;
}
//��ת��������
Node *reverseListPart(Node *head,int from,int to)
{
	Node *fpre = NULL;
	Node *tpos = NULL;
	Node *node1 = head;
	int len = 0;
	while (node1)
	{
		len++;
		fpre = len == from - 1 ? node1 : fpre;
		tpos = len == to + 1 ? node1 : tpos;
		node1 = node1->next;
	}
	if (from > to || from<1 || to>len)
	{
		return head;
	}
	node1 = fpre == NULL ? head : fpre->next;
	Node *node2 = node1->next;
	node1->next = tpos;
	Node * next1 = NULL;
	while (node2 != tpos)
	{
		next1 = node2->next;
		node2->next = node1;
		node1 = node2;
		node2 = next1;
	}
	if (fpre != NULL)
	{
		fpre->next = node1;
		return head;
	}
	return node1;
}
//Լɪ��
Node *josephusKill(Node *head, int m)
{
	if (head == NULL || head->next == head || m < 1)
	{
		return head;
	}
	Node *last = head;
	while (last->next!=head)
	{
		last = last->next;
	}
	int count = 0;
	while (head != last)
	{
		if (++count == m)
		{
			last->next = head->next;
			count = 0;
		}
		else {
			last = last->next;
		}
		head = head->next;
	}
	return head;
}
//�ж��Ƿ��ǻ������з���1���ռ临�Ӷ�O(n)
bool isPalindrome1(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	stack<Node*> stack;
	Node *cur = head;
	
	while (cur)
	{
		stack.push(cur);
		cur = cur->next;
	}
	while (head)
	{
		if (head->data != stack.top()->data)
		{
			return false;
		}
		stack.pop();
		head = head->next;
	}
	return true;
}
//�ж��Ƿ��ǻ������з���2
bool isPalindrome2(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	Node *s = head->next;
	Node *cur = head;
	stack<Node *> stack;
	while (cur->next != NULL&&cur->next->next != NULL)
	{
		s = s->next;
		cur = cur->next->next;
	}
	while (s)
	{
		stack.push(s);
		s = s->next;
	}
	while (!stack.empty())
	{
		if (head->data != stack.top()->data)
		{
			return false;
		}
		stack.pop();
		head = head->next;
	}
	return true;

}
//�ж��Ƿ��ǻ������з���3
bool isPalindrome3(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	Node *node1 = head;
	Node *node2 = head;
	while (node2&&node2->next)
	{
		node1 = node1->next;
		node2 = node2->next->next;
	}
	node2 = node1->next;
	node1->next = NULL;
	Node *node3 = NULL;
	while (node2)
	{
		node3 = node2->next;
		node2->next = node1;
		node1 = node2;
		node2 = node3;
	}
	node3 = node1;//�������ҽڵ�
	node2 = head;
	bool res = true;
	while (node1&&node2)
	{
		if (node1->data!=node2->data)
		{
			res = false;
			break;
		}
		node1 = node1->next;
		node2 = node2->next;
	}
	node1 = node3->next;
	node3->next = NULL;
	while (node1)
	{
		node2 = node1->next;
		node1->next = node3;
		node3 = node1;
		node1 = node2;
	}
	return res;

}
//����������ĳֵ���ֳ����С���м���ȣ��ұߴ����ʽ
void arrPartition(Node* *arrNode, int pivot, int len);
Node *listPartition1(Node *head, int pivot)
{
	int i = 0;
	Node *cur = head;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	int len = i;
	Node* *arrNode = new Node*[i];
	cur = head;
	while (i--)
	{
		arrNode[i] = cur;
		cur = cur->next;
	}
	arrPartition(arrNode, pivot,len);
	for (i = 1; i < len; i++)
	{
		arrNode[i-1]->next = arrNode[i];
	}
	arrNode[i - 1]->next = NULL;
	return arrNode[0];
}
void swap(Node* *arrNode, int a, int b);
void arrPartition(Node* *arrNode, int pivot,int len)
{
	int left = -1;
	int index = 0;
	int right = len;
	while (index != right)
	{
		if (arrNode[index]->data == pivot)
		{
			index++;
		}
		else if (arrNode[index]->data < pivot)
		{
			swap(arrNode, index++, ++left);
		}
		else {
			swap(arrNode, index, --right);
		}
	}
}
void swap(Node* *arrNode, int a, int b)
{
	Node* temp = arrNode[a];
	arrNode[a] = arrNode[b];
	arrNode[b] = temp;
}
//����������ĳֵ���ֳ����С���м���ȣ��ұߴ����ʽ,����2
Node *listPartition2(Node *head, int pivot)
{
	Node *sH = NULL;
	Node *sT = NULL;
	Node *eH = NULL;
	Node *eT = NULL;
	Node *bH = NULL;
	Node *bT = NULL;
	Node *next = NULL;
	while (head)
	{
		next = head->next;
		head->next = NULL;
		if (head->data < pivot)
		{
			if (sH == NULL)
			{
				sH = head;
				sT = head;
			}
			else {
				sT->next = head;
				sT = head;
			}
		}
		else if (head->data == pivot)
		{
			if (eH == NULL)
			{
				eH = head;
				eT = head;
			}
			else {
				eT->next = head;
				eT = head;
			}
		}
		else {
			if (bH == NULL)
			{
				bH = head;
		    	bT = head;
			}
			else {
				bT->next = head;
				bT = head;
			}
		}
		head = next;
	}
	if (sT)
	{
		sT->next = eH;
		eT = eT == NULL ? sT : eT;
	}
	if (eT)
	{
		eT->next = bH;
	}
	return sH != NULL ? sH : eH != NULL ? eH : bH;
}
//���ƺ������ָ��ڵ������1
//randNode* copyListWithRand1(randNode *head)
//{
//	randNode *cur = head;
//	hash_map<randNode*, randNode> map;//
//	while (cur)
//	{
//		map[cur] = randNode(cur->data);
//		cur = cur->next;
//	}
//	cur = head;
//	while (cur)
//	{
//		(&map[cur])->next = &map[cur->next];
//		(&map[cur])->rand = &map[cur->rand];
//		cur = cur->next;
//	}
//	return &map[head];
//	
//}
//���ƺ������ָ��ڵ��������2
randNode* copyListWithRand2(randNode *head)
{
	if (head)
	{
		return head;
	}
	randNode *cur = head;
	randNode *next = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = new randNode(cur->data);
		cur->next->next = next;
		cur = next;
	}
	cur = head;
	randNode* curCopy = NULL;
	while (cur)
	{
		next = cur->next->next;
		curCopy = cur->next;
		curCopy->rand = cur->rand == NULL ? NULL : cur->rand->next;
		cur = next;
	}
	cur = head;
	next = NULL;
	randNode *res = cur->next;
	while (cur)
	{
		next = cur->next->next;
		curCopy = cur->next;
		cur->next = next;
		curCopy->next = next == NULL ? NULL : next->next;
		cur = next;
	}
	return res;
}
//�����������������������1
Node* addList(Node *head1, Node *head2)
{
	Node *cur = head1;
	stack<Node*> stack1,stack2 ;
	while (cur)
	{
		stack1.push(cur);
		cur = cur->next;
	}
	cur = head2;
	while (cur)
	{
		stack2.push(cur);
		cur = cur->next;
	}
	int ca = 0;
	int sum = 0;
	int n1 = 0;
	int n2 = 0;
	Node *node1 = NULL;
	Node *pre = NULL;

	while (!stack1.empty() || !stack2.empty())
	{

		n1 = stack1.empty() ? 0 : stack1.top()->data;
		n2 = stack2.empty() ? 0 : stack2.top()->data;
		sum = n1 + n2 + ca;
		ca = sum / 10;
		pre = node1;
		node1 = new Node(sum % 10);
		node1->next = pre;
		if (!stack1.empty())
		{
			stack1.pop();
		}
		if (!stack2.empty())
		{
			stack2.pop();
		}
	}
	if (ca == 1)
	{
		pre = node1;
		node1 = new Node(1);
		node1->next = pre;
	}
	return node1;
}
//�����������������������2
Node* addList2(Node *head1, Node *head2)
{
	
	head1 = reverseList(head1);
	head2 = reverseList(head2);
	int ca = 0;
	int sum = 0;
	int n1 = 0;
	int n2 = 0;
	Node* newNode = NULL;
	Node* pre = NULL;
	Node* cur1 = head1;
	Node* cur2 = head2;
	while (cur1 || cur2)
	{
		n1 = cur1 != NULL ? cur1->data : 0;
		n2 = cur2 != NULL ? cur2->data : 0;
		sum = n1 + n2 + ca;
		ca = sum / 10;
		newNode = new Node(sum % 10);
		newNode->next = pre;
		pre = newNode;
		if (cur1)
		{
			cur1 = cur1->next;
		}
		if (cur2)
		{

			cur2 = cur2->next;
		}
	}
	if (ca)
	{
		newNode = new Node(1);
		newNode->next = pre;
	}
	Node *res = newNode;
	head1 = reverseList(head1);
	head2 = reverseList(head2);
	return res;
}
//�жϵ������Ƿ��л��������ص�һ�����뻷�Ľڵ�
Node *getLoopNode(Node* head)
{
	if (head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return NULL;
	}
	Node *fast = head->next->next;
	Node *slow = head->next;
	while (fast != slow)
	{
		if (fast->next == NULL || fast->next->next == NULL)
		{
			return NULL;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
	
}
//�ҳ�û�л������������ཻ�Ľڵ�
Node *noLoop(Node* head1, Node* head2)
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	Node *cur1 = head1;
	Node *cur2 = head2;
	int n = 0;
	while (cur1->next)
	{
		n++;
		cur1 = cur1->next;
	}
	while (cur2->next)
	{
		n--;
		cur2 = cur2->next;
	}
	if (cur1 != cur2)
	{
		return NULL;
	}
	cur1 = n > 0 ? head1 : head2;
	cur2 = cur1 == head1 ? head2 : head1;
	n = abs(n);
	while (n)
	{
		n--;
		cur1 = cur1->next;
	}
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}
//�ҳ��л������������ཻ�Ľڵ�
Node *bothLoop(Node *head1, Node* loop1, Node *head2, Node *loop2)
{
	Node *cur1 = NULL;
	Node *cur2 = NULL;
	if (loop1 == loop2)
	{
		cur1 = head1;
		cur2 = head2;
		int n = 0;
		while (cur1 != loop1)
		{
			n++;
			cur1 = cur1->next;
		}
		while (cur2 != loop2)
		{
			n--;
			cur2 = cur2->next;
		}
		cur1 = n > 0 ? head1 : head2;
		cur2 = cur1 == head1 ? head2 : head1;
		n = abs(n);
		while (n)
		{
			cur1 = cur1->next;
			n--;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else {
		cur1 = loop1->next;
		while (cur1 != loop1)
		{
			if (cur1 == loop2)
			{
				return cur1;
			}
			cur1 = cur1->next;
		}
		return NULL;
	}
}
Node* getIntersectNode(Node *head1, Node *head2)
{
	if (head1==NULL||head2==NULL)
	{
		return NULL;
	}
	Node *loop1 = getLoopNode(head1);
	Node *loop2 = getLoopNode(head2);
	if (loop1 == NULL&&loop2 == NULL)
	{
		return noLoop(head1, head2);
	}
	if (loop1 != NULL&&loop2 != NULL)
	{
		return bothLoop(head1, loop1, head2, loop2);
	}
	return NULL;
}
//��������ÿk���ڵ����򷽷�1
Node*resign(stack<Node*> stack, Node *left, Node *right);
Node* reverserKNode(Node *head, int k)
{
	if (k < 2)
	{
		return head;
	}
	stack<Node*> stack;
	Node* newHead = head;
	Node* cur = head;
	Node* pre = NULL;
	Node* next = NULL;
	while (cur)
	{
		next = cur->next; 
		stack.push(cur);
		if (stack.size() == k)
		{
			pre = resign(stack, pre, next);
			newHead = newHead == head ? cur : newHead;
		}
		cur = next;
	}
	return newHead;
}
Node* resign(stack<Node*> stack, Node* left, Node* right)
{
	Node *cur = stack.top();
	stack.pop();
	if (left != NULL)
	{
		left->next = cur;
	}
	Node *next = NULL;
	while (!stack.empty())
	{
		next = stack.top();
		cur->next = next;
		cur = next;
		stack.pop();
	}
	cur->next = right;
	return cur;
}
//��������ÿk���ڵ����򷽷�2
void resign2(Node* left, Node* start, Node* end, Node* right);
Node *reverserKNode2(Node *head,int k)
{
	if (k < 2)
	{
		return head;
	}
	Node *start = NULL;
	Node *pre = NULL;
	Node *cur = head;
	Node *next = NULL;
	int count = 0;
	while (cur)
	{
		next = cur->next;
		count++;
		if (count == k)
		{
			start = pre == NULL ? head : pre->next;
			head = pre == NULL ? cur : head;
			resign2(pre, start, cur, next);
			pre = start;
			count = 0;
		}
		cur = next;
	}
	return head;
}
void resign2(Node *left, Node *start, Node *end, Node *right)
{
	Node* pre = start;
	Node* cur = start->next;
	Node* next = NULL;
	while (cur != right)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	if (left)
	{
		left->next = pre;
	}
	start->next = right;
}
//������������ת����˫��������1
void inOrderToQueue(DoubleNode *head,deque<DoubleNode*> * queue);
DoubleNode* convert1(DoubleNode *head)
{
	deque<DoubleNode*> queue;
	inOrderToQueue(head, &queue);
	if (queue.empty())
	{
		return head;
	}
	head = queue.front();
	queue.pop_front();
	DoubleNode *pre = head;
	pre->last = NULL;
	DoubleNode *cur = NULL;
	while (!queue.empty())
	{
		cur = queue.front();
		queue.pop_front();
		pre->next = cur;
		cur->last = pre;
		pre = cur;
	}
	pre->next = NULL;
	return head;
}
void inOrderToQueue(DoubleNode *head,  deque<DoubleNode*> *queue)
{
	if (head == NULL)
	{
		return ;
	}
	inOrderToQueue(head->last, queue);
	(*queue).push_back(head);
	inOrderToQueue(head->next, queue);
}
//������������ת����˫������2
DoubleNode* process(DoubleNode* head)
{
	if (head==NULL)
	{
		return NULL;
	}
	DoubleNode* leftE = process(head->last);
	DoubleNode* rightE = process(head->next);
	DoubleNode* leftS = leftE == NULL ? NULL : leftE->next;
	DoubleNode* rightS = rightE == NULL ? NULL : rightE->next;
	if (leftE&&rightE)
	{
		leftE->next = head;
		head->last = leftE;
		head->next = rightS;
		rightS->last = head;
		rightE->next = leftS;
		return rightE;
	}
	else if (leftE)
	{
		leftE->next = head;
		head->last = leftE;
		head->next = leftS;
		return head;
	}
	else if (rightE)
	{
		head->next = rightS;
		rightS->last = head;
		rightE->next = head;
		return rightE;
	}
	else {
		head->next = head;
		return head;
	}
}
DoubleNode* convert2(DoubleNode* head)
{
	if (head==NULL)
	{
		return NULL;
	}
	DoubleNode *last = process(head);
	head = last->next;
	last->next = NULL;
	return head;
}
//��������ѡ������
Node* smallPreNode(Node* head) 
{
	Node *cur = head->next;
	Node *pre = head;
	Node *small = head;
	Node *smallPre = NULL;
	while (cur)
	{
		if (cur->data < small->data)
		{
			small = cur;
			smallPre = pre;
		}
		pre = cur;
		cur = cur->next;
	}
	return smallPre;
}
Node* selectionSort(Node* head)
{
	Node* cur = head;
	Node* smallPre = NULL;
	Node* small = NULL;
	Node* tail = NULL;
	while (cur)
	{
		small = cur;
		smallPre = smallPreNode(cur);
		if (smallPre != NULL)
		{
			small = smallPre->next;
			smallPre->next = small->next;
		}
		cur = cur == small ? cur->next : cur;
		if (tail == NULL)
		{
			head = small;
			
		}
		else {
			tail->next = small;
		}
		tail = small;
	}
	return head;
}
//������Ļ��������в����½ڵ�
Node* insertNum(Node *head,int num)
{
	Node* node = new Node(num);
	if (head == NULL)
	{
		node->next = node;
		return node;
	}
	Node* pre = head;
	Node* cur = head->next;
	while (cur!=head)
	{
		if (pre->data <= num&&cur->data >= num)
		{
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	pre->next = node;
	node->next = cur;
	return num > head->data ? head : node;
}
//�ϲ���������ĵ�����
Node* merge(Node* head1, Node* head2)
{

	if (head1 == NULL || head2 == NULL)
	{
		return  head1 == NULL ? head2 : head1;
	}
	Node* cur = NULL;
	Node* head = head1->data > head2->data ? head2 : head1;
	cur = head;
	Node* cur1 = head1->data == head->data ? head1->next : head1;
	Node* cur2 = head2->data == head->data ? head2->next : head2;
	while (cur1&&cur2)
	{
		if (cur1->data < cur2->data)
		{
			cur->next = cur1;
			cur = cur1;
			cur1 = cur1->next;
		}
		else
		{
			cur->next = cur2;
			cur = cur2;
			cur2 = cur2->next;
		}
	}
	cur->next = cur1 == NULL ? cur2 : cur1;
	return head;
}
//�������Ұ����ķ�ʽ������ϵ�����
void remerge(Node *head)
{
	Node *cur = head;
	Node *right = head->next;
	while (right->next&&right->next->next)
	{
		right = right->next->next;
		cur = cur->next;
	}
	right = cur->next;
	cur->next = NULL;
	cur = head;
	Node *next = NULL;
	while (cur->next != NULL)
	{
		next = right->next;
		right->next = cur->next;
		cur->next = right;
		cur = right->next;
		right = next;
	}
	cur->next = right;
}

int main()
{
	Node *node1 = new Node(9);
	node1->next = new Node(3);
	node1->next->next = new Node(7);
	node1->next->next->next = new Node(6);

	Node *node2 = new Node(6);
	node2->next = new Node(3);
	node2->next->next = new Node(3);
	//node2->next->next->next = new Node(4);
	//node2->next->next->next->next = new Node(5);
	//node2->next->next->next->next->next = new Node(2);
	//node2->next->next->next->next->next->next = new Node(1);
//	printCommonPart(node1, node2);
//	cout << endl;
	//removeLastKthNode(node2,3);
	//printCommonPart(node1, node2);


	DoubleNode *doubleNode = new DoubleNode(2);
	doubleNode->next = new DoubleNode(4);
	doubleNode->last = NULL;
	doubleNode->next->last = doubleNode;
//	printDoubleNodeList(doubleNode);
//	removeLastKthDoubleNode(doubleNode, 1);
//	printDoubleNodeList(doubleNode);

	//removeMidNode(node2);
	//printNodeList(node2);
	//removeByRatio(node2, 1, 6);
	/*cout << "����" << endl;
	printNodeList(node2);
	node2=reverseList(node2);
	cout << "��ת��" << endl;
	printNodeList(node2);


	cout << "��תǰ��" << endl;
	printDoubleNodeList(doubleNode);
	doubleNode = reverseDoubleList(doubleNode);
	cout << "��ת��" << endl;
	printDoubleNodeList(doubleNode);*/

//	node2=reverseListPart(node2, 1, 5);
//	printNodeList(node2);




	Node *node3 = new Node(1);
	node3->next = new Node(2);
	node3->next->next = new Node(3);
	node3->next->next->next = new Node(4);
	node3->next->next->next->next = new Node(5);
	node3->next->next->next->next->next = new Node(6);
	node3->next->next->next->next->next->next = new Node(7);
	node3->next->next->next->next->next->next->next = node3;
	printCircleNodeList(node3);
	//node3 = josephusKill(node3, 4);
	//printCircleNodeList(node3);


	/*if (isPalindrome3(node2))
	{
		cout << "�ǻ�������" << endl;
	}
	else {
		cout << "���ǻ�������" << endl;
	}
	printNodeList(node2);

	node2=listPartition2(node2,3);
	printNodeList(node2);
*/
	//randNode *node4 = new randNode(1);
	//node4->next = new randNode(2);
	//node4->next->next = new randNode(3);
	//node4->rand = node4->next->next;
	//node4->next->rand = NULL;
	//node4->next->next->rand = node4;
	//randNode *node5 = copyListWithRand2(node4);
	//printNodeList(node5);


	Node* node6 = addList2(node1, node2);
	printNodeList(node6);
	printNodeList(node1);
	printNodeList(node2);


	Node *node7 = reverserKNode2(node1, 2);
	printNodeList(node7);
	

	DoubleNode *node8 = new DoubleNode(1);
	node8->last = new DoubleNode(2);
	node8->next = new DoubleNode(3);
	DoubleNode *node9 = convert2(node8);
	printDoubleNodeList(node9);
	
	printNodeList(node1);
	Node* node10 = selectionSort(node1);
	printNodeList(node10);


	Node* node11 = new Node(0);
	node11->next = new Node(2);
	node11->next->next = new Node(3);
	node11->next->next->next = new Node(4);
//	Node* node12 = new Node(1);
//	node12->next = new Node(3);
//	Node* node13 = merge(node11, node12);
////	printNodeList(node11);
////	printNodeList(node12);
//	printNodeList(node13);
//
	remerge(node11);
	printNodeList(node11);
	
    return 0;
}

