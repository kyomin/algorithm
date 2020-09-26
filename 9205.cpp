#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// ���� ���� �� ���� ��� ��
const int INF = 1000000000;

int dist[103][103];

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		pair<int, int> position[103];	// �� ������ ��ǥ
		cin >> n;

		memset(dist, 0, sizeof(dist));

		// dist �迭 �ʱ�ȭ
		// 1 : home, n+2 : ������
		for (int i = 1; i <= (n + 2); i++)
			for (int j = 1; j <= (n + 2); j++)
				dist[i][j] = (i == j) ? 0 : INF;

		
		// ���� ������ �Է� �ޱ�
		for (int node = 1; node <= (n + 2); node++) {
			int x, y;
			cin >> x >> y;

			position[node] = make_pair(x, y);

			// ������� �Էµ� �ٸ� ����� �Ÿ� ���Ͽ� ���� ����
			for (int prevNode = 1; prevNode < node; prevNode++) {
				// �Ÿ� ���
				int distance = abs(position[prevNode].first - x) + abs(position[prevNode].second - y);

				// 1000 ������ �Ÿ��� ���� ���´�
				if(distance <= 1000)
					dist[prevNode][node] = min(dist[prevNode][node], distance);
			}
		}

		// �÷��̵� �ͼ� �˰��� ����
		for (int k = 1; k <= (n + 2); k++)
			for (int i = 1; i <= (n + 2); i++)
				for (int j = 1; j <= (n + 2); j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		// ���������� �� �� �ִ� ���
		if (dist[1][n + 2] != INF)
			cout << "happy" << '\n';
		else
			cout << "sad" << '\n';
	}

	return 0;
}