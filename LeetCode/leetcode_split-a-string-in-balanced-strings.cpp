#include <string>

using namespace std;

class Solution {
public:
	int balancedStringSplit(string s) {
		int len = s.length();
		int ans = 0;
		int L_cnt = 0;
		int R_cnt = 0;

		for (int i = 0; i < len; i++) {
			if (L_cnt > 0 && R_cnt > 0 && L_cnt == R_cnt) {
				ans++;
				L_cnt = 0;
				R_cnt = 0;
			}

			if (s[i] == 'L')
				L_cnt++;
			else
				R_cnt++;
		}

		if (L_cnt > 0 && R_cnt > 0 && L_cnt == R_cnt)
			ans++;

		return ans;
	}
};