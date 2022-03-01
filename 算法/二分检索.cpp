#include<iostream>
using namespace std;
//���ּ��� �������б��в�����Ŀ
int binarySearch(int list[], int length, int item) //�����±�
{
    int first = 0, last = length - 1;
    while (first <= last)
    {
        int middle = (first + last) / 2;
        if (item == list[middle])
        {
            return middle;
        }
        else if (item < list[middle]) //��С�����������������
        {
            last = middle - 1;
        }
        else if (item > list[middle]) //��С�����������������
        {
            first = middle + 1;
        }
    }
    return -1;
}
int main()
{
    int test1[1] = { 1 };
    int test3[5] = { 1,3,6,9,11 };
    cout << binarySearch(test1, 1, 1) << endl;
    cout << binarySearch(test1, 1, 6) << endl;
    cout << binarySearch(test3, 5, 6) << endl;
    cout << binarySearch(test3, 5, 2) << endl;
    
}