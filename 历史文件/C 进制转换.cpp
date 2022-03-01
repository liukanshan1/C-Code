#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	int x;
	while (cin >> x)
	{
        //二进制
		cout << "binary:" ;
        int  i, j = 0;
        int a[1000];
        i = x;
        while (i)
        {
            a[j] = i % 2;
            i /= 2;
            j++;
        }
        for (i = j - 1; i >= 0; i--)
        {
            cout << a[i];
        }

		cout << ", oct:" << std::oct << x ;              //8进制
		cout << ", hex:" << std::hex << x << endl;       //16进制
	}

}



//printf("%05o\n", 35);    //按八进制格式输出，保留5位高位补零
//printf("%03d\n", 35);    //按十进制格式输出，保留3位高位补零
//printf("%05x\n", 35);    //按十六进制格式输出，保留5位高位补零


//cout << "35的8进制:" << std::oct << 35 << endl;
//cout << "35的10进制" << std::dec << 35 << endl;
//cout << "35的16进制:" << std::hex << 35 << endl;
//cout << "35的2进制: " << bitset<8>(35) << endl;      //<8>：表示保留8位输出