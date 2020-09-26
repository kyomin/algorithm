#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int len;
		cin >> len;

		string str1, str2;
		cin >> str1 >> str2;

		int ans = 0;

		for (int i = 0; i < len; i++) {
			if (str1[i] == str2[i])
				ans++;
		}

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}