#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
#include<algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;

class Matrix
{
public:
    Matrix(int m,int n):han(m),lie(n) {
        x.resize(han,vector<int>(n,0));
    }
    vector<vector<int>> x;
    int han, lie;
    friend istream& operator>>(istream& in, Matrix& m);
    friend ostream& operator<<(ostream& ou, const Matrix& m);
    Matrix& operator*(Matrix& m) {
        if (lie==m.han)
        {
            static Matrix res(han,m.lie);
            for (int i = 0; i < res.han; i++)
            {
                for (int j = 0; j < res.lie; j++)
                {
                    int temp = 0;
                    for (int t = 0; t < lie; t++)
                    {
                        temp += x[i][t] * m.x[t][j];
                    }
                    res.x[i][j] = temp;
                }
            }
            return res;
        }
        else
        {
            cout << "can't multiply!" << endl;
            static Matrix res(0, 0);
            return res;
        }
    }
    void DiagonalOrder() {
        string res;
        for (int i = 0; i < han; i++)
        {
            int ii = i;
            int j = 0;
            string s ;
            while (ii >= 0 && ii < han && j >= 0 && j < lie)
            {
                s += to_string(x[ii][j]) + " ";
                ii -= 1;
                j += 1;
            }
            s.erase(s.length() - 1, 1);
            if (i % 2 != 0)
            {
                reverse(s.begin(), s.end());
            }
            s += " ";
            res += s;
        }
        for (int j = 1; j < lie; j++)
        {
            int jj = j;
            int i = han - 1;
            string s ;
            while (i >= 0 && i < han && jj >= 0 && jj < lie)
            {
                s += to_string(x[i][jj]) + " ";
                i -= 1;
                jj += 1;
            }
            s.erase(s.length() - 1, 1);
            if (j % 2 != 0)
            {
                reverse(s.begin(), s.end());
            }
            s += " ";
            res += s;
        }
       res.erase(res.length() - 1, 1);
       cout << res << endl;
    }
    void setZeros() {
        set<int> hangs;
        set<int> lies;
        for (int i = 0; i < han; i++)
        {
            for (int  j = 0; j < lie; j++)
            {
                if (x[i][j] == 0)
                {
                    hangs.insert(i);
                    lies.insert(j);
                }
            }
        }
        for (int i = 0; i < han; i++)
        {
            for (int j = 0; j < lie; j++)
            {
                if (hangs.find(i)!=hangs.end()||lies.find(j)!=lies.end())
                {
                    x[i][j] = 0;
                }
            }
        }
    }


};

istream& operator>>(istream& in, Matrix& m)
{
    for (int i = 0; i < m.han; i++)
    {
        for (int j = 0; j < m.lie; j++)
        {
            //cout << "aa" << i << j << endl;
            in >> m.x[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& ou, const Matrix& m)
{
    for (int i = 0; i < m.han; i++)
    {
        for (int j = 0; j < m.lie; j++)
        {
            ou << m.x[i][j];
            if (j==m.lie-1)
            {
                ou << endl;
            }
            else
            {
                ou << " ";
            }
        }
    }
    return ou;
}

int main() {
    int n, m;
    while (cin >> m >> n) {
        Matrix mat1(m, n);
        cin >> mat1;
        int x, y;
        cin >> x >> y;
        Matrix mat2(x, y);
        cin >> mat2;
        Matrix res = mat1 * mat2;
        cout << res;
        mat1.DiagonalOrder();
        mat1.setZeros();

        cout << mat1;

    }

    return 0;

}

//int main() {
//    int n, m;
//    while (cin >> m >> n) {
//        Matrix mat1(m, n);
//        cin >> mat1;
//        int x, y;
//        cin >> x >> y;
//        Matrix mat2(x, y);
//        cin >> mat2;
//        Matrix res = mat1 * mat2;
//        cout << res;
//
//    }
//
//    return 0;
//
//}