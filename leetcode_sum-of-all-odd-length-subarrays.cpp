#include <vector>

using namespace std;

class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int sum = 0;
		int len = arr.size();
		int odd_len = 1;

		while (odd_len <= len) {
			for (int i = 0; i <= len - odd_len; i++)
				for (int j = i; j < (i + odd_len); j++) 
					sum += arr[j];
	
			odd_len += 2;
		}

		return sum;
	}
};