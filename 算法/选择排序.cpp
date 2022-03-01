#include<iostream>
using namespace std;
//—°‘Ò≈≈–Ú
void selectionSort(int list[], int length)
{
    int firstUnsorted = 0;
    while (firstUnsorted < length - 1)
    {
        int indexOfSmallest = firstUnsorted;
        for (int i = firstUnsorted + 1; i <= length - 1; i++)
        {
            if (list[i] < list[indexOfSmallest])
            {
                indexOfSmallest = i;
            }
        }
        if (indexOfSmallest != firstUnsorted)
        {
            int temp = list[firstUnsorted];
            list[firstUnsorted] = list[indexOfSmallest];
            list[indexOfSmallest] = temp;
        }
        firstUnsorted++;
    }
}
int main()
{
    int test1[1] = { 1 };
    int test2[2] = { 4,1 };
    int test3[5] = { 1,2,2,9,7 };

    selectionSort(test1, 1);
    selectionSort(test2, 2);
    selectionSort(test3, 5);

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