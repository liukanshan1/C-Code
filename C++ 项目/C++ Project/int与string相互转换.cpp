//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    int a = 45688;
//    string s = to_string(a); //intתstring
//    int b = atoi(s.c_str()); 
//    //stringתint��������������Ҳ������Ӧ�ı�׼�⺯����
//    //���縡����atof(),long��atol()�ȵȡ�
//    cout << b;
//    s[0] = tolower(s[0]);//Сд
//    s[0] = toupper(s[0]);//Сд
//
//}

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a="000000000000000000000000000000000000000000000";
    //cin >> a;
    int b = stoi(a);
    double c = stod(a);
    long d = stol(a);
    float e = stof(a);
    cout << b << " " << c << " " << d << " " << e << endl;

}