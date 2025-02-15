#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> out;
		int len = nums.size();
		int sum = 0;
		bool found = false;

		for (int first = 0; first < len - 1; first++) {
			if (found)
				break;

			sum += nums[first];

			for (int second = first + 1; second < len; second++) {
				if (found)
					break;

				sum += nums[second];

				if (sum == target) {
					out.push_back(first);
					out.push_back(second);

					found = true;
				}

				sum -= nums[second];
			}

			sum -= nums[first];
		}

		return out;
	}
};