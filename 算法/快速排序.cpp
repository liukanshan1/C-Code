#include<iostream>
using namespace std;
//¿ìËÙÅÅĞò
void quickSort(int list[], int first, int last)
{
    if (first < last)
    {
        int splitVal = list[first];
        int left = first + 1;
        int right = last;
        while (left <= right)
        {
            while (list[left] <= splitVal && left <= right)
            {
                left++;
            }
            while (list[right] >= splitVal && left <= right)
            {
                right--;
            }
            if (left < right)
            {
                int temp = list[right];
                list[right] = list[left];
                list[left] = temp;
            }
        }
        int splitPoint = right;
        int temp = list[first];
        list[first] = list[splitPoint];
        list[splitPoint] = temp;
        quickSort(list, first, splitPoint - 1);
        quickSort(list, splitPoint + 1, last);
    }
}
int main()
{
    int test1[1] = { 1 };
    int test2[2] = { 4,1 };
    int test3[5] = { 1,2,2,9,7 };

    quickSort(test1, 0, 0);
    quickSort(test2, 0, 1);
    quickSort(test3, 0, 4);

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

