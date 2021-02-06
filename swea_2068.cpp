#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<int> v;
		v.resize(10);

		for (int i = 0; i < 10; i++)
			cin >> v[i];

		cout << '#' << t << ' ' << *max_element(v.begin(), v.end()) << '\n';
	}

	return 0;
}