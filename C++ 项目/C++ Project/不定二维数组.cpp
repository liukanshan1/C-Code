#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {

        //定义二维数组[n][n]
        int** p;
        int i, j;
        int sum=0;

        p = new int* [n];
        for (i = 0; i < n; i++) {
            p[i] = new int[n];
        }
        //二维数组赋值
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n; j++) 
            {
                if (j>=i)
                {
                    p[i][j] = 1;
                }
                else
                {
                    p[i][j] = i-j+1;
                    sum = sum + p[i][j];
                }
                
            }
        }
        //输出
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
            {
                if (j==n-1)
                {
                    cout <<p[i][j] << endl;
                }
                else
                {
                    cout << p[i][j] << " ";
                }
                
            }
        }
        cout << sum << endl;      
        //释放内存
        for (i = 0; i < n; i++) {
            delete[] p[i];
        }
        delete[] p;
        
    }
}