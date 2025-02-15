#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int cnt = 0;

		while (next_permutation(nums.begin(), nums.end())) {
			cnt++;

			if (cnt == 1)
				break;
		}

		// �� �������� ��� �ٽ� ó������
		if (cnt == 0)
			sort(nums.begin(), nums.end());
	}
};