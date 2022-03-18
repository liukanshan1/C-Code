#include<iostream>
#include<string>
using namespace std;

class Employee
{
public:
	Employee(int b=2000)
	{
		basicSalary = b;
	}
	int number;
	string name;
	int basicSalary;
};
class Salesman :public Employee
{
public:
	Salesman(double c = 5 / 1000.0)
	{
		commrate = c;
	}
	int sales;
	static double commrate;
};
class Salesmanager :public Salesman
{
public:
	Salesmanager(int j = 3000)
	{
		jobSalary = j;
	}
	int jobSalary;
};
double Salesman::commrate;


int main()
{
	Employee e;
	Salesman man;
	Salesmanager manager;
	while (cin>>e.number)
	{
		cin >> e.name 
			>> man.number >> man.name >> man.sales
			>> manager.number >> manager.name >> manager.sales;
		cout << e.name << " " << e.number << " " << e.basicSalary << endl
			<< man.name << " " << man.number << " " << man.basicSalary + man.sales * man.commrate << endl
			<< manager.name << " " << manager.number << " " << manager.basicSalary + manager.jobSalary + manager.sales * manager.commrate << endl;
	}
}
