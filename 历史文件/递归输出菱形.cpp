/* 学号 班级 姓名 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
   ----------------------------------------------------------------------------------- */

/***************************************************************************
	 函数名称：print_space
	 功    能：打印每行前面的空格
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
	 函数名称：print_content
	 功    能：打印每行的内容和回车
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
	 函数名称：print_row
	 功    能：完成每行的打印循环
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
	 函数名称：
	 功    能：打印菱形
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
void print_diamond(char start_ch, char end_ch)
{
	static int y = 1;
	static int char_count = int(end_ch) - int(start_ch);
	print_row(y, char_count, start_ch, end_ch);
}

/***************************************************************************
	 函数名称：print_equals
	 功    能：打印一行等号，按菱形最大宽度输出=。
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中两处...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();

	/* 菱形(中间为A) */
	cout << print_equals(end_ch) << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << print_equals(end_ch) << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}
