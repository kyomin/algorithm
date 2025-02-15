#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<char> all_vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

	bool isVowel(char ch) {
		for (int i = 0; i < all_vowels.size(); i++)
			if (ch == all_vowels[i])
				return true;

		return false;
	}

	bool halvesAreAlike(string s) {
		int len = s.length();
		int half = len / 2;

		string left = s.substr(0, half);
		string right = s.substr(half, half);

		int left_vowel_cnt = 0;
		int right_vowel_cnt = 0;

		for (int i = 0; i < left.length(); i++)
			if (isVowel(left[i]))
				left_vowel_cnt++;

		for (int i = 0; i < right.length(); i++)
			if (isVowel(right[i]))
				right_vowel_cnt++;

		if (left_vowel_cnt == right_vowel_cnt)
			return true;
		else
			return false;
	}
};