#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 절대 나올 수 없는 경로 값
const int INF = 1000000000;

int friends[301][301];
int N;

// first : 시작점, second : 끝점
vector<pair<int, int>> lines;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			friends[y][x] = (y == x) ? 0 : INF;

	// 인덱스를 1부터 시작하기 위함
	lines.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int start, end;
		cin >> start >> end;

		lines[i] = make_pair(start, end);
	}

	// 간선 정보 입력 받음
	for (int y = 1; y <= N; y++) {
		// 현재 파악하고자 하는 친구의 경계
		int boundaryLeft = lines[y].first;
		int boundaryRight = lines[y].second;

		for (int x = 1; x <= N; x++) {
			if (y == x)
				continue;

			int start = lines[x].first;
			int end = lines[x].second;

			// 현재 친구의 경계 내부에 있다면 친분은 항상 1이다.
			if ((start >= boundaryLeft && start <= boundaryRight) || (end >= boundaryLeft && end <= boundaryRight)
				|| (boundaryLeft >= start && boundaryLeft <= end) || (boundaryRight >= start && boundaryRight <= end)) {
				friends[y][x] = 1;
			}
		}
	}

	// 플로이드 와샬 알고리즘 적용
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);

	int Q;
	cin >> Q;

	for (int q = 0; q < Q; q++) {
		int A, B;
		cin >> A >> B;

		if (friends[A][B] == INF)
			cout << -1 << '\n';
		else
			cout << friends[A][B] << '\n';
	}

	return 0;
}