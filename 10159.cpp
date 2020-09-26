#include <iostream>

using namespace std;

int weight[101][101];
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		weight[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (weight[i][k] && weight[k][j])
					weight[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;

		for (int j = 1; j <= n; j++) {
			if (!weight[i][j] && !weight[j][i])
				cnt++;
		}

		cout << cnt - 1 << '\n';	// 자기 자신과의 비교는 제외!
	}

	return 0;
}