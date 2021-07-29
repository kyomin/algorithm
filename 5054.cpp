#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		vector<int> store_pos;
		int N;
		cin >> N;
		store_pos.resize(N);

		for (int n = 0; n < N; n++)
			cin >> store_pos[n];

		int min = *min_element(store_pos.begin(), store_pos.end());
		int max = *max_element(store_pos.begin(), store_pos.end());

		cout << (max-min)*2 << '\n';
	}

	return 0;
}