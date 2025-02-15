#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	int pre[32000] = { 0, };	// 선행자의 개수
	vector<int> suc[32000];	// 후행자 목록 리스트
	vector<int> start_node;	// 시작 노드들을 담는다.

	cin >> N >> K;

	// 연결 정보 입력
	for (int i = 0; i < K; i++) {
		int u, v;
		cin >> u >> v;

		suc[u - 1].push_back(v - 1);
		pre[v - 1]++;
	}

	// 정답을 줄줄이 담을 것이다.
	vector<int> result;
	deque<int> Q;

	// 선행자가 하나도 없는 첫 노드 먼저 큐에 push!
	for (int i = 0; i < N; i++)
		if (pre[i] == 0)
			Q.push_front(i);

	// 모든 노드를 돌아 큐가 빌 때까지!
	while (!Q.empty()) {
		int  u = Q.front();
		Q.pop_front();

		// 결과에 순서대로 push!
		result.push_back(u);

		for (auto next : suc[u]) {
			--pre[next];

			// 선행자가 이제 없다면
			if (pre[next] == 0)
				// 그리고 큐에 넣어져서 해당 노드의 작업 진행!
				Q.push_front(next);
		}
	}

	// 출력 과정!
	int len = result.size();

	for (int i = 0; i < len; i++)
		cout << result[i] + 1 << ' ';

	cout << '\n';

	return 0;
}