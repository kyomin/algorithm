#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;

int ans = numeric_limits<int>::max();

int a[51][51];
int temp[51][51];

vector<pair<int, int>> chicken;
vector<pair<int, int>> vc;
int N, M, m;

void solution() {
	int sum = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (temp[i][j] == 1) {
				int min_dist = (int)abs(vc[0].first - i) + (int)abs(vc[0].second - j);

				for (int k = 1; k < m; k++) {
					min_dist = min(min_dist,
						(int)abs(vc[k].first - i) + (int)abs(vc[k].second - j)
					);
				}

				sum += min_dist;
			}
		}
	}

	ans = min(ans, sum);
}

void DFS(int cnt) {
	if (vc.size() == m) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				temp[i][j] = a[i][j];
		}

		solution();
	}

	for (int i = cnt; i < chicken.size(); i++) {
		if (vc.size() < m) {
			vc.push_back(chicken[i]);

			DFS(i + 1);

			vc.pop_back();
		}
	}
}

int main() {
	memset(a, 0, sizeof(a));

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int n;
			cin >> n;

			if (n == 0 || n == 1)
				a[i][j] = n;
			else
				// 치킨 집 좌표 담기
				chicken.emplace_back(i, j);
		}
	}

	for (int i = 1; i <= M; i++) {
		m = i;

		DFS(0);

		vc.clear();
	}

	cout << ans << '\n';

	return 0;
}