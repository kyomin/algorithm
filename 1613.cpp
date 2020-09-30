#include <iostream>

using namespace std;

int history[401][401];
int N, K, S;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int k = 0; k < K; k++) {
		int history1, history2;
		cin >> history1 >> history2;

		// history1 > history2¿Ã¥Ÿ.
		history[history1][history2] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (history[i][k] && history[k][j])
					history[i][j] = 1;

	cin >> S;

	for (int s = 0; s < S; s++) {
		int history1, history2;
		cin >> history1 >> history2;

		if (history[history1][history2])
			cout << -1 << '\n';
		else if (history[history2][history1])
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}