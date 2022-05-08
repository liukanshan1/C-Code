#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
#include<algorithm>
#include <map>
#include <queue>
using namespace std;

class Ternary
{
public:
	Ternary(){}
	Ternary(int num) {
        while (num)
        {
            x.push_back(num % 3);
            num /= 3;          
        }
	}
	void display() {
		reverse(x.begin(), x.end());
		for (int  i : x )
		{
			cout << i;
		}
		cout << endl;
		reverse(x.begin(), x.end());
	}
    vector<int> x;
	int operator[](int i) {
		if (i<x.size())
		{
			return x[i];
		}
		return -1;
	}
	Ternary operator+ (Ternary t) {
		Ternary temp;
		vector<int> a = this->x, b = t.x;
		int ss = 0;
		while (!a.empty()&&!b.empty())
		{
			ss += a[0] + b[0];
			reverse(a.begin(), a.end());
			a.pop_back();
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			b.pop_back();
			reverse(b.begin(), b.end());
			temp.x.push_back(ss%3);
			ss /= 3;			
		}
		if (!a.empty() || !b.empty())
		{
			vector<int> c;
			c = a.empty() ? b : a;
			while (!c.empty())
			{
				ss += c[0];
				reverse(c.begin(), c.end());
				c.pop_back();
				reverse(c.begin(), c.end());
				temp.x.push_back(ss % 3);
				ss /= 3;
			}
		}
		if (ss!=0)
		{
			temp.x.push_back(ss);
		}
		return temp;
	}
private:

};
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	Ternary t1(num1), t2(num2);
	cout << t1[0] << " " << t2[0] << endl;
	t1.display();
	t2.display();
	Ternary t3 = t1 + t2;
	t3.display();
	t1.display();
}
