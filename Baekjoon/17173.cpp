#include <iostream>

using namespace std;

bool check[1001];

int main() {
	int sum = 0;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;

		for (int j = 1; j <= N; j++) {
			if (j%n == 0) {
				if (!check[j]) {
					sum += j;
					check[j] = true;
				}
			}
		}
	}

	cout << sum << '\n';

	return 0;
}