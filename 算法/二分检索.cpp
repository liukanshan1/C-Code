#include<iostream>
using namespace std;
//二分检索 在有序列表中查找项目
int binarySearch(int list[], int length, int item) //返回下标
{
    int first = 0, last = length - 1;
    while (first <= last)
    {
        int middle = (first + last) / 2;
        if (item == list[middle])
        {
            return middle;
        }
        else if (item < list[middle]) //从小到大排序的数组适用
        {
            last = middle - 1;
        }
        else if (item > list[middle]) //从小到大排序的数组适用
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