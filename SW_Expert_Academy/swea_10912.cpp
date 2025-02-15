#include <iostream>
#include <string>

using namespace std;

int alpha[26];

void init() {
	for (int i = 0; i < 26; i++)
		alpha[i] = 0;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string s;
		cin >> s;

		init();

		for (int i = 0; i < s.size(); i++) {
			char ch = s[i];
			int idx = (int)(ch - 'a');
			alpha[idx]++;
		}

		bool judge = true;
		string ans = "";

		for (int i = 0; i < 26; i++) {
			if (alpha[i] == 0)
				continue;

			// 해당 알파벳이 짝수 개 등장 했으면 짝이 맞으므로
			if (alpha[i] % 2 == 0)
				continue;

			// 홀수 개 등장하는 순간 짝이 안 맞는 것이다.
			judge = false;
			ans += (char)(i + 'a');
		}

		// 모두가 짝이 맞는 경우이다.
		if (judge) {
			cout << '#' << t << ' ' << "Good" << '\n';
			continue;
		}

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}