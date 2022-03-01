/* ѧ�� �༶ ���� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */

/***************************************************************************
	 �������ƣ�print_space
	 ��    �ܣ���ӡÿ��ǰ��Ŀո�
 ***************************************************************************/
void print_space(int y, int char_count,bool flag)
{
	static int space_count = 0;
	if (flag)
	{
		if (space_count <= char_count - y)
		{
			cout << " ";
			space_count++;
			print_space(y, char_count, flag);
		}
		else
		{
			space_count = 0;
		}
	}
	else
	{
		if (space_count <= y- char_count-2)
		{
			cout << " ";
			space_count++;
			print_space(y, char_count, flag);
		}
		else
		{
			space_count = 0;
		}
	}
}

/***************************************************************************
	 �������ƣ�print_content
	 ��    �ܣ���ӡÿ�е����ݺͻس�
 ***************************************************************************/
void print_content(int y, char start_ch, char end_ch, bool flag)
{
	static int x = 1;
	if (flag)
	{
		if (x<=2*y-1)
		{
			if ((int(start_ch) + y - x)>=65)
			{
				cout << char(int(start_ch) + y - x);
				x++;
				print_content(y, start_ch, end_ch, flag);
			}
			else
			{
				cout << char(int(start_ch) + x - y);
				x++;
				print_content(y, start_ch, end_ch, flag);
			}
		}
		else
		{
			cout << endl;
			x = 1;
		}
	}
	else
	{
		int _y = 2 * (int(end_ch) - int(start_ch) + 1) - y;
		if (x <= 2 * _y - 1)
		{
			if ((int(start_ch) + _y - x) >= 65)
			{
				cout << char(int(start_ch) + _y - x);
				x++;
				print_content(y, start_ch, end_ch, flag);
			}
			else
			{
				cout << char(int(start_ch) + x - _y);
				x++;
				print_content(y, start_ch, end_ch, flag);
			}
		}
		else
		{
			cout << endl;
			x = 1;
		}
	}
}

/***************************************************************************
	 �������ƣ�print_row
	 ��    �ܣ����ÿ�еĴ�ӡѭ��
 ***************************************************************************/
void print_row(int y, int char_count, char start_ch, char end_ch)
{
	static bool flag = true;
	if (y <= char_count * 2+1)
	{
		print_space(y, char_count, flag);
		print_content(y, start_ch, end_ch, flag);
		y++;
		if (y == char_count+2)
		{
			flag = false;
		}
		print_row(y, char_count, start_ch, end_ch);
	}
}

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ����
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void print_diamond(char start_ch, char end_ch)
{
	static int y = 1;
	static int char_count = int(end_ch) - int(start_ch);
	print_row(y, char_count, start_ch, end_ch);
}

/***************************************************************************
	 �������ƣ�print_equals
	 ��    �ܣ���ӡһ�еȺţ���������������=��
 ***************************************************************************/
char print_equals(char end_ch)
{
	static int count = 0;
	if (count<(int(end_ch) - 65)*2)
	{
		count++;
		cout << "=";
		print_equals(end_ch);
	}
	else
	{
		count = 0;
		return '=';
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main����������...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();

	/* ����(�м�ΪA) */
	cout << print_equals(end_ch) << endl; /* ��������������=(��������ѭ��) */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << print_equals(end_ch) << endl; /* ��������������=(��������ѭ��) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}
