#include <iostream>

using namespace std;

int main() {
	int ans = 0;
	int t;
	cin >> t;

	for (int i = 0; i < 5; i++) {
		int tea;
		cin >> tea;

		if (t == tea)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}