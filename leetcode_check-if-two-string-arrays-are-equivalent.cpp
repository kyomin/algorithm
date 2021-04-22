#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
		string s1 = "";
		string s2 = "";

		for (string s : word1)
			s1 += s;

		for (string s : word2)
			s2 += s;

		if (s1 == s2)
			return true;
		else
			return false;
	}
};