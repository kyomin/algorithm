#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = 0;
	int N;
	cin >> N;

	for (int i = 1; i < N; i++) {
		string str = to_string(i);
		int sum = i;
		int len = str.size();

		for (int j = 0; j < len; j++)
			sum += (int)(str[j] - '0');

		if (sum == N) {
			ans = i;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}