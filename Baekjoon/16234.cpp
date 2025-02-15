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
queue<population> populations;	// ���� ������ ��´�.

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

		// Ž�� ���� ���� X
		if (!isInside(nr, nc)) continue;
		if (check[nr][nc]) continue;

		int next_num = map[nr][nc];
		int diff = abs(cur_num - next_num);

		// ���� ������ �����Ѵٸ� ������ �ϳ��� �ִ� ���̴�.
		if (L <= diff && diff <= R) {
			flag = true;	// �����ؼ� ������ �ٽ� �� �� �۾�

			dfs(nr, nc);
		}
	}
}

// ������ ���տ� ���� �ѷ��� ���� ����� �ִ´�.
void spreadAvgInUnion() {
	int cnt = populations.size();	// ������ �̷�� �ִ� ĭ�� ����
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
		// ��ȸ���� Ž���� �ٽ� ������ ���̹Ƿ�
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