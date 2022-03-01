#include<iostream>
using namespace std;
//插入排序
void insertionSort(int list[], int length)
{
    int current = 1;
    while (current < length)
    {
        int index = current;
        while (index > 0)
        {
            if (list[index] < list[index - 1]) //从小到大排序
            {
                int temp = list[index];
                list[index] = list[index - 1];
                list[index - 1] = temp;
                index--;
            }
            else
            {
                break;
            }
        }
        current++;
    }
}
int main()
{
    int test1[1] = { 1 };
    int test2[2] = { 4,1 };
    int test3[5] = { 1,5,2,9,7 };

    insertionSort(test1, 1);
    insertionSort(test2, 2);
    insertionSort(test3, 5);

    for (int i = 0; i < 1; i++)
    {
        cout << test1[i];
    }
    cout << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << test2[i];
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << test3[i];
    }
}