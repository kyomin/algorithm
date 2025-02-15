#include <vector>

using namespace std;

class Solution {
public:
	int count_num[101] = { 0 };

	int numIdenticalPairs(vector<int>& nums) {
		int ans = 0;

		for (int num : nums)
			count_num[num]++;

		for (int i = 1; i <= 100; i++)
			if (count_num[i] >= 2)
				ans += (((count_num[i])*(count_num[i] - 1)) / 2);

		return ans;
	}
};