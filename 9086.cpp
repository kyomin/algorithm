#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string S;
		string ans = "";

		cin >> S;
		int len = S.size();

		ans += S[0];
		ans += S[len - 1];

		cout << ans << '\n';
	}

	return 0;
}