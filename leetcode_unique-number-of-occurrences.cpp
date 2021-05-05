#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool check[1001];

	bool uniqueOccurrences(vector<int>& arr) {
		memset(check, false, sizeof(check));

		map<int, int> m;		// first : num, second : frequency
		int len = arr.size();

		for (int i = 0; i < len; i++) {
			int num = arr[i];

			if (m.find(num) == m.end())	// 해당 키를 못 찾았다면
				m[num] = 1;
			else // 해당 키를 찾았다면 빈도 증가!
				m.find(num)->second += 1;
		}

		vector<pair<int, int>> v;
		copy(m.begin(), m.end(), back_inserter(v));

		// 빈도수들만 담기
		vector<int> freq;

		for (int i = 0; i < v.size(); i++)
			freq.push_back(v[i].second);

		for (int i = 0; i < freq.size(); i++) {
			if (!check[freq[i]])
				check[freq[i]] = true;
			else
				return false;
		}

		return true;
	}
};