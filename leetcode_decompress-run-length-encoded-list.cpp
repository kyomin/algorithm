#include <vector>

using namespace std;

class Solution {
public:
	vector<int> decompressRLElist(vector<int>& nums) {
		vector<int> out;
		int len = nums.size();

		for (int i = 0; i < len; i+=2) {
			int num = nums[i + 1];
			int freq = nums[i];

			for (int j = 0; j < freq; j++)
				out.push_back(num);
		}

		return out;
	}
};