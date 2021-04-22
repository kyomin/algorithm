#include <string>

using namespace std;

class Solution {
public:
	bool check[26] = { false };		// 알파벳 체크용

	bool checkIfPangram(string sentence) {
		int len = sentence.length();

		for (int i = 0; i < len; i++) {
			int idx = (int)(sentence[i] - 'a');

			if (!check[idx])
				check[idx] = true;
		}

		for (int i = 0; i < 26; i++)
			if (!check[i])
				return false;
		
		return true;
	}
};