#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int *coin = new int[N + 1];

		for (int i = 1; i <= N; i++) {
			int n;
			cin >> n;
			coin[i] = n;
		}

		int M;
		cin >> M;

		int *DP = new int[M + 1];

		for (int i = 1; i <= M; i++)
			DP[i] = 0;

		for (int i = 1; i <= N; i++) {
			if (i == 1) {
				for (int j = 1; j <= M; j++)
					if (j%coin[i] == 0)
						DP[j] = 1;
			}
			else {
				for (int j = coin[i]; j <= M; j++)
					if (j == coin[i])
						DP[j] += 1;
					else
						DP[j] = DP[j - coin[i]] + DP[j];
			}
		}

		cout << DP[M] << endl;
	}

	return 0;
}