#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

vector<int> a[100001];	// ���� ����Ʈ
bool check[100001];
set<int> connectedNodes[100001];	// �� ������ ������ ������ ������

void dfs(int node) {
	check[node] = true;
	
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];

		if (!check[next]) 
			dfs(next);
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;

		// ���� �׽�Ʈ ���̽� �� ����ߴ� �͵� �ٽ� �ʱ�ȭ!
		for (int i = 1; i <= N; i++) {
			a[i].clear();
			connectedNodes[i].clear();
		}
			
		for (int i = 0; i < M; i++) {
			int u, v;

			cin >> u >> v;

			a[u].push_back(v);
		}

		for (int node = 1; node <= N; node++) {
			memset(check, false, sizeof(check));

			dfs(node);

			// �ش� �������� �ٸ� �������� �� �͵�� ���� �͵� insert!
			for (int i = 1; i <= N; i++) {
				if (check[i]) {
					connectedNodes[node].insert(i);
					connectedNodes[i].insert(node);
				}
			}
		}

		int cnt = 0;
		vector<int> results;

		for (int node = 1; node <= N; node++) {
			if (connectedNodes[node].size() == N) {
				cnt++;
				results.push_back(node);
			}
		}

		cout << '#' << t << ' ' << cnt << '\n';
		
		for (int i = 0; i < results.size(); i++) {
			cout << results[i] << ' ';
		}

		cout << '\n';
	}

	return 0;
}