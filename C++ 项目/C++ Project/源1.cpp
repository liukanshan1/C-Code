#include<iostream>
#include<vector>
using namespace std;

class node
{
public:
	int index;
	node* next = nullptr;
};

class CircleLinkedList
{
public:
	void pushBack(int n) {
		node* newNode = new node;
		newNode->index = n;
		if (head == nullptr)
		{
			head = newNode;
			head->next = head;
			last = head;
		}
		else
		{
			newNode->next = head;
			last->next = newNode;
			last = newNode;
		}
	}
	node* head = nullptr;
	node* last = nullptr;
};

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		CircleLinkedList CLL;
		for (int i = 0; i < n; i++)
		{
			CLL.pushBack(i);
		}
		node* p = CLL.head;
		node* pre = CLL.last;	
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