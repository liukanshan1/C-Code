#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
#include<algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

class Point
{
public:
	Point():x(0),y(0){}
    Point(double a, double b):x(a),y(b){}
    double r() {
        return sqrt(x * x + y * y);
    }
    double distance(const Point& p) {
        double a = x - p.x;
       double b = y - p.y;
        return sqrt(a * a + b * b);
    }
    Point relative(const Point& p) {
        return Point(x - p.x, y - p.y);
    }
    bool is_above_left(const Point& p)
    {
        return (x < p.x) && (y > p.y);
    }
    double x, y;

private:

};







int main()
{
    double x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;
    Point p1, p2(x2, y2), p3(x3, y3);
    cout << fixed << setprecision(2) << p2.r() << endl;
    cout << "The distance between p3 and p2 is " << fixed << setprecision(2) << p3.distance(p2) << endl;
    Point p4 = p2.relative(p3);
    cout << fixed << setprecision(2) << "p4:(" << p4.x << "," << p4.y << ")" << endl;
    cout << "Is p2 is above left of p3?:" << p2.is_above_left(p3) << endl;
}