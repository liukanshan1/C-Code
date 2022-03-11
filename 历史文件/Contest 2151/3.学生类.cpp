#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	static int total;
	static int count;
	static int sum();
	static void average();

	int score;
	void scoretotalcount(int s);
private:

};

int Student::total=0;
int Student::count=0;//类外初始化

void Student::scoretotalcount(int s)
{
	cout << total;
}
int Student::sum()
{
	return total;
}
void Student::average()
{
	cout << (int)total / count;
}
int main()
{
	Student s[5];
	while (cin>> s[0].score)
	{
		Student::total += s[0].score;
		Student::count++;
		for (int i = 1; i < 5; i++)
		{
			cin >> s[i].score;
			Student::total +=s[i].score;
			Student::count++;
		}

		cout<<Student::sum();
		cout << " ";
		Student::average();
	}
	

}