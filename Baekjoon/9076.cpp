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
		vector<int> scores;
		scores.resize(5);

		for (int i = 0; i < 5; i++)
			cin >> scores[i];

		sort(scores.begin(), scores.end());

		int sum = 0;
		int diff = scores[3] - scores[1];

		for (int i = 1; i < 4; i++)
			sum += scores[i];

		if (diff >= 4)
			cout << "KIN" << '\n';
		else
			cout << sum << '\n';
	}

	return 0;
}