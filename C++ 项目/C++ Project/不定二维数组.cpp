#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {

        //�����ά����[n][n]
        int** p;
        int i, j;
        int sum=0;

        p = new int* [n];
        for (i = 0; i < n; i++) {
            p[i] = new int[n];
        }
        //��ά���鸳ֵ
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
        //���
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
        //�ͷ��ڴ�
        for (i = 0; i < n; i++) {
            delete[] p[i];
        }
        delete[] p;
        
    }
}