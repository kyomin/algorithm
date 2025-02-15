#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isInAllowed(char ch, string allowed) {
		int len = allowed.length();

		for (int i = 0; i < len; i++)
			if (ch == allowed[i])
				return true;

		return false;
	}

	int countConsistentStrings(string allowed, vector<string>& words) {
		int ans = 0;
		
		for (auto word : words) {
			int len = word.length();
			bool nagative_flag = false;

			for (int i = 0; i < len; i++) {
				if (!isInAllowed(word[i], allowed)) {
					nagative_flag = true;
					break;
				}
			}

			if (!nagative_flag)
				ans++;
		}

		return ans;
	}
};