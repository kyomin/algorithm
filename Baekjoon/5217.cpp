#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		vector<pair<int, int>> pairs;
		int n;
		cin >> n;

		cout << "Pairs for " << n << ":";

		for (int i = 1; i < 12; i++) {
			for (int j = i + 1; j <= 12; j++) {
				if (i + j == n) {
					pairs.push_back(make_pair(i, j));
				}
			}
		}

		int len = pairs.size();

		if (len == 0) {
			cout << '\n';
			continue;
		}
		
		for (int i = 0; i < len - 1; i++)
			cout << ' ' << pairs[i].first << ' ' << pairs[i].second << ",";

		if (len >= 1)
			cout << ' ' << pairs[len - 1].first << ' ' << pairs[len - 1].second << '\n';
	}

	return 0;
}