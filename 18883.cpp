#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int num = 1;

	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= M; col++) {
			if (col == M)
				cout << num++ << '\n';
			else
				cout << num++ << ' ';
		}
	}

	return 0;
}