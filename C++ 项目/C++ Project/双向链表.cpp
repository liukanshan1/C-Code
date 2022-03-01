#include <iostream>
#include <string>
using namespace std;

struct Num
{
	string data;
	struct Num* next;
	struct Num* previous;
};

Num* CreateList(int n)
{
	Num* head = new Num; //����head
	head->previous = NULL; //head��previous�ÿ�
	Num* pre = head;
	for (int i = 0; i < n; i++)
	{
		Num* p = new Num;
		p->data = "data here";
		p->previous = pre; //this��previousָ��ǰһ����
		pre->next = p; //��һ����nextָ��this
		pre = p;  //����preΪthis
		p->next = NULL;  //this��next�ÿ�
	}
	return head;
}

void display(Num* head)
{
	Num* p = head->next;
	
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}

	p = head->next->next->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->previous;
	}

	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	Num* head = CreateList(n);
	display(head);
}