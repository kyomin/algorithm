#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string s;
		cin >> s;
		
		int cnt = 0;
		int left = 0;
		int right = s.length() - 1;
		bool flag = true;

		while (left <= right) {
			cnt++;

			if (s[left] != s[right]) {
				flag = false;
				break;
			}

			left++;
			right--;
		}

		cout << (flag ? 1 : 0) << ' ' << (flag&&s.length() % 2 == 0 ? cnt + 1 : cnt) << '\n';
	}

	return 0;
}