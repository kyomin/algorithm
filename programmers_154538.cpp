#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
	vector<int> visit(1000001, 0);	// 1 ≤ x ≤ y ≤ 1,000,000

	queue<int> q;
	q.push(x);

	// 1차원에서의 BFS 탐색
	while (!q.empty()) {
		int cur = q.front();

		q.pop();

		// y가 되었다면
		if (cur == y)
			return visit[cur];

		// 3가지 연산
		int dx[3] = { cur + n, cur * 2, cur * 3 };

		for (int k = 0; k < 3; k++) {
			int nx = dx[k];

			// 범위 체크
			if (nx > y) continue;

			// 방문 체크
			if (visit[nx] != 0) continue;

			visit[nx] = visit[cur] + 1;

			q.push(nx);
		}
	}

	// 위의 탐색에서 걸리지 않았다면 y로 만들 수 없으므로
	return -1;
}