#include <iostream>

using namespace std;

int main() {
	int N, R, C;
	cin >> N >> R >> C;

	char **A = new char*[N + 1];

	for (int i = 1; i <= N; i++)
		A[i] = new char[N + 1];

	if (((R % 2 == 1) && (C % 2 == 1)) || ((R % 2 == 0) && (C % 2 == 0))) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (((i % 2 == 1) && (j % 2 == 1)) || ((i % 2 == 0) && (j % 2 == 0)))
					A[i][j] = 'v';
				else
					A[i][j] = '.';
			}
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (((i % 2 == 1) && (j % 2 == 0)) || ((i % 2 == 0) && (j % 2 == 1)))
					A[i][j] = 'v';
				else
					A[i][j] = '.';
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << A[i][j];

		cout << '\n';
	}

	return 0;
}