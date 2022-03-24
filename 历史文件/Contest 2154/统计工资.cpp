#include<iostream>
using namespace std;

class Employee
{
public:
	Employee();
	virtual ~Employee();
	int basicSalary = 2000;
	string name;
	Employee* next = nullptr;
	virtual int salary() = 0;
private:

};

Employee::Employee()
{
}

Employee::~Employee()
{
}

class Teacher:public Employee
{
public:
	Teacher(){};
	Teacher(int l, int c,string n);
	~Teacher();
	int level;
	int classes;
	int salary()
	{
		int temp;
		switch (level)
		{
		case 1:
			temp = 50 * classes;
			break;
		case 2:
			temp = 30 * classes;
			break;
		case 3:
			temp = 20 * classes;
			break;
		default:
			break;
		}
		return basicSalary + temp;
	}
private:

};

Teacher::Teacher(int l, int c,string n)
{
	name = n;
	level = l;
	classes = c;
}

Teacher::~Teacher()
{
}

class Manager :public Employee
{
public:
	Manager(int w,string n);
	~Manager();
	int workSalary;
	int salary()
	{
		return workSalary + basicSalary;
	}
private:

};

Manager::Manager(int w,string n)
{
	name = n;
	workSalary = w;
}

Manager::~Manager()
{
}

class LabAssistant :public Employee
{
public:
	LabAssistant(int w,string n);
	~LabAssistant();
	int workDay;
	int salary()
	{
		return basicSalary + 20 * workDay;
	}
private:

};

LabAssistant::LabAssistant(int w,string n)
{
	name = n;
	workDay = w;
}

LabAssistant::~LabAssistant()
{
}

int main()
{

	string name;
	int level;
	int classes;
	while (cin >> name >> level >> classes)
	{
		Employee* head = new Teacher;
		Employee* p = head;
		p->next = new Teacher(level, classes, name);
		p = p->next;
		for (int i = 0; i < 3; i++)
		{
			cin >> name >> level >> classes;
			p->next = new Teacher(level, classes, name);
			p = p->next;
		}
		p = head->next;
		int sum = 0, average, max = p->salary(), min = p->salary();
		while (p != nullptr)
		{
			sum += p->salary();
			if (p->salary() > max)
			{
				max = p->salary();
			}
			if (p->salary() < min)
			{
				min = p->salary();
			}
			p = p->next;
		}
		average = sum / 4;
		cout << sum << endl
			<< average << endl
			<< max << endl
			<< min << endl;
	}
	
}