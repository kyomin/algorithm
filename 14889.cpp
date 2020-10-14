#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int S[21][21];
bool check[21];
int ans = 987654321;
vector<int> vc;

void dfs(int cnt) {
	if (vc.size() == M) {
		int start_sum = 0;
		int link_sum = 0;

		for (int i = 1; i <= N; i++) {
			if (check[i]) {
				for (int j = 1; j <= N; j++)
					if (check[j])
						start_sum += S[i][j];
			}
			else {
				for (int j = 1; j <= N; j++)
					if (!check[j])
						link_sum += S[i][j];
			}
		}

		ans = min(ans, (int)abs(start_sum - link_sum));
		return;
	}

	for (int i = cnt; i <= N; i++) {
		if (vc.size() < M) {
			vc.push_back(i);
			check[i] = true;

			dfs(i + 1);

			vc.pop_back();
			check[i] = false;
		}
	}
}

int main() {
	cin >> N;
	M = (N / 2);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> S[i][j];

	dfs(1);

	cout << ans << '\n';

	return 0;
}