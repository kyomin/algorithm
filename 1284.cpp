#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		string str;
		cin >> str;

		if (str == "0")
			break;

		int len = 0;

		len += 2;	// 양 끝
		len += (str.size() - 1);	// 숫자 사이 여백

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '0') {
				len += 4;
				continue;
			}

			if (str[i] == '1') {
				len += 2;
				continue;
			}

			len += 3;
		}

		cout << len << '\n';
	}

	return 0;
}