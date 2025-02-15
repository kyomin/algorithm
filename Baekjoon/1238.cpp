#include <iostream>
#include <algorithm>

using namespace std;

// ���� ���� �� ���� ��� ��
const int INF = 1000000000;

int dist[1001][1001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, X;
	cin >> N >> M >> X;

	// dist �迭 �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = (i == j) ? 0 : INF;

	// ���� ���� �Է� �ޱ�
	for (int m = 0; m < M; m++) {
		int a, b, c;
		cin >> a >> b >> c;

		dist[a][b] = min(dist[a][b], c);
	}

	// �÷��̵� �ͼ� �˰��� ����
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int result = 0;

	for (int i = 1; i <= N; i++) {
		if (i == X)
			continue;

		// X���� ���µ� �ɸ��� �ð� + X���� ���µ� �ɸ��� �ð�
		int time = dist[i][X] + dist[X][i];

		result = max(result, time);
	}

	cout << result << '\n';

	return 0;
}