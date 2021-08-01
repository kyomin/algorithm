#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	string str_n = to_string(N);
	int len = str_n.length();
	int q = M / len;
	int r = M % len;

	if (r != 0)
		q += 1;

	string ans = "";

	if (len*N >= M) {
		while (true) {
			ans += str_n;
			if (ans.length() >= M) {
				ans = ans.substr(0, M);
				break;
			}
		}
	}
	else {
		for (int i = 0; i < N; i++)
			ans += str_n;
	}

	cout << ans << '\n';

	return 0;
}