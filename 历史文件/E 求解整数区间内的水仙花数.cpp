#include <iostream>
using namespace std;
int main()
{
    int a, b, c, m, n;
    while (cin >> m >> n)
    {
        bool flag = 1;
        for (int i = m; i <= n; i++)
        {
            a = i / 100;
            b = (i % 100) / 10;
            c = i % 10;
            if (i == a * a * a + b * b * b + c * c * c)
            {
                flag = 0;
                cout << i << " ";
            }
        }
        if (flag)
        {
            cout << "none" << endl;
        }
        else
        {
            cout << endl;
        }
    }

}