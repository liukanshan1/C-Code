//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    int a = 45688;
//    string s = to_string(a); //int转string
//    int b = atoi(s.c_str()); 
//    //string转int，对于其他类型也都有相应的标准库函数，
//    //比如浮点型atof(),long型atol()等等。
//    cout << b;
//    s[0] = tolower(s[0]);//小写
//    s[0] = toupper(s[0]);//小写
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