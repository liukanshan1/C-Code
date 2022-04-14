#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int maxWealth = 0;
		for (auto i : accounts)
		{
			int temp = accumulate(i.begin(), i.end(), 0); //��������������͵ĳ�ʼֵ��ͬʱ��������ֵ����
			if (temp > maxWealth)
			{
				maxWealth = temp;
			}
		}
		return maxWealth;
    }
};