#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = 0;
	int passengers = 0;

	for (int i = 1; i <= 10; i++) {
		int in, out;
		cin >> out >> in;

		passengers += (in - out);

		ans = max(ans, passengers);
	}

	cout << ans << '\n';

	return 0;
}