#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
    int a = 10;
    double b = 314159.26;
    cout << a << endl;//以十进制形式输出 
    cout << setbase(8);//以八进制形式输出 
    cout << setiosflags(ios::showbase);//显示进制指示符 
    cout << a << endl;
    cout << setprecision(7);//设置精度为7位 
    cout << b << endl;
    cout << setiosflags(ios::fixed);//设置以固定小数点的方式输出 
    cout << setprecision(4);//设置小数点后保留4位 
    cout << b << endl;
    //设置以指数形式输出，同时字母大写且左对齐。 
    cout << setiosflags(ios::scientific | ios::uppercase | ios::left);
    cout << setw(20);
    //设置显示域宽为20 
    cout << setfill('*');//空白处以’*‘填充 
    cout << -b << endl;//以负数方式四级成绩
    //取消指数形式输出 
    cout << resetiosflags(ios::scientific | ios::uppercase);
    cout << setfill(' ');//空白处以’‘填充 
    cout << setprecision(6);//设置小数点后保留6位 
    cout << setw(20);//宽度为20 
    cout << b << endl;
    return 0;
}
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double p_i = 3.14159265;

int main()
{
    int n;
    while (cin >> n)
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