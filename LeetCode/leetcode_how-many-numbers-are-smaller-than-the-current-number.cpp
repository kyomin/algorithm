#include <vector>

using namespace std;

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> ans;
		int len = nums.size();
		ans.resize(len);

		for (int i = 0; i < len; i++) {
			int num = nums[i];
			int cnt = 0;

			for (int j = 0; j < len; j++) {
				if (i == j)
					continue;

				if (num > nums[j])
					cnt++;
			}

			ans[i] = cnt;
		}

		return ans;
	}
};