#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int index;
	node* next = nullptr;
};
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		node* head = new node;
		head->index = 0;
		node* p = head;
		for (int i = 1; i < n; i++)
		{
			p->next = new node;
			p->next->index = i;
			p = p->next;
		}
		p->next = head;
		node* pre = p;
		p = head;
		while (p->next != p)
		{
			int i = 0;
			do
			{
				p = p->next;
				pre = pre->next;
				i++;
			} while (i != m - 1);
			pre->next = p->next;
			delete p;
			p = pre->next;
		}
		cout << p->index << endl;
	}
}