//���ļ��ṹ
#include <iostream>
using namespace std;
#include "Examples_myAreas.h"
int main()
{

}

//����������
double max(double, double);

//Ĭ�ϲ���
double dist(double, double = 0);

//ָ�����
void swap(int*, int*);
void swap(int* x, int* y)
{

}

//���ò���
void swap(int&, int&);
void swap(int& x, in& y)
{

}

//��������ָ������
int* maxPoint(int* x, int* y)
{

}

//����������������
int& maxRef(int& x, int& y)
{

}

//����ָ��
typedef double functionType(double, double);
functionType max, min;  //��������
double(*fp)(double, double); //����ָ��
functionType* fp1, * fp2;  //����ָ��
//���庯��ָ������pType
typedef double (*pType)(double, double);
typedef functionType* pType;
pType pf1, pf2;
pf1 = max;
pf2 = min;
//����ָ����ú���
x = fp(0.5, 0.3);

//��������
inline int isnumber(char);
int isnumber(char ch)
{

}

//�궨��
//�����滻�����г��ֵı�ʶ��
#define PI 3.14159  //const
#define area(r) PI*r*r  //inline

//��������
#if 1  //�������ʽ,������0��1
	//�����ı�
#else
	//�����ı�2
#endif

