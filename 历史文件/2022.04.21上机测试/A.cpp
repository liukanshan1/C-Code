#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pointer
{
public:
    int x;
    int y;

private:

};

class Circle :public Pointer
{
public:
    int r;
    double area() {
        return 3.14 * r * r;
    }
    double perimeter()
    {
        return 3.14 * r * 2;
    }

private:

};

class Cylinder :public Circle
{
public:
	Cylinder(int xx,int yy, int rr,int hh ){
        x = xx;
        y = yy;
        r = rr;
        h = hh;
    };
    int h;
    void setHeight(int hei) {
        h = hei;
    }
    void setRadius(int rr) {
        r = rr;
    }
    void setPoint(int xx, int yy) {
        x = xx;
        y = yy;
    }
    double volume() {
        return Circle::area() * h;
    }
    double area()
    {
        return Circle::perimeter() * (r + h);
    }
    friend ostream& operator<<(ostream& out, Cylinder c);
private:

};

ostream& operator<<(ostream& out, Cylinder c) {
    out << c.area() << " " << c.volume() << endl;
    return out;
}



int main()

{

    int x, y, r, h;

    cin >> x >> y >> r >> h;

    Cylinder cy1(x, y, r, h);

    cout << cy1.area() << " " << cy1.volume() << endl;



    cin >> x >> y >> r >> h;

    cy1.setHeight(h);

    cy1.setRadius(r);

    cy1.setPoint(x, y);

    cout << cy1;

    return 0;

}