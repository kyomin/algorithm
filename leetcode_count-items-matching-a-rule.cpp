#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int ans = 0;
		map<string, int> m;
		m["type"] = 0;
		m["color"] = 1;
		m["name"] = 2;

		for (auto item : items)
			if (item[m.find(ruleKey)->second] == ruleValue)
				ans++;
		
		return ans;
	}
};