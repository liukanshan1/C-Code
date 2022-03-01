# 期中考试F题使用递归的方法

```c++
#include <iostream>
using namespace std;

double money = 0; //全局变量money，因为在fuli函数中调用了money，所以写在了全局变量

void fuli(double a,double b,int c)
{
	static double s = 0;  //初始化变量，static 修饰的静态局部变量只执行初始化一次，而且延长了局部变量的生命周期，直到程序运行结束以后才释放。
	static int i = 1;  //这个用来计数。
	if (i <= c)  //判断是否跳出递归
	{
		s = (s + a) * (1 + b); //由题目得出公式
		i++;  //次数加1
		fuli(a, b, c);  //递归调用函数，递归，就是在运行的过程中调用自己，
	}
	else
	{
		money = s;  //结果传递给money
		s = 0;  //因为有while循环，存在多种数据，为了下一次正确计算，将函数用到的变量重新赋值。
		i = 1;
	}
	
}

int main()
{
	double a = 0, b = 0;
	int c = 0;
	while (cin >> a >> b >> c)
	{
		b = b / 100.0;   //转换百分数
		b = b / 12.0;   //平均到月份
		fuli(a, b, c);  //调用fuli函数
		printf("%.2f\n", money);  //使用printf保留两位小数(%.2是两位小数，f是浮点数）
	}
}

//cout << fixed << setprecision(4) << x << endl; 
//对应头文件：#include<iomanip>
```

