/* ѧ�� ���� �༶ */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

void move_by_ijkl(int &x,int &y,char ijkl,char m)
{
	if (m == '1')
	{
		if (ijkl == 'i' || ijkl == 'I')
		{
			y -= 1;
			if (y < 1 || y > 17)
			{
				y += 1;
			}
		}
		else if (ijkl == 'k' || ijkl == 'K')
		{
			y += 1;
			if (y < 1 || y > 17)
			{
				y -= 1;
			}
		}
		else if (ijkl == 'j' || ijkl == 'J')
		{
			x -= 1;
			if (x < 1 || x > 69)
			{
				x += 1;
			}
		}
		else if (ijkl == 'l' || ijkl == 'L')
		{
			x += 1;
			if (x < 1 || x > 69)
			{
				x -= 1;
			}
		}
	}
	else if (m=='2')
	{
		if (ijkl == 'i' || ijkl == 'I')
		{
			y -= 1;
			if (y < 1 )
			{
				y =17;
			}
			else if (y>17)
			{
				y = 1;
			}
		}
		else if (ijkl == 'k' || ijkl == 'K' )
		{
			y += 1;
			if (y < 1)
			{
				y = 17;
			}
			else if (y > 17)
			{
				y = 1;
			}
		}
		else if (ijkl == 'j' || ijkl == 'J')
		{
			x -= 1;
			if (x < 1 )
			{
				x = 69;
			}
			else if (x>69)
			{
				x = 1;
			}
		}
		else if (ijkl == 'l' || ijkl == 'L')
		{
			x += 1;
			if (x < 1)
			{
				x = 69;
			}
			else if (x > 69)
			{
				x = 1;
			}
		}
	}
	else if (m == '5')
	{
		if (ijkl == 'i' || ijkl == 'I')
		{
			y -= 1;
			if (y < 1 || y > 17)
			{
				y += 1;
			}
		}
		else if (ijkl == 'k' || ijkl == 'K' )
		{
			y += 1;
			if (y < 1 || y > 17)
			{
				y -= 1;
			}
		}
		else if (ijkl == 'j' || ijkl == 'J')
		{
			x -= 1;
			if (x < 1 || x > 69)
			{
				x += 1;
			}
		}
		else if (ijkl == 'l' || ijkl == 'L')
		{
			x += 1;
			if (x < 1 || x > 69)
			{
				x -= 1;
			}
		}
	}
	else if (m == '6')
	{
		if (ijkl == 'i' || ijkl == 'I')
		{
			y -= 1;
			if (y < 1)
			{
				y = 17;
			}
			else if (y > 17)
			{
				y = 1;
			}
		}
		else if (ijkl == 'k' || ijkl == 'K' )
		{
			y += 1;
			if (y < 1)
			{
				y = 17;
			}
			else if (y > 17)
			{
				y = 1;
			}
		}
		else if (ijkl == 'j' || ijkl == 'J')
		{
			x -= 1;
			if (x < 1)
			{
				x = 69;
			}
			else if (x > 69)
			{
				x = 1;
			}
		}
		else if (ijkl == 'l' || ijkl == 'L')
		{
			x += 1;
			if (x < 1)
			{
				x = 69;
			}
			else if (x > 69)
			{
				x = 1;
			}
		}
	}

}

void move_by_arrow(int& x, int& y, char arrow, char m)
{
	if (m == '3')
	{
		if (int(arrow) == 72)  //����
		{
			y -= 1;
			if (y < 1 || y > 17)
			{
				y += 1;
			}
		}
		else if (int(arrow) == 80)  //����
		{
			y += 1;
			if (y < 1 || y > 17)
			{
				y -= 1;
			}
		}
		else if (int(arrow) == 75)  //����
		{
			x -= 1;
			if (x < 1 || x > 69)
			{
				x += 1;
			}
		}
		else if (int(arrow) == 77)  //����
		{
			x += 1;
			if (x < 1 || x > 69)
			{
				x -= 1;
			}
		}
	}
	else if (m == '4')
	{
		if (int(arrow) == 72)
		{
			y -= 1;
			if (y < 1)
			{
				y = 17;
			}
			else if (y > 17)
			{
				y = 1;
			}
		}
		else if (int(arrow) == 80)
		{
			y += 1;
			if (y < 1)
			{
				y = 17;
			}
			else if (y > 17)
			{
				y = 1;
			}
		}
		else if (int(arrow) == 75)
		{
			x -= 1;
			if (x < 1)
			{
				x = 69;
			}
			else if (x > 69)
			{
				x = 1;
			}
		}
		else if (int(arrow) == 77)
		{
			x += 1;
			if (x < 1)
			{
				x = 69;
			}
			else if (x > 69)
			{
				x = 1;
			}
		}
	}
}

int menu()
{
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl
		<< "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl
		<< "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl
		<< "4.�ü�ͷ�������������ң��߽����" << endl
		<< "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ�������ͷ�������ƶ�)" << endl
		<< "6.��I��J��K��L��������������(��Сд���ɣ��߽���ƣ������ͷ�������ƶ�)" << endl
		<< "0.�˳�" << endl
		<< "[��ѡ��0 - 6]";
	char menu;
	menu=_getch();  //ͷ�ļ�#include <conio.h> ����Ҫ�س�����������
	return menu;
}


