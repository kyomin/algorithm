#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		int sum = 0;
		
		cin >> N;

		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			sum += n;
		}

		cout << sum << '\n';
	}

	return 0;
}