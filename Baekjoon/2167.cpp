#include <iostream>

using namespace std;

int arr[301][301];

int N, M, K;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int row = 1; row <= N; row++)
		for (int col = 1; col <= M; col++)
			cin >> arr[row][col];

	cin >> K;

	for (int k = 0; k < K; k++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;

		int sum = 0;

		for (int row = i; row <= x; row++)
			for (int col = j; col <= y; col++)
				sum += arr[row][col];

		cout << sum << '\n';
	}

	return 0;
}