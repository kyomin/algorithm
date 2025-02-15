#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<int> scores;
		int N;
		cin >> N;

		scores.resize(N);

		for (int n = 0; n < N; n++)
			cin >> scores[n];

		sort(scores.begin(), scores.end());

		int max = *max_element(scores.begin(), scores.end());
		int min = *min_element(scores.begin(), scores.end());

		int largest_gap = 0;
		
		for (int i = 1; i < N; i++) {
			int gap = scores[i] - scores[i - 1];

			if (gap > largest_gap)
				largest_gap = gap;
		}

		cout << "Class " << t << '\n';
		cout << "Max " << max << ", Min " << min << ", Largest gap " << largest_gap << '\n';
	}

	return 0;
}