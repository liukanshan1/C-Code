#include <iostream>
#include <string>
using namespace std;

struct Students
{
	string name[10];
	int score[10];
};


int main()
{
	Students stu;	
	while (cin>>stu.name[0]>>stu.score[0])
	{
		for (int i = 1; i < 10; i++)
		{
			cin >> stu.name[i] >> stu.score[i];
		}
		int max = 0;
		string good_stu;
		for (int i = 1; i < 10; i++)
		{
			if (stu.score[i]>max)
			{
				max = stu.score[i];
				good_stu = stu.name[i];
			}
		}
		cout << good_stu << endl;
	}
}