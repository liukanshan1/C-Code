#include<iostream>
using namespace std;
//µİ¹é¶ş·Ö¼ìË÷
int binarySearch(const int list[], int first, int last, int item)
{
    if (first > last)
    {
        return -1;
    }
    else
    {
        int middle = (first + last) / 2;
        if (item == list[middle])
        {
            return middle;
        }
        else if (item < list[middle])
        {
            return binarySearch(list, first, middle - 1, item);
        }
        else
        {
            return binarySearch(list, middle + 1, last, item);
        }
    }
}
int main()
{
    int test1[1] = { 1 };
    int test3[5] = { 1,3,6,9,11 };
    cout << binarySearch(test1, 0, 0, 1) << endl;
    cout << binarySearch(test1, 0, 0, 6) << endl;
    cout << binarySearch(test3, 0, 4, 11) << endl;
    cout << binarySearch(test3, 0, 4, 2) << endl;
}