#include <iostream>

using namespace std;

int ans[5];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int x, y;
		cin >> x >> y;

		if (x == 0 || y == 0)
			ans[4] += 1;
		else if (x > 0 && y > 0)
			ans[0] += 1;
		else if (x < 0 && y>0)
			ans[1] += 1;
		else if (x < 0 && y < 0)
			ans[2] += 1;
		else if (x > 0 && y < 0)
			ans[3] += 1;
	}

	cout << "Q1: " << ans[0] << '\n';
	cout << "Q2: " << ans[1] << '\n';
	cout << "Q3: " << ans[2] << '\n';
	cout << "Q4: " << ans[3] << '\n';
	cout << "AXIS: " << ans[4] << '\n';

	return 0;
}