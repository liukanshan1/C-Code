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
        n = s.find(f);  //�����ַ������Ҳ�������-1
        if (n != -1)
        {
            //����һ
            //s.erase(n, f.length()); //ɾ��n��ʼ��f.length()��Ԫ��
            //s.insert(n, r); //�����滻���ַ���
            //������
            s.replace(n, f.length(), r); //��n��ʼ��f.length()��Ԫ���滻Ϊr
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