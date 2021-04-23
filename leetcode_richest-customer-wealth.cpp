#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int maximum_wealth = 0;

		for (auto account : accounts) {
			int sum = 0;
			
			for (int i = 0; i < account.size(); i++) 
				sum += account[i];
			
			maximum_wealth = max(maximum_wealth, sum);
		}

		return maximum_wealth;
	}
};