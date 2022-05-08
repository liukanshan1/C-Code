#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
#include<algorithm>
#include <map>
#include <queue>
using namespace std;

class SStack
{
public:
    vector<int> x;
    void push(int num) {
        x.push_back(num);
        sort(x.begin(), x.end());
    }
    bool isEmpty() {
        return x.empty();
   }
    int top() {
        return x.back();
    }
    void pop() {
        x.pop_back();
    }

private:

};


int main() {

    SStack stack = SStack();

    int n;

    int num;

    while (cin >> n) {

        for (int i = 0; i < n; ++i) {

            cin >> num;

            stack.push(num);

        }

        while (!stack.isEmpty()) {

            cout << stack.top() << " ";

            stack.pop();

        }

        cout << endl;

    }

    return 0;

}