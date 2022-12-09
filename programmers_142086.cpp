#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int len = s.length();

	for (int i = 0; i < len; i++) {
		char ch = s[i];
		bool found = false;
		int cnt = 1;

		for (int j = i - 1; j >= 0; j--) {
			if (s[j] == ch) {
				found = true;
				break;
			}

			cnt++;
		}

		if (found)
			answer.push_back(cnt);
		else
			answer.push_back(-1);
	}

	return answer;
}