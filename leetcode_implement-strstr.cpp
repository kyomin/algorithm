#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "")
			return 0;
		
		int haystack_len = haystack.size();
		int needle_len = needle.size();
		int ans = -1;

		for (int i = 0; i <= haystack_len - needle_len; i++) {
			string substr = haystack.substr(i, needle_len);

			if (substr == needle) {
				ans = i;
				break;
			}
		}

		return ans;
	}
};