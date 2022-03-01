//多文件结构
#include <iostream>
using namespace std;
#include "Examples_myAreas.h"
int main()
{

}

//函数的声明
double max(double, double);

//默认参数
double dist(double, double = 0);

//指针参数
void swap(int*, int*);
void swap(int* x, int* y)
{

}

//引用参数
void swap(int&, int&);
void swap(int& x, in& y)
{

}

//函数返回指针类型
int* maxPoint(int* x, int* y)
{

}

//函数返回引用类型
int& maxRef(int& x, int& y)
{

}

//函数指针
typedef double functionType(double, double);
functionType max, min;  //函数声明
double(*fp)(double, double); //函数指针
functionType* fp1, * fp2;  //函数指针
//定义函数指针类型pType
typedef double (*pType)(double, double);
typedef functionType* pType;
pType pf1, pf2;
pf1 = max;
pf2 = min;
//函数指针调用函数
x = fp(0.5, 0.3);

//内联函数
inline int isnumber(char);
int isnumber(char ch)
{

}

//宏定义
//用来替换正文中出现的标识符
#define PI 3.14159  //const
#define area(r) PI*r*r  //inline

//条件编译
#if 1  //常量表达式,可以是0或1
	//程序文本
#else
	//程序文本2
#endif

