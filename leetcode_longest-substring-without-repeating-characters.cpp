#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0;
		int len = s.size();

		for (int i = 0; i < len; i++) {
			vector<char> temp;

			for (int start = i; start < len; start++) {
				char ch = s[start];

				int judge = find(temp.begin(), temp.end(), ch) - temp.begin();

				// 해당 문자를 담지 않은 경우
				if (judge == temp.size())
					temp.push_back(ch);
				else
					break;
			}
			
			if (temp.size() > ans)
				ans = temp.size();
		}

		return ans;
	}
};