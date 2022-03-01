#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double m, n, p, x;
	double a = 0, b = 0, c = 0;
	while (cin >> m >> n >> p)
	{
		for (int i = 0; i <= m; i++)
		{
			a = a + i;
		}
		for (long int i = 0; i <=n; i++)
		{
			b=b+i*i*i;
		}
		for (long int i = 0; i <= p; i++)
		{
			c = c + i * i * i * i * i;
		}
		x = (a + b) / c;
		cout << fixed << setprecision(4) << x << endl;
		a = 0; b = 0; c = 0;
	}
}


//cout << fixed << setprecision(4) << x << endl; 
//对应头文件：#include<iomanip>

//pow 函数用法示例：
//area = pow(4.0,2);
//要求至少第一个参数是 double 类型的,该函数返回的值始终是 double 类型数字
////对应头文件：#include<cmath>