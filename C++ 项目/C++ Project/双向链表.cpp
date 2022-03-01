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
	Num* head = new Num; //定义head
	head->previous = NULL; //head的previous置空
	Num* pre = head;
	for (int i = 0; i < n; i++)
	{
		Num* p = new Num;
		p->data = "data here";
		p->previous = pre; //this的previous指向前一个；
		pre->next = p; //上一个的next指向this
		pre = p;  //重置pre为this
		p->next = NULL;  //this的next置空
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