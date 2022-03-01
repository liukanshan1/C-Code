#include<iostream>
using namespace std;
void main()
{
    int n, i, j = 0;
    int a[1000];
    cin >> n;
    i = n;
    while (i)
    {
        a[j] = i % 2;
        i /= 2;
        j++;

    }
    for (i = j - 1; i >= 0; i--)
        cout << a[i];

}