#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 10;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int map[MAX][MAX];
bool check[MAX][MAX];
vector<pair<int, int>> arr;
vector<pair<int, int>> vc;

int N;
int ans;

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

bool plantFlowers(int r, int c) {
	if (check[r][c]) return false;
	
	check[r][c] = true;

	for (int k = 0; k < 4; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];

		// 범위를 벗어나거나 이미 심어진 꽃과 만나는 경우 
		if (!isInside(nr, nc)) return false;
		if (check[nr][nc]) return false;

		check[nr][nc] = true;
	}

	return true;
}

void dfs(int cnt) {
	if (vc.size() == 3) {
		memset(check, false, sizeof(check));

		for (int i = 0; i < 3; i++) {
			int r = vc[i].first;
			int c = vc[i].second;

			// 꽃 3개를 심지 못하는 경우가 발견되면
			if (!plantFlowers(r, c)) return;
		}

		// for문을 정상적으로 빠져나왔으면 꽃 3개를 잘 심은 것이다.
		int sum = 0;
		
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				if (check[r][c])
					sum += map[r][c];

		ans = min(ans, sum);

		return;
	}

	for (int i = cnt; i < N*N; i++) {
		if (vc.size() < 3) {
			vc.push_back(arr[i]);
			dfs(cnt + 1);
			vc.pop_back();
		}
	}
}

void input() {
	ans = INF;
	cin >> N;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];

			arr.push_back(make_pair(r, c));
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	dfs(0);

	cout << ans << '\n';

	return 0;
}