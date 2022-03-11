#include <string>
#include <iostream>
#include <cstring>
using namespace std;

string s, f, r;
int s_count = 0;

void f_r_str(string &s, string f, string r)
{
    s_count = 0;
    int n = -1;
    do
    {
        n = s.find(f);  //查找字符串，找不到返回-1
        if (n != -1)
        {
            //方法一
            //s.erase(n, f.length()); //删除n开始的f.length()个元素
            //s.insert(n, r); //插入替换的字符串
            //方法二
            s.replace(n, f.length(), r); //从n开始的f.length()个元素替换为r
            s_count++;
        }
    } while (n != -1);
}

int main()
{
 
    while (cin >> s >> f >> r)
    {
        f_r_str(s, f, r);
        cout << s_count << endl;
        cout << s << endl;
    }

    return 0;

}
//倒序查找字符串
{
    string s;
    getline(cin, s);
    int pre = s.length(), now;
    while ((now = s.rfind(' ', s.length() - 1)) != string::npos) //注意 s.length() - 1
    {
        cout << s.substr(now + 1, pre - now - 1) << " ";
        s.erase(now, 1);
        pre = now;
    }
    cout << s.substr(0, pre) << endl;
}