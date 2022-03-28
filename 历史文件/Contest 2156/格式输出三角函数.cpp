#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double p_i = 3.14159265;

int main()
{
	int n;
	while (cin>>n)
	{
		for (int i = 1; i <= n; i++)
		{
			double temp = i * 2 * p_i / 360;
			cout << std::left << setw(3)
				<< i
				<< std::left << fixed << setprecision(5) << setw(10)
				<< sin(temp) 
				<< std::left << fixed << setprecision(5) << setw(10)
				<< cos(temp) 
				<< std::left << fixed << setprecision(5)
				<< tan(temp) 
				<< endl;
		}
	}
}