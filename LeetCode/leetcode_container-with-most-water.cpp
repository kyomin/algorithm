#include <vector>

using namespace std;

class Solution {
public:
	int min(int a, int b) {
		if (a < b)
			return a;
		else
			return b;
	}

	int max(int a, int b) {
		if (a > b)
			return a;
		else
			return b;
	}

	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int max_area = (right - left)*min(height[left], height[right]);

		while (left < right) {
			if (height[left] <= height[right])
				left++;
			else
				right--;

			max_area = max(max_area, (right - left)*min(height[left], height[right]));
		}

		return max_area;
	}
};