#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> que;
		map<int, int> mp;
		vector<int> res;
		while (nums.size()!=0)
		{
			int num = nums.back();
			nums.pop_back();
			map<int, int>::iterator it = mp.end();
			if ((it = mp.find(num)) != mp.end())
			{
				it->second += 1;
			}
			else
			{
				mp.insert(make_pair(num, 1));
			}
		}
		for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			que.push(make_pair(it->second, it->first));
		}
		for (int i = 0; i < k; i++)
		{
			res.push_back(que.top().second);
			que.pop();
		}
		return res;
    }
};

int main()
{
	Solution s;
	vector<int> nums = {1,1,1,2,2,3};
	int k = 2;
	vector<int> res = s.topKFrequent(nums, k);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;

}



