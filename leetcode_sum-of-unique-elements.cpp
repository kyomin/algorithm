#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	int numFreq[101];

	int sumOfUnique(vector<int>& nums) {
		memset(numFreq, 0, sizeof(numFreq));
		
		int len = nums.size();

		for (int i = 0; i < len; i++) {
			int num = nums[i];

			numFreq[num]++;
		}

		int sum = 0;

		for (int i = 1; i <= 100; i++)
			if (numFreq[i] == 1)
				sum += i;

		return sum;
	}
};