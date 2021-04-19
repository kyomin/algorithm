#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		
		for (auto it = nums.begin(); it != nums.end();) {
			if (*it == val)
				it = nums.erase(it);
			else
				it++;
		}

		return nums.size();
	}
};