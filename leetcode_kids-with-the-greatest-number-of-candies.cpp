#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int max = *max_element(candies.begin(), candies.end());
		vector<bool> ans;

		for (int candy : candies) {
			if (candy + extraCandies >= max)
				ans.push_back(true);
			else
				ans.push_back(false);
		}

		return ans;
	}
};