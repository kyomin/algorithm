#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;

		int num1 = atoi(str.c_str());

		reverse(str.begin(), str.end());
		
		int num2 = atoi(str.c_str());
		
		int sum = num1 + num2;
		
		str = to_string(sum);
		int len = str.size();

		if (len % 2 == 0) {
			int mid = len / 2;

			string left = str.substr(0, mid);
			string right = str.substr(mid, mid);
			reverse(right.begin(), right.end());

			if (left == right)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
		else {
			int mid = len / 2;

			string left = str.substr(0, mid);
			string right = str.substr(mid + 1, mid);
			reverse(right.begin(), right.end());

			if (left == right)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}