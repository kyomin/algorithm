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

	for (int t = 0; t < T; t++) {
		vector<int> candidates;
		int sum = 0;
		int N;
		cin >> N;

		candidates.resize(N);

		for (int n = 0; n < N; n++) {
			cin >> candidates[n];
			sum += candidates[n];
		}
		
		int half = sum / 2;
		int max = *max_element(candidates.begin(), candidates.end());
		int max_count = 0;
		int R;

		for (int n = 0; n < N; n++) {
			if (candidates[n] == max) {
				max_count++;
				R = n + 1;
			}
		}
		
		// 최다 득표자가 없는 경우
		if (max_count >= 2) {
			cout << "no winner" << '\n';
			continue;
		}

		if (max > half)
			cout << "majority winner " << R << '\n';
		else
			cout << "minority winner " << R << '\n';
	}

	return 0;
}