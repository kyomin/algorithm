#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums;

		for (int i = 0; i < nums1.size(); i++)
			nums.push_back(nums1[i]);

		for (int i = 0; i < nums2.size(); i++)
			nums.push_back(nums2[i]);

		// 오름차순 정렬
		sort(nums.begin(), nums.end());

		if (nums.size() % 2 == 1)
			return nums[nums.size() / 2];
		else {
			int idx = nums.size() / 2;

			return((double)(nums[idx - 1] + nums[idx]) / 2);
		}
	}
};