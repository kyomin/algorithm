#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v;
	int sum = 0;

	for (int i = 0; i < 7; i++) {
		int n;
		cin >> n;

		if (n % 2 == 1) {
			sum += n;
			v.push_back(n);
		}
	}

	if (sum == 0) {
		cout << -1 << endl;
		return 0;
	}

	sort(v.begin(), v.end());

	cout << sum << '\n' << v[0] << '\n';

	return 0;
}