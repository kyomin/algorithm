#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int RIGHT = 1;
const int LEFT = 2;
const int INF = 987654321;

int N, M, H;
int ladder[30][10];

bool check() {
	for (int i = 0; i < N; i++) {
		int row = 0;
		int col = i;

		do {
			if (ladder[row][col] == LEFT)
				col--;
			else if (ladder[row][col] == RIGHT)
				col++;

			row++;	// 왼쪽, 오른쪽으로 움직였건, 내려간다.
		} while (row != H);

		// 끝에 도달했을 때, 시작 열과 같지가 않다면
		if (i != col)
			return false;
	}

	// 위의 반복문을 다 거쳤다면 필터링이 된 것이다.
	return true;
}

// pos: 현 위치, cnt: 선택한 개수
int solve(int pos, int cnt) {
	// base case : 3개의 조합을 구했거나, 끝까지 간 경우
	if (cnt == 3 || pos >= (N*H)) {
		if (check())
			return cnt;

		return INF;
	}

	// row = pos/col_cnt
	// col = pos%col_cnt
	int ret = INF;
	int row = pos / N;
	int col = pos % N;

	// 열이 마지막 위치가 아닌 경우에만 가로선을 놓을 수 있다.
	if (col != N - 1 && ladder[row][col] == 0 && ladder[row][col+1] == 0) {
		ladder[row][col] = RIGHT;
		ladder[row][col + 1] = LEFT;

		ret = min(ret, solve(pos + 2, cnt + 1));

		// 다시 복원 => 선택 안 한걸로 맞춰준다.
		ladder[row][col] = 0;
		ladder[row][col + 1] = 0;
	}

	ret = min(ret, solve(pos + 1, cnt));

	return ret;
}

int main() {
	cin >> N >> M >> H;
	memset(ladder, 0, sizeof(ladder));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		// 인덱스를 맞춰주기 위함
		ladder[a - 1][b - 1] = RIGHT;
		ladder[a - 1][b] = LEFT;
	}

	int ans = solve(0, 0);
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}