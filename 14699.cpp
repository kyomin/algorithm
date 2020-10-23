#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 5001;

int dp[MAX];	// dp[i] : i 쉼터에서 출발했을 때 거치는 최대 쉼터 개수
vector<pair<int, int>> nodes;	// first : node, second : height
vector<int> a[MAX];	// 인접 리스트

// 높이 기준 내림차순 정렬
bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second > p2.second)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	// 높이 정보 담기
	for (int n = 1; n <= N; n++) {
		int h;
		cin >> h;

		nodes.push_back(make_pair(n, h));
	}

	sort(nodes.begin(), nodes.end(), comp);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		a[v].push_back(u);
		a[u].push_back(v);
	}

	// 가장 높이 위치한 노드부터 내려오면서 처리한다.
	// 왜냐면 가장 높은 곳에선 더 나아갈 수 없으므로 최소를 갖기 때문이다.
	for (int i = 0; i < N; i++) {
		int max = 0;
		int node = nodes[i].first;
		
		for (int j = 0; j < a[node].size(); j++) {
			int connected_node = a[node][j];

			if (dp[connected_node] > max)
				max = dp[connected_node];
		}
		
		dp[node] = max + 1;	// +1은 자기 자신
	}

	for (int node = 1; node <= N; node++)
		cout << dp[node] << '\n';

	return 0;
}