#include<iostream>
#include<string>
using namespace std;

class Book
{
public:
	Book();
	~Book();
	int display()
	{
		return number * price;
	}
	int borrow()
	{
		number--;
		return number;
	}
	int restore()
	{
		number++;
		return number;
	}
	string bookname;
	int price;
	int number;
private:

};

Book::Book()
{
}

Book::~Book()
{
}

int main()
{
	Book b;
	cin >> b.bookname >> b.price >> b.number;
	cout << b.bookname <<" " << b.price<<" " << b.number << endl;
	for (int i = 0; i < 5; i++)
	{
		char temp;
		cin >> temp;
		switch (temp)
		{
		case 'B':
			cout << b.borrow() << endl;
			break;
		case 'R':
			cout << b.restore() << endl;
			break;
		case 'C':
			cout << b.display() << endl;
			break;
		default:
			break;
		}

	}
}