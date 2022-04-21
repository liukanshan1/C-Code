#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
#include<algorithm>
#include <map>
#include <queue>
using namespace std;

class Cart
{
public:
    friend istream& operator>>(istream& in, Cart& c);
    double caculate() {
        
        return ep * en + mp * mn + cp * cn;
    }
    double ep;
    double mp;
    double cp;
    double en;
    double mn;
    double cn;
};

class Minus:public Cart
{
public:
    double caculate() {
        double ori = ep * en + mp * mn + cp * cn;
        int temp = ep * en + mp * mn + cp * cn;
        int des = (temp / 200)*30 ;
        //cout <<" waa" << des << " " << ori;
        return ori - des;
    }
};

class DisCount:public Cart
{
public:
    double caculate() {
        return (ep * en + mp * mn + cp * cn)*0.9;
    }

private:

};



istream& operator>>(istream& in, Cart& c)
{
    in >> c.ep >> c.mp >> c.cp >> c.en >> c.mn >> c.cn;
    return in;
}

int main()

{

    int n;
    DisCount d;
    Cart* cart = &d;
    while (cin >> *cart)
    {
        double originPrice = cart->caculate();
        DisCount* discount = (DisCount*)cart;
        double res1 = discount->caculate();

        Minus* minus = (Minus*)cart;

        double res2 = minus->caculate();

        cout << originPrice << " ";
        double res = res1 < res2 ? res1 : res2;
        cout << res << endl;
    }




 

}