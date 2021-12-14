#include <iostream>
using namespace std;

const int MAX = 1000000;
const int MIN = -1000000;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		int max = MIN;
		int min = MAX;

		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;

			if (num > max)
				max = num;

			if (num < min)
				min = num;
		}

		cout << min << ' ' << max << '\n';
	}

	return 0;
}