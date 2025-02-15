#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		string str_x = to_string(x);
		string original = str_x;
		reverse(str_x.begin(), str_x.end());

		if (original == str_x)
			return true;
		else
			return false;
	}
};