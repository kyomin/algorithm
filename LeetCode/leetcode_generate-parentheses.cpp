#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> result;

	void dfs(string s, int left, int right) {
		// 짝이 안 맞는 경우이다.
		if (left > right)
			return;

		if (left == 0 && right == 0) {
			result.push_back(s);
			return;
		}

		if (left > 0)
			dfs(s + "(", left - 1, right);
		if (right > 0)
			dfs(s + ")", left, right - 1);
	}

	vector<string> generateParenthesis(int n) {
		dfs("", n, n);

		return result;
	}
};