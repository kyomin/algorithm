#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	static bool comp(pair<int, char> p1, pair<int, char> p2) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}

	string restoreString(string s, vector<int>& indices) {
		string ans = "";
		vector<pair<int, char>> index_and_char;
		int len = indices.size();


		for (int i = 0; i < len; i++)
			index_and_char.push_back(make_pair(indices[i], s[i]));

		sort(index_and_char.begin(), index_and_char.end(), comp);

		for (int i = 0; i < len; i++)
			ans += index_and_char[i].second;

		return ans;
	}
};