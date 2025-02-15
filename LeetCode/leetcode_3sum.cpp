#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		// ���Ǹ� ���� �������� ����
		sort(nums.begin(), nums.end());

		vector<vector<int>> ret;
		int len = nums.size();
		int j, k;	// i:first, j: second, k: third

		for (int i = 0; i < len; i++) {
			// ù �����Ͱ� ó�� �ε����̰ų�, ���� ���� ���� �ʴٸ� ��ȸ!
			if (i == 0 || nums[i] != nums[i - 1]) {
				j = i + 1;
				k = len - 1;

				// �� ��° �����Ͱ� �� ��° �����͸� �����ϱ� ������
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

						// ������ ���� ���� ��찡 ���� ������ ����
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