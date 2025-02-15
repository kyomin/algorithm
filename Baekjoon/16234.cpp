#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

struct population {
	int row;
	int col;
	int num;
};

const int MAX = 50;
const int dr[] = { 1, -1, 0, 0 };
const int dc[] = { 0, 0, 1, -1 };

int ans;
bool flag = true;
int N, L, R;
int map[MAX][MAX];
bool check[MAX][MAX];
queue<population> populations;	// 연합 정보를 담는다.

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;
	else
		return false;
}

void dfs(int r, int c) {
	check[r][c] = true;
	int cur_num = map[r][c];
	populations.push({ r, c, cur_num });

	for (int k = 0; k < 4; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];

		// 탐색 조건 만족 X
		if (!isInside(nr, nc)) continue;
		if (check[nr][nc]) continue;

		int next_num = map[nr][nc];
		int diff = abs(cur_num - next_num);

		// 연합 조건을 만족한다면 연합이 하나라도 있는 것이다.
		if (L <= diff && diff <= R) {
			flag = true;	// 존재해서 다음에 다시 한 번 작업

			dfs(nr, nc);
		}
	}
}

// 형성된 연합에 골고루 뿌려질 값을 계산해 넣는다.
void spreadAvgInUnion() {
	int cnt = populations.size();	// 연합을 이루고 있는 칸의 개수
	int sum = 0;
	queue<population> union_copy = populations;

	while (!populations.empty()) {
		int num = populations.front().num;
		populations.pop();

		sum += num;
	}

	int avg = sum / cnt;

	while (!union_copy.empty()) {
		int r = union_copy.front().row;
		int c = union_copy.front().col;
		map[r][c] = avg;
		union_copy.pop();
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L >> R;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> map[r][c];

	while (flag) {
		// 매회마다 탐색을 다시 진행할 것이므로
		memset(check, false, sizeof(check));
		flag = false;

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (check[r][c]) continue;

				dfs(r, c);

				spreadAvgInUnion();
			}
		}

		if(flag)
			ans += 1;
	}

	cout << ans << '\n';

	return 0;
}