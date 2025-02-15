#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 5001;

int dp[MAX];	// dp[i] : i ���Ϳ��� ������� �� ��ġ�� �ִ� ���� ����
vector<pair<int, int>> nodes;	// first : node, second : height
vector<int> a[MAX];	// ���� ����Ʈ

// ���� ���� �������� ����
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

	// ���� ���� ���
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

	// ���� ���� ��ġ�� ������ �������鼭 ó���Ѵ�.
	// �ֳĸ� ���� ���� ������ �� ���ư� �� �����Ƿ� �ּҸ� ���� �����̴�.
	for (int i = 0; i < N; i++) {
		int max = 0;
		int node = nodes[i].first;
		
		for (int j = 0; j < a[node].size(); j++) {
			int connected_node = a[node][j];

			if (dp[connected_node] > max)
				max = dp[connected_node];
		}
		
		dp[node] = max + 1;	// +1�� �ڱ� �ڽ�
	}

	for (int node = 1; node <= N; node++)
		cout << dp[node] << '\n';

	return 0;
}