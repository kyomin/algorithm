#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	int nums[10001];

	int repeatedNTimes(vector<int>& A) {
		memset(nums, 0, sizeof(nums));

		int len = A.size();
		int ans = 0;
		
		for (int i = 0; i < len; i++) {
			int num = A[i];
			nums[num]++;
		}

		for (int i = 1; i <= 10000; i++) {
			if (nums[i] != 0 && nums[i] != 1) {
				ans = i;
				break;
			}
		}

		return ans;
	}
};