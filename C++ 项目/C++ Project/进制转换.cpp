#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	int x;
	while (cin>>x)
	{
		cout << " " << bitset<8>(x) << " ";      //<8>����ʾ����8λ���
		printf("%02x\n", x);    //��ʮ�����Ƹ�ʽ���������5λ��λ����
	}
	
}



//printf("%05o\n", 35);    //���˽��Ƹ�ʽ���������5λ��λ����
//printf("%03d\n", 35);    //��ʮ���Ƹ�ʽ���������3λ��λ����
//printf("%05x\n", 35);    //��ʮ�����Ƹ�ʽ���������5λ��λ����


//cout << "35��8����:" << std::oct << 35 << endl;
//cout << "35��10����" << std::dec << 35 << endl;
//cout << "35��16����:" << std::hex << 35 << endl;
//cout << "35��2����: " << bitset<8>(35) << endl;      //<8>����ʾ����8λ���
