#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
#include<algorithm>
#include <map>
#include <queue>
using namespace std;

template<typename T>
class MyVector
{
public:
    vector<T> ss;
    void push_back(T t) {
        ss.push_back(t);
    }
    T pop_back() {
        T temp = ss.back();
        ss.pop_back();
        return temp;
    }
    bool empty() {
        return ss.empty();
    }
private:

};



int main()

{

    MyVector<string> ar;

    int num;

    string temp;

    cin >> num;

    for (int i = 0; i < num; i++) {

        cin >> temp;

        ar.push_back(temp);

    }

    temp = ar.pop_back();

    cout << temp;

    while (!ar.empty()) {

        temp = ar.pop_back();

        cout << " " << temp;

    }

    cout << endl;

    return 0;

}