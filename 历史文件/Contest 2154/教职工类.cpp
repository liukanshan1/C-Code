#include<iostream>
using namespace std;

class Employee
{
public:
	Employee();
	virtual ~Employee();
	int basicSalary = 2000;
	string name;
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
	string name[3];
	int level;
	int classes;
	int workSalary;
	int workDay;
	while (cin >> name[0] >> level>>classes)
	{
		cin >> name[1] >> workSalary
			>> name[2] >> workDay;
		Employee* p1 = new Teacher(level, classes, name[0]);
		Employee* p2=new Manager(workSalary,name[1]);
		Employee*p3=new LabAssistant(workDay,name[2]);
		cout << p1->name << " " << p1->salary() << endl
			<< p2->name << " " << p2->salary() << endl
			<< p3->name << " " << p3->salary() << endl;
	}
	

	
}