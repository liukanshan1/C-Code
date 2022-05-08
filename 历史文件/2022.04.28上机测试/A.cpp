#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class Vehicle
{
public:

    virtual void display() = 0;
private:

};

class Car: public Vehicle
{
public:
    int pas;
    int wei;
    Car(int num,int kg):pas(num),wei(kg) {}
    void display()
    {
        cout << pas * 8 + wei * 2 << endl;
    }
private:

};

class Truck :public Vehicle
{
public:
    int wei;
    Truck(int kg):wei(kg){}
    void display()
    {
        cout << wei * 5<< endl;
    }

private:

};

class Bus :public Vehicle
{
public:
    int pas;
    Bus(int num):pas(num){}
    void display()
    {
        cout << pas * 3<< endl;
    }

private:

};




int main()

{

    Vehicle* pd[10];

    int t, num, i = 0;

    double kg;

    cin >> t;

    while (t) {

        if (t == 1) {

            cin >> num >> kg;

            pd[i] = new Car(num, kg);

        }
        else if (t == 2) {

            cin >> kg;

            pd[i] = new Truck(kg);

        }
        else if (t == 3) {

            cin >> num;

            pd[i] = new Bus(num);

        }

        pd[i]->display();

        i++;

        cin >> t;

    }

    delete* pd;

    return 0;

}

