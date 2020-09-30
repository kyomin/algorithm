#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 길이 순 내림차 정렬
bool comp(const string &s1, const string &s2) {
	if (s1.size() > s2.size())
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<string> strings;
	vector<string> ans;

	for (int n = 0; n < N; n++) {
		string s;
		cin >> s;

		strings.push_back(s);
	}

	sort(strings.begin(), strings.end(), comp);

	for (int i = 0; i < N; i++) {
		// 가장 긴 것은 일단 넣는다.
		if (i == 0) {
			ans.push_back(strings[i]);
			continue;
		}

		string s = strings[i];
		int len = ans.size();
		bool isHead = false;

		for (int j = 0; j < len; j++) {
			if (ans[j].substr(0, s.size()) == s) {
				isHead = true;
				break;
			}
		}

		if (!isHead)
			ans.push_back(s);
	}

	cout << ans.size() << '\n';

	return 0;
}