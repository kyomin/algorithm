#include <string>

using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		string ans = "";

		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			
			if (isupper(ch))
				ans += (char)(ch + 32);
			else
				ans += ch;
		}

		return ans;
	}
};