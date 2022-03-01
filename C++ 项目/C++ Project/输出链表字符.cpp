#include <iostream>
#include <string>
using namespace std;

struct Num
{
	string s;
	Num* next;
}; 

Num* CreateList(int n,string s)
{
	Num* head = new Num; //定义head
	Num* pre = head;
	for (int i = n-1; i >= 0; i--)
	{
		Num* p = new Num;
		p->s = s[i];
		pre->next = p; //上一个的next指向this
		pre = p;  //重置pre为this
		p->next = NULL;  //this的next置空
	}
	return head;
}

void display(Num* head)
{
	Num* p = head->next;
	while (p!=NULL)
	{
		cout << p->s;
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int i = 3;
	while (i)
	{
		int n;
		string s;
		cin >> s;
		n = s.length();
		Num* head = CreateList(n, s);
		display(head);
		i--;
	}
}

////翻转数字链表
//Num* p = head->next; //头结点之后的第1个节点
//Num* q = head->next->next; //头结点之后的第2节点
//Num* m = head->next->next->next; //头结点之后的第3个节点
//p->next = NULL; //将头接点之后的第1个节点的next指针置为空
//while (m) //根据m是否为空来判断 以此逆序每一个节点
//{
//	q->next = p;
//	p = q;
//	q = m;
//	m = m->next;
//}
//q->next = p; //将最后一个节点逆序
//head->next = q; //将头从新指向新的的第1节点