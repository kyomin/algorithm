#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int compare = pow(2, 31) - 1;	// Ÿ�ٰ� ���� ����� ���̴� int�� �ִ����� �ϴ� �ʱ�ȭ
		int ret = 0;
		int len = nums.size();
		int j, k;	// second, third ������

		sort(nums.begin(), nums.end());

		for (int i = 0; i < len; i++) {
			j = i + 1;
			k = len - 1;

			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				int val = abs(sum - target);	// Ÿ�ٰ��� ���� ���ϱ�

				if (val < compare) {
					compare = val;
					ret = sum;

					if (ret < target)
						j++;
					else
						k--;
				}
				else if (sum < target) {
					j++;
				}
				else {
					k--;
				}
			}
		}

		return ret;
	}
};