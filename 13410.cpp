#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = 0;
	int N, K;
	cin >> N >> K;

	for (int k = 1; k <= K; k++) {
		int num = N * k;
		string str = to_string(num);
		reverse(str.begin(), str.end());

		ans = max(ans, atoi(str.c_str()));
	}

	cout << ans << '\n';

	return 0;
}