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

			// �ش� ���ĺ��� ¦�� �� ���� ������ ¦�� �����Ƿ�
			if (alpha[i] % 2 == 0)
				continue;

			// Ȧ�� �� �����ϴ� ���� ¦�� �� �´� ���̴�.
			judge = false;
			ans += (char)(i + 'a');
		}

		// ��ΰ� ¦�� �´� ����̴�.
		if (judge) {
			cout << '#' << t << ' ' << "Good" << '\n';
			continue;
		}

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}