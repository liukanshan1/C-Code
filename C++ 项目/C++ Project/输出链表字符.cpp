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
	Num* head = new Num; //����head
	Num* pre = head;
	for (int i = n-1; i >= 0; i--)
	{
		Num* p = new Num;
		p->s = s[i];
		pre->next = p; //��һ����nextָ��this
		pre = p;  //����preΪthis
		p->next = NULL;  //this��next�ÿ�
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

////��ת��������
//Num* p = head->next; //ͷ���֮��ĵ�1���ڵ�
//Num* q = head->next->next; //ͷ���֮��ĵ�2�ڵ�
//Num* m = head->next->next->next; //ͷ���֮��ĵ�3���ڵ�
//p->next = NULL; //��ͷ�ӵ�֮��ĵ�1���ڵ��nextָ����Ϊ��
//while (m) //����m�Ƿ�Ϊ�����ж� �Դ�����ÿһ���ڵ�
//{
//	q->next = p;
//	p = q;
//	q = m;
//	m = m->next;
//}
//q->next = p; //�����һ���ڵ�����
//head->next = q; //��ͷ����ָ���µĵĵ�1�ڵ