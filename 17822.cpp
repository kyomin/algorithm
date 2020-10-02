#include <iostream>

using namespace std;

const int MAX = 51;		// 1���� �ε����� ���߱� ����

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
		// X�� ����� �����̶��
		if (i%X == 0) {
			// �׸��� �ð� �����̶��
			if (D == 0) {
				// �ð� �������� Kĭ ��ŭ ȸ��!
				for (int k = 0; k < K; k++) {
					int tmp = map[i][M];

					for (int idx = M; idx >= 2; idx--)
						map[i][idx] = map[i][idx - 1];

					map[i][1] = tmp;
				}
			}
			else if(D == 1) {	// �ݽð� ���� ó��!
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
	// ������ ���� �ϳ��� ����� true�� ����� �ֱ�
	bool flag = false;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			// �̹� ���Ű� �� ���
			if (temp[r][c] == 0) continue;

			// �� ��
			int idx1 = c - 1;
			int idx2 = c + 1;

			// �� �� ó��
			if (idx1 == 0) idx1 = M;
			if (idx2 == M + 1) idx2 = 1;

			// ù ���ڵ���
			if (r == 1) {
				// �ڱ� ���� ���� ���� �����
				if (map[r][c] == map[r][idx1]) {
					temp[r][c] = 0;	// �ڱ� �ڽ� �����
					temp[r][idx1] = 0;	// ���� �� �����ش�.
					flag = true;	// �ϳ��� ��������
				}
				else if (map[r][c] == map[r][idx2]) {	
					// �ڱ� ������ ���� ���� �����
					temp[r][c] = 0;
					temp[r][idx2] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r + 1][c]) {
					// �ڱ� �ؿ� ���� ���� �����
					temp[r][c] = 0;
					temp[r + 1][c] = 0;
					flag = true;
				}
			}
			else if (r == N) {		// ������ ���ڵ���
				// �ڱ� ���� ��
				if (map[r][c] == map[r][idx1]) {
					temp[r][c] = 0;	
					temp[r][idx1] = 0;	
					flag = true;
				}
				else if (map[r][c] == map[r][idx2]) {
					// �ڱ� ������ ���� ���� �����
					temp[r][c] = 0;
					temp[r][idx2] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r - 1][c]) {
					// �ڱ� ���� ���� ���� �����
					temp[r][c] = 0;
					temp[r - 1][c] = 0;
					flag = true;
				}
			}
			else {		// ó����, �������� �ƴ� ���ڵ���
				// �ڱ� ���� ��
				if (map[r][c] == map[r][idx1]) {
					temp[r][c] = 0;
					temp[r][idx1] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r][idx2]) {
					// �ڱ� ������ ���� ���� �����
					temp[r][c] = 0;
					temp[r][idx2] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r - 1][c]) {
					// �ڱ� ���� ���� ���� �����
					temp[r][c] = 0;
					temp[r - 1][c] = 0;
					flag = true;
				}
				else if (map[r][c] == map[r + 1][c]) {
					// �ڱ� �ؿ� ���� ���� �����
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

// ���ŵ� ���� ������ ��� �������� �� ���� !
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