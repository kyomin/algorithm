#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string digits;
	vector<string> out;
	vector<string> mapping_of_digit = {
			"abc", "def", "ghi", "jkl",
			"mno", "pqrs", "tuv", "wxyz"
	};

	void recur(int digits_index, string ans) {
		if (digits_index >= digits.size()) {
			out.push_back(ans);
			return;
		}

		int digit = (int)(digits[digits_index] - '0');
		string str = mapping_of_digit[digit - 2];

		for (int i = 0; i < str.size(); i++)
			recur(digits_index + 1, ans + str[i]);
	}

	vector<string> letterCombinations(string digits) {
		this->digits = digits;

		// 최소 케이스 처리
		if (digits == "")
			return {};

		recur(0, "");

		return out;
	}
};