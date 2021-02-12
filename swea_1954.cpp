#include <iostream>

using namespace std;

const int MAX = 10;
const int dr[] = { 0, 1, 0, -1 };
const int dc[] = { 1, 0, -1, 0 };

int map[MAX][MAX];
int N;

void init() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			map[r][c] = 0;
}

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		init();
		
		int cur_dir = 0;
		int cur_r = 0;
		int cur_c = 0;
		int cur_num = 1;

		while (true) {
			// 배열에 현재 숫자를 표기
			map[cur_r][cur_c] = cur_num;
			cur_num++;

			int next_r = cur_r + dr[cur_dir];
			int next_c = cur_c + dc[cur_dir];
			
			if (!isInside(next_r, next_c)) {	// 만약 범위를 벗어난 경우라면 방향을 바꿔본다.
				cur_dir += 1;

				// 북쪽 방향(3) 다음이라면 다시 동쪽 방향(0)으로 초기화
				if (cur_dir == 4)
					cur_dir = 0;

				// 만약, 방향을 바꿨는데도 다음으로 갈 수 없는 경우라면 숫자를 다 채운 경우이다.
				next_r = cur_r + dr[cur_dir];
				next_c = cur_c + dc[cur_dir];

				if (map[next_r][next_c] != 0)
					break;

				cur_r = next_r;
				cur_c = next_c;
			}
			else if (map[next_r][next_c] != 0) {	// 이미 표시가 된 경우라면 방향을 바꿔본다.
				cur_dir += 1;

				// 북쪽 방향(3) 다음이라면 다시 동쪽 방향(0)으로 초기화
				if (cur_dir == 4)
					cur_dir = 0;

				// 만약, 방향을 바꿨는데도 다음으로 갈 수 없는 경우라면 숫자를 다 채운 경우이다.
				next_r = cur_r + dr[cur_dir];
				next_c = cur_c + dc[cur_dir];

				if (map[next_r][next_c] != 0)
					break;

				cur_r = next_r;
				cur_c = next_c;
			}
			else {		// 그냥 다음으로 가도 되는 경우라면 간다.
				cur_r = next_r;
				cur_c = next_c;
			}
		}

		cout << '#' << t << '\n';
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N - 1; c++)
				cout << map[r][c] << ' ';

			cout << map[r][N - 1] << '\n';
		}
	}

	return 0;
}