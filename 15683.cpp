#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void check(vector<vector<int>> &a, vector<vector<int>> &b, int x, int y, int dir) {
	int n = a.size();	// 행
	int m = a[0].size();	// 열

	// cctv의 위치, 여기를 기준으로 뻗어나갈 것이다.
	int i = x;
	int j = y;

	// 지도 범위 내에서
	while (0 <= i && i < n && 0 <= j && j < m) {
		if (a[i][j] == 6)	// 벽에 닿으면
			break;	// 더 뻗어나가지 않고 탈출!

		// 빈 칸이 아님을 표식
		b[i][j] = a[x][y];

		i += dx[dir];
		j += dy[dir];
	}
}

int go(vector<vector<int>> &a, vector<tuple<int, int, int>> &cctv,
	int index, vector<int> dirs
) {
	// cctv의 개수가 다 모이면 작업 시작!
	if (cctv.size() == index) {
		vector<vector<int>> b(a);	// b <- a copy!

		for (int i = 0; i < cctv.size(); i++) {
			int what, x, y;

			// 튜플 원소 차례로 담기
			tie(what, x, y) = cctv[i];

			// 각 cctv에 대해 처리!
			if (what == 1) {
				check(a, b, x, y, dirs[i]);
			}
			else if (what == 2) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 2) % 4);
			}
			else if (what == 3) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
			}
			else if (what == 4) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
				check(a, b, x, y, (dirs[i] + 2) % 4);
			}
			else if (what == 5) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
				check(a, b, x, y, (dirs[i] + 2) % 4);
				check(a, b, x, y, (dirs[i] + 3) % 4);
			}
		}

		// 위의 작업을 다 마치고 사각지대 세기(빈 칸 세기)
		int cnt = 0;
		int n = a.size();
		int m = a[0].size();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (b[i][j] == 0)
					cnt += 1;

		return cnt;
	}

	int ans = 100;

	for (int i = 0; i < 4; i++) {
		// index번째 cctv에 방향 넣기
		dirs[index] = i;

		int temp = go(a, cctv, index + 1, dirs);

		ans = min(ans, temp);
	}

	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;

	// 2차원 벡터 크기(만) 초기화
	vector<vector<int>> a(n, vector<int>(m));
	vector<tuple<int, int, int>> cctv;
	vector<int> dirs;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			// cctv라면 담아주기
			if (a[i][j] >= 1 && a[i][j] <= 5) {
				cctv.emplace_back(a[i][j], i, j);
				dirs.push_back(0);
			}
		}
	}

	cout << go(a, cctv, 0, dirs) << '\n';

	return 0;
}