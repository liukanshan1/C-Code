#include <iostream>
using namespace std;
int main()
{
	//while������Ϊtrue��ʱ��ojϵͳ�ᱨ��������ޣ����������ֶ�������10�����ݣ�ͨ��forѭ������ɶ��Ի���ߡ�
	int a[10][2];
	while (cin >> a[0][0] >> a[1][0] >> a[2][0] >> a[3][0] >> a[4][0] >> a[5][0] >> a[6][0] >> a[7][0] >> a[8][0] >> a[9][0])
	{
		for (int i = 0; i < 10; i++)
		{
			a[i][1] = i;
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++)
			{
				if (a[i][0] < a[j][0])
				{
					int temp1 = a[i][0];
					a[i][0] = a[j][0];
					a[j][0] = temp1;
					int temp2 = a[i][1];
					a[i][1] = a[j][1];
					a[j][1] = temp2;
				}
			}
		}
	
		for (int m = 0; m < 10; m++)
		{
			cout << a[m][0]<<" "<<a[m][1]<<endl;
		}
				
	}
	
}