#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
    int a = 10;
    double b = 314159.26;
    cout << a << endl;//��ʮ������ʽ��� 
    cout << setbase(8);//�԰˽�����ʽ��� 
    cout << setiosflags(ios::showbase);//��ʾ����ָʾ�� 
    cout << a << endl;
    cout << setprecision(7);//���þ���Ϊ7λ 
    cout << b << endl;
    cout << setiosflags(ios::fixed);//�����Թ̶�С����ķ�ʽ��� 
    cout << setprecision(4);//����С�������4λ 
    cout << b << endl;
    //������ָ����ʽ�����ͬʱ��ĸ��д������롣 
    cout << setiosflags(ios::scientific | ios::uppercase | ios::left);
    cout << setw(20);
    //������ʾ���Ϊ20 
    cout << setfill('*');//�հ״��ԡ�*����� 
    cout << -b << endl;//�Ը�����ʽ�ļ��ɼ�
    //ȡ��ָ����ʽ��� 
    cout << resetiosflags(ios::scientific | ios::uppercase);
    cout << setfill(' ');//�հ״��ԡ������ 
    cout << setprecision(6);//����С�������6λ 
    cout << setw(20);//���Ϊ20 
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