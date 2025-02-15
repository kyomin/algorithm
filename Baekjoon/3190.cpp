#include <iostream>

using namespace std;

int D[100][100];
bool apple[100][100];

// 0 : ��, 1 : ��, 2 : ��, 3 : ��
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, K, L;

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			D[i][j] = -1;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;

		apple[x - 1][y - 1] = true;
	}

	int x = 0, y = 0;	// ó�� ��ǥ
	int dir = 1;	// ó���� ��������
	int len = 1;	// ù �� ���̴� 1
	D[x][y] = 0;
	int now = 0;

	cin >> L;

	for (int k = 0; k <= L; k++) {
		// �Ӹ��� �湮�� �� �ִ� �ִ� ĭ�� �����̴�.
		// ����� �� �����ϰ��� ������ �� �������� �� ��Ȳ���� �����Ű��
		// �׻� ������ ���� ���̴�.
		int t = N * N + 1;
		char ch;

		// ���� ����� ������ �� �ִٸ�
		if (k < L)
			cin >> t >> ch;

		while (now < t) {
			now += 1;
			// ���� ���ϴ� �������� ����.
			x += dx[dir];
			y += dy[dir];

			// ���� ���̶��!
			if (x < 0 || x >= N || y < 0 || y >= N) {
				cout << now << '\n';
				return 0;
			}

			// �Ӹ��� �ű� ���� ����� �ִٸ�
			if (apple[x][y]) {
				apple[x][y] = false;
				len += 1;
			}

			// �ڱ� ���� �浹�� �Ͼ�ٸ�
			if (D[x][y] != -1 && now - D[x][y] <= len) {
				cout << now << '\n';
				return 0;
			}

			D[x][y] = now;
		}

		if (ch == 'L')
			if (dir == 0)
				dir = 3;
			else
				dir -= 1;
		else
			if (dir == 3)
				dir = 0;
			else
				dir += 1;
	}

	return 0;
}