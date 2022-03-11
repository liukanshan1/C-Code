#include<iostream>
#include<vector>
#include<functional>

using namespace std;

class Base1 {
public:
	void p1() { cout << "Base1::p1()" << endl; }
	void p2() { cout << "Base1::p2()" << endl; }
	void p3() { cout << "Base1::p3()" << endl; }
};

vector<function<void()>> m_vecFunc;

void fucPrint1()
{
	cout << "fucPrint1()" << endl;
}
void fucPrint2()
{
	cout << "fucPrint2()" << endl;
}
void fucPrint3()
{
	cout << "fucPrint3()" << endl;
}
int main()
{
	Base1 b1;
	m_vecFunc.push_back(fucPrint1);
	m_vecFunc.push_back(fucPrint2);
	m_vecFunc.push_back(fucPrint3);
	m_vecFunc.push_back(bind(&Base1::p1, &b1));
	m_vecFunc.push_back(bind(&Base1::p2, &b1));
	m_vecFunc.push_back(bind(&Base1::p3, &b1));
	m_vecFunc[0]();
	m_vecFunc[1]();
	m_vecFunc[2]();
	m_vecFunc[3]();
	m_vecFunc[4]();
	m_vecFunc[5]();
	cout << "Hello world!" << endl;
	return 0;
}