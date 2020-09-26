#include <iostream>

using namespace std;

int baskets[101];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		int start, end, ball;
		cin >> start >> end >> ball;

		for (int i = start; i <= end; i++) {
			baskets[i] = ball;
		}
	}

	for (int i = 1; i <= N; i++)
		cout << baskets[i] << ' ';

	cout << '\n';

	return 0;
}