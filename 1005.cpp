#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// 테스트 케이스의 수
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;	// 노드의 개수
		int K;	// 연결 정보의 개수
		int W;	// 해답을 알고자 하는 건물 번호
		int time[1000];	// 각 노드(건물)의 작업 시간
		int pre[1000] = { 0, };	// 선행자의 개수
		vector<int> suc[10000];	// 후행자의 목록 리스트(인접 리스트)

		cin >> N >> K;

		// 작업 시간 정보 입력
		for (int i = 0; i < N; i++)
			cin >> time[i];

		// 연결 정보 입력
		for (int i = 0; i < K; i++) {
			int u, v;
			cin >> u >> v;
			// 인덱스를 맞춰주기 위해 -1을 취한다.
			suc[u - 1].push_back(v - 1);
			pre[v - 1]++;
		}

		cin >> W;	// 타겟 노드 번호 입력
		W--;	// 인덱스를 맞춰주기 위함!

		// 해당 건물을 짓기 시작하는 데 걸리는 최소 시간을 담는다
		int result[1000] = { 0, };

		queue<int> Q;

		// 선행자가 하나도 없는 노드들을 먼저 큐에 push
		for (int i = 0; i < N; i++)
			if (pre[i] == 0)
				Q.push(i);

		// W번 건물의 선행자가 하나도 없을 때까지!
		while (pre[W] > 0) {
			int u = Q.front();
			Q.pop();

			// 모든 후행자 건물의 최소 건설시작시간을 갱신!
			for (auto next : suc[u]) {
				result[next] = max(result[next], result[u] + time[u]);

				// 작업이 끝났으면 선행자 개수를 하나 줄인다.
				--pre[next];

				// 만일 현재 노드가 다음과 연결되어 있는 마지막 선행 노드라면
				if (pre[next] == 0)
					Q.push(next); // 다음 과정으로 진행하기 위함!
			}
		}

		// 최종 결과에 목표 건물을 짓는 데 걸리는 시간도 더해야 한다.
		cout << result[W] + time[W] << '\n';
	}

	return 0;
}