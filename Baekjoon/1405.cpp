#include <iostream>

using namespace std;

const int MAX = 29;		// N�� �ִ� 14�̹Ƿ�
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int N;
double percent[4];
bool visit[MAX][MAX];

double dfs(int r, int c, int cnt) {
	// N�� ��ŭ �̵� �Ϸ��� ��� 1�� return�����ν� Ȯ�� ������ �����Ѵ�.
	if (cnt == N)
		return 1.0;

	visit[r][c] = true;
	double result = 0.0;

	for (int k = 0; k < 4; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];

		// �湮�� ���� �ٽ� ���� �Ǹ� �̵���ΰ� �ܼ����� ���� ���̴�.
		if (visit[nr][nc])
			continue;

		result += percent[k] * dfs(nr, nc, cnt + 1);
	}

	// ���� Ž�� �Ϸ� ��, �ٸ� �������� �� �� �ְ� �ٽ� �湮 üũ�� ������ �ش�.
	visit[r][c] = false;

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;

		percent[i] = (a / 100.0);
	}

	// N�� �ִ� 14�� ���� ����� �߰����� �κ��� ���� �����Ѵ�.
	double probability = dfs(14, 14, 0);

	cout.precision(10);
	cout << fixed << probability << '\n';

	return 0;
}