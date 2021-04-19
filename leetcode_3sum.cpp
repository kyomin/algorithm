#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		// 편의를 위해 오름차순 정렬
		sort(nums.begin(), nums.end());

		vector<vector<int>> ret;
		int len = nums.size();
		int j, k;	// i:first, j: second, k: third

		for (int i = 0; i < len; i++) {
			// 첫 포인터가 처음 인덱스이거나, 이전 값과 같지 않다면 순회!
			if (i == 0 || nums[i] != nums[i - 1]) {
				j = i + 1;
				k = len - 1;

				// 두 번째 포인터가 세 번째 포인터를 역전하기 전까지
				while (j < k) {
					int sum = nums[i] + nums[j] + nums[k];

					if (sum == 0) {
						vector<int> out;
						out.push_back(nums[i]);
						out.push_back(nums[j]);
						out.push_back(nums[k]);
						ret.push_back(out);

						j++;
						k--;

						// 이전과 같지 않은 경우가 나올 때까지 갱신
						while (j < len - 1 && nums[j] == nums[j - 1])
							j++;

						while (k > j && nums[k] == nums[k + 1])
							k--;
					}
					else if (sum > 0) {
						k--;
					}
					else {
						j++;
					}
				}
			}
		}

		return ret;
	}
};