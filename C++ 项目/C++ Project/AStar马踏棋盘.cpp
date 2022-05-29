#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class dot {
public:
    dot() {}
    dot(int m, int n) :x(m), y(n) {}
    bool operator == (const dot& d) {
        return d.x == x && d.y == y;
    }
    int x, y;
};
struct compare {
    bool operator() (pair<int, dot> d1, pair<int, dot> d2) {
        return d1.first > d2.first;
    }
};

int row, col;
dot start;
dot target;
dot moves[8] = { dot(1,2),
               dot(1,-2),
               dot(-1,2),
               dot(-1,-2),
               dot(2,1),
               dot(2,-1),
               dot(-2,1),
               dot(-2,-1) };

vector<dot> expend(dot d);
bool checkValid(dot d);
dot operator+(dot d1, dot d2);
int heuristic(dot d);
int search(priority_queue<pair<int, dot>, vector<pair<int, dot>>, compare>& que, vector<vector<bool>> reached);

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> row >> col;
        cin >> start.x >> start.y;
        cin >> target.x >> target.y;
        priority_queue<pair<int, dot>, vector<pair<int, dot>>, compare> que;
        que.push(make_pair(heuristic(start), start));
        vector<vector<bool>> reached(row + 1, vector<bool>(col + 1, false));
        reached[start.x][start.y] = true;
        cout << search(que, reached) << endl;
    }
    return 0;
}

vector<dot> expend(dot d) {
    vector<dot> dots;
    for (dot move : moves) {
        dot temp = d + move;
        if (checkValid(temp)) {
            dots.push_back(temp);
        }
    }
    return dots;
}

bool checkValid(dot d) {
    return d.x >= 1 && d.x <= row && d.y >= 1 && d.y <= col;
}

dot operator+(dot d1, dot d2) {
    return dot(d1.x + d2.x, d1.y + d2.y);
}

int heuristic(dot d) {
    return (abs(d.x - target.x) + abs(d.y - target.y)) / 3;
    //return 0;
}

int search(priority_queue<pair<int, dot>, vector<pair<int, dot>>, compare>& que, vector<vector<bool>> reached) {
    while (!que.empty()&&que.top().first <= heuristic(start) * 2) {
        pair<int, dot> current = que.top();
        que.pop();
        if (current.second == target) {
            return current.first;
        }
        for (dot d : expend(current.second)) {
            if (!reached[d.x][d.y]) {
                que.push(make_pair(current.first - heuristic(current.second) + 1 + heuristic(d), d));
                reached[d.x][d.y] = true;
            }
        }
    }
    return 0;
}