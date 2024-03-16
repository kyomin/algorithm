#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
	vector<int> visit(1000001, 0);	// 1 �� x �� y �� 1,000,000

	queue<int> q;
	q.push(x);

	// 1���������� BFS Ž��
	while (!q.empty()) {
		int cur = q.front();

		q.pop();

		// y�� �Ǿ��ٸ�
		if (cur == y)
			return visit[cur];

		// 3���� ����
		int dx[3] = { cur + n, cur * 2, cur * 3 };

		for (int k = 0; k < 3; k++) {
			int nx = dx[k];

			// ���� üũ
			if (nx > y) continue;

			// �湮 üũ
			if (visit[nx] != 0) continue;

			visit[nx] = visit[cur] + 1;

			q.push(nx);
		}
	}

	// ���� Ž������ �ɸ��� �ʾҴٸ� y�� ���� �� �����Ƿ�
	return -1;
}