#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		const int MIN = pow(10, 5)*(-1);

		int ret = MIN;
		int pSum = 0;

		for (int i = 0; i < nums.size(); i++) {
			pSum = max(pSum, 0) + nums[i];
			ret = max(pSum, ret);
		}

		return ret;
	}
};