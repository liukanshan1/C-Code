#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b )
	{
		//加密
		for (int i = 0; i < 6; i++)
		{
			
			a[i] = char((7 + int(a[i])-48) % 10+48);	//0的acsii值为48。这里把字符型转数值运算后再转回字符型。
		}
		reverse(a.begin(), a.end());
		//删除首位的0
		if (int(a[0]) == 48)
		{
			for (int n = 1; n < 6; n++)
			{
				cout << a[n];
			}
			cout << " ";
		}
		else
		{
			cout << a << " ";
		}
		//解密
		//判断长度是否为6
		if (b.length()==5)
		{
			string temp;
			temp = "aaaaaa";
			for (int z = 1; z < 6; z++)
			{
				temp[z] = b[z-1];
			}
			temp[0] = char(48);
			b = temp;
		}
		for (int m = 0; m < 6; m++)
		{
			if ((int(b[m])-48)>=7&& (int(b[m]) - 48) <=9)
			{
				b[m] = char(int(b[m]) - 7);
			}
			else
			{
				b[m] = char(int(b[m]) + 3);
			}
		}
		reverse(b.begin(), b.end());
		cout << b << endl;


		
		
	}
	return 0;
}


