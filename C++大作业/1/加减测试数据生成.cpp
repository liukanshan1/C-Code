#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int count = 1000;
	int a = -1000, b = 10000;
	srand((int)time(0));
	cout << "hhhhhhhhhhhhhhhhhhhh" << endl
		<< "+" << endl
		<< "1, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111" << endl
		<< "222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222" << endl
		<< "+" << endl
		<< " - 12, 345, 678, 901, 234, 567, 890, 123, 456, 789, 012, 345, 678, 901, 234, 567, 890" << endl
		<< "98, 765, 432, 198, 765, 432, 198, 765, 432, 198, 765, 432, 198, 765, 432, 198, 765" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "+" << endl;
		cout << (rand() % (b - a + 1)) + a << endl;
		cout << (rand() % (b - a + 1)) + a << endl;
	}
		
}