int main()
{
	while (true)
	{
		const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
		int x = 35, y = 9;
		char m;
		m = menu();

		srand((unsigned int)(time(0)));  //����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ���

		if (m == '1')
		{
			cls(hout);  //�˾�������ǵ���ϵͳ��cls��������
			init_border(hout);  //��ʾ��ʼ�ı߿����е�����ַ�
			gotoxy(hout, x, y);  //��굽���м�
			char ijkl;
			while (true)
			{
				ijkl = _getch();
				if (ijkl == 'q' || ijkl == 'Q')
				{
					break;
				}
				else if (int(ijkl) == 32)
				{
					cout << " ";
					gotoxy(hout, x, y);
				}
				else
				{
					move_by_ijkl(x, y, ijkl, m);
					gotoxy(hout, x, y);
				}
			}
		}
		else if (m == '2')
		{
			cls(hout);  //�˾�������ǵ���ϵͳ��cls��������
			init_border(hout);  //��ʾ��ʼ�ı߿����е�����ַ�
			gotoxy(hout, x, y);  //��굽���м�
			char ijkl;
			while (true)
			{
				ijkl = _getch();
				if (ijkl == 'q' || ijkl == 'Q')
				{
					break;
				}
				else if (int(ijkl) == 32)
				{
					cout << " ";
					gotoxy(hout, x, y);
				}
				else
				{
					move_by_ijkl(x, y, ijkl, m);
					gotoxy(hout, x, y);
				}
			}
		}
		else if (m == '3')
		{
			cls(hout);  //�˾�������ǵ���ϵͳ��cls��������
			init_border(hout);  //��ʾ��ʼ�ı߿����е�����ַ�
			gotoxy(hout, x, y);  //��굽���м�
			char arrow;
			while (true)
			{
				arrow = _getch();
				if (int(arrow) == -32)
				{
					arrow = _getch();
					move_by_arrow(x, y, arrow, m);
					gotoxy(hout, x, y);
				}
				else if (arrow == 'q' || arrow == 'Q')
				{
					break;
				}
				else if (int(arrow) == 32)
				{
					cout << " ";
					gotoxy(hout, x, y);
				}
			}
		}
		else if (m == '4')
		{
			cls(hout);  //�˾�������ǵ���ϵͳ��cls��������
			init_border(hout);  //��ʾ��ʼ�ı߿����е�����ַ�
			gotoxy(hout, x, y);  //��굽���м�
			char arrow;
			while (true)
			{
				arrow = _getch();
				if (int(arrow) == -32)
				{
					arrow = _getch();
					move_by_arrow(x, y, arrow, m);
					gotoxy(hout, x, y);
				}
				else if (arrow == 'q' || arrow == 'Q')
				{
					break;
				}
				else if (int(arrow) == 32)
				{
					cout << " ";
					gotoxy(hout, x, y);
				}
			}
		}
		else if (m == '5')
		{
			cls(hout);  //�˾�������ǵ���ϵͳ��cls��������
			init_border(hout);  //��ʾ��ʼ�ı߿����е�����ַ�
			gotoxy(hout, x, y);  //��굽���м�
			char ijkl, ijkl2;
			while (true)
			{
				ijkl = _getch();  //�������ͷʱ��һ��getch�õ���-32���ڶ����õ���75
				if (int(ijkl) == -32)
				{
					ijkl2 = _getch();
				}
				else if (int(ijkl) == 32)
				{
					cout << " ";
					gotoxy(hout, x, y);
				}
				else
				{
					if (ijkl == 'q' || ijkl == 'Q')
					{
						break;
					}
					else
					{
						move_by_ijkl(x, y, ijkl, m);
						gotoxy(hout, x, y);
					}
				}
			}
		}
		else if (m == '6')
		{
			cls(hout);  //�˾�������ǵ���ϵͳ��cls��������
			init_border(hout);  //��ʾ��ʼ�ı߿����е�����ַ�
			gotoxy(hout, x, y);  //��굽���м�
			char ijkl, ijkl2;
			while (true)
			{
				ijkl = _getch();  //�������ͷʱ��һ��getch�õ���-32���ڶ����õ���75
				if (int(ijkl) == -32)
				{
					ijkl2 = _getch();
				}
				else if (int(ijkl) == 32)
				{
					cout << " ";
					gotoxy(hout, x, y);
				}
				else
				{
					if (ijkl == 'q' || ijkl == 'Q')
					{
						break;
					}
					else
					{
						move_by_ijkl(x, y, ijkl, m);
						gotoxy(hout, x, y);
					}
				}
			}
		}
		else if (m == '0')
		{
			return 0;
		}

		gotoxy(hout, 0, 23);
		cout << "��Ϸ���������س����˳�.";
		char ent;
		while (true)
		{
			ent = _getch();
			if (int(ent) == 13)
			{
				cls(hout);
				break;
			}
		}
		continue;	
	}
}
