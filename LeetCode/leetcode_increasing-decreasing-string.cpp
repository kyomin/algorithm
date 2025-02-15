#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string sortString(string s) {
		string ans = "";
		bool isAscent = true;

		while (s.length() != 0) {
			if (isAscent) {
				sort(s.begin(), s.end());
				isAscent = false;
			}
			else {
				sort(s.begin(), s.end());
				reverse(s.begin(), s.end());
				isAscent = true;
			}
			
			string temp = "";
			char prev = s[0];
			ans += prev;
			int len = s.length();

			for (int i = 1; i < len; i++) {
				if (s[i] == prev)
					temp += s[i];
				else {
					ans += s[i];
					prev = s[i];
				}
			}

			s = temp;
		}

		return ans;
	}
};