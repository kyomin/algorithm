#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int left = 0;
	int right = 0;
	bool isRight = false;
	string str;
	cin >> str;

	int len = str.size();

	for (int i = 0; i < len; i++) {
		if (str[i] == ')') {
			isRight = true;
			continue;
		}

		if (str[i] == '@') {
			if (!isRight)
				left++;
			else
				right++;
		}
	}

	cout << left << ' ' << right << '\n';

	return 0;
}