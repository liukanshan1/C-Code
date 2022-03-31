#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<class T>
class Node
{
public:
	Node(T d)
	{
		data = d;
	}
	void output()
	{
		cout << this->data << " ";
	}
	T data;
	Node* next = nullptr;
};


int main()
{
	int temp;
	while (cin>>temp)
	{
		Node<int>* head = new Node<int>(temp);
		Node<int>* p = head;
		for (int i = 0; i < 5; i++)
		{
			cin >> temp;
			p->next = new Node<int>(temp);
			p = p->next;
		}
		p = head;
		while (p != nullptr)
		{
			p->output();
			p = p->next;
		} 
		cout << endl;
	}
	

}