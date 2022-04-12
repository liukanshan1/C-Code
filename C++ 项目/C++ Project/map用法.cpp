#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
		map<int, int, greater<int>> ranks;
        int size = score.size();
		for (int i = 0; i < size; i++)
		{
            ranks.insert(make_pair(score[i], i));
		}
		vector<string> res;
		res.resize(size);
		int i = 0;
		for (map<int, int>::iterator p = ranks.begin(); p!=ranks.end(); p++,i++)
		{
			if (i == 0)
			{
				res[p->second] = "Gold Medal";
			}
			else if (i == 1)
			{
				res[p->second] = "Silver Medal";
			}
			else if (i == 2)
			{
				res[p->second] = "Bronze Medal";
			}
			else
			{
				res[p->second] = to_string(i + 1);
			}
		}
		return res;
    }
};

int main()
{
	vector<int> score;
	score.push_back(10);
	score.push_back(3);
	score.push_back(8);
	score.push_back(9);
	score.push_back(4);
	Solution s;
	vector<string> res = s.findRelativeRanks(score);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}