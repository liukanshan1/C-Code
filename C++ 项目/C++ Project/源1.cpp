#include<iostream>
#include<vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		map<char, int> mp;
		for (auto c : s)
		{
			mp[c]++;
	    }
		priority_queue<pair<int, char>> pq;
		for (auto it : mp)
		{
			pq.push(make_pair(it.second, it.first));
		}
		string res;
		while (!pq.empty())
		{
			auto p = pq.top();
			pq.pop();
			for (int i = 0; i < p.first; i++)
			{
				res+=p.second;
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	
	cout << s.frequencySort("tree");
}