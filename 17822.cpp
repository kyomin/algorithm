#include <iostream>

using namespace std;

const int MAX = 51;		// 1부터 인덱스를 맞추기 위함

int N, M, T;
int X, D, K;
int map[MAX][MAX];
int temp[MAX][MAX];
int ans;

void copyMapToTemp() {
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			temp[r][c] = map[r][c];
}

void copyTempToMap() {
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			map[r][c] = temp[r][c];
}

void move(int X, int D, int K) {
	cin >> X >> D >> K;

	for (int i = 1; i <= N; i++) {
		// X의 배수인 원판이라면
		if (i%X == 0) {
			// 그리고 시계 방향이라면
			if (D == 0) {
				// 시계 방향으로 K칸 만큼 회전!
				for (int k = 0; k < K; k++) {
					int tmp = map[i][M];

					for (int idx = M; idx >= 2; idx--)
						map[i][idx] = map[i][idx - 1];

					map[i][1] = tmp;
				}
			}
			else if(D == 1) {	// 반시계 방향 처리!
				for (int k = 0; k < K; k++) {
					int tmp = map[i][1];

					for (int idx = 1; idx <= M - 1; idx++)
						map[i][idx] = map[i][idx + 1];

					map[i][M] = tmp;
				}
			}
		}
	}
}

bool remove() {
	// 제거할 것이 하나라도 생기면 true로 만들어 주기
	bool flag = false;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			// 이미 제거가 된 경우
			if (temp[r][c] == 0) continue;

			// 양 옆
			int idx1 = c - 1;
			int idx2 = c + 1;

			// 양 끝 처리
			if (idx1 == 0) idx1 = M;
			if (idx2 == M + 1) idx2 = 1;

			// 첫 레코드라면
			if (r == 1) {
				// 자기 왼쪽 놈이 같은 수라면
				if (map[r][c] == map[r][idx1]) {
					temp[r][c] = 0;	// 자기 자신 지우고
					temp[r][idx1] = 0;	// 왼쪽 넘 지워준다.
					flag = true;	// 하나라도 지웠으니
				}
				else if (map[r][c] == map[r][idx2]) {	
					// 자기 오른쪽 놈이 같은 수라면
					temp[r][c] = 0;
					temp[r][idx2] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r + 1][c]) {
					// 자기 밑에 넘이 같은 수라면
					temp[r][c] = 0;
					temp[r + 1][c] = 0;
					flag = true;
				}
			}
			else if (r == N) {		// 마지막 레코드라면
				// 자기 왼쪽 넘
				if (map[r][c] == map[r][idx1]) {
					temp[r][c] = 0;	
					temp[r][idx1] = 0;	
					flag = true;
				}
				else if (map[r][c] == map[r][idx2]) {
					// 자기 오른쪽 놈이 같은 수라면
					temp[r][c] = 0;
					temp[r][idx2] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r - 1][c]) {
					// 자기 위에 넘이 같은 수라면
					temp[r][c] = 0;
					temp[r - 1][c] = 0;
					flag = true;
				}
			}
			else {		// 처음도, 마지막도 아닌 레코드라면
				// 자기 왼쪽 넘
				if (map[r][c] == map[r][idx1]) {
					temp[r][c] = 0;
					temp[r][idx1] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r][idx2]) {
					// 자기 오른쪽 놈이 같은 수라면
					temp[r][c] = 0;
					temp[r][idx2] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r - 1][c]) {
					// 자기 위에 넘이 같은 수라면
					temp[r][c] = 0;
					temp[r - 1][c] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r + 1][c]) {
					// 자기 밑에 넘이 같은 수라면
					temp[r][c] = 0;
					temp[r + 1][c] = 0;
					flag = true;
				}
			}
		}
	}

	if (flag) return true;
	else return false;
}

// 제거된 것이 없으면 평균 기준으로 값 갱신 !
void solve() {
	int cnt = 0;
	int sum = 0;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (temp[r][c] != 0) {
				sum += temp[r][c];
				cnt++;
			}
		}
	}

	double avg = (double)sum / cnt;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (temp[r][c] > avg)
				temp[r][c]--;
			else if (temp[r][c] < avg && temp[r][c] > 0)
				temp[r][c]++;
		}
	}
}

void countAnswer() {
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			if (map[r][c] != 0)
				ans += map[r][c];

	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> T;

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			cin >> map[r][c];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	for (int t = 0; t < T; t++) {
		move(X, D, K);
		copyMapToTemp();

		if (!remove()) solve();

		copyTempToMap();
	}

	countAnswer();

	return 0;
}