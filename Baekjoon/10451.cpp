#include <iostream>
#include <vector>

using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];

		// 아직 방문하지 않은 노드라면
		if (check[next] == false)
			dfs(next);
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		for (int j = 1; j < 1001; j++) {
			check[j] = false;
			a[j].clear();
		}

		int N;
		cin >> N;

		int *A = new int[N + 1];

		for (int j = 1; j <= N; j++) {
			int n;
			cin >> n;
			A[j] = n;
		}

		// 인접 리스트 초기화
		for (int j = 1; j <= N; j++)
			a[j].push_back(A[j]);

		int cycle = 0;

		// 정점만큼 돌면서
		for (int j = 1; j <= N; j++) {
			// 아직 방문하지 않았으면
			if (check[j] == false) {
				// 탐색을 시킨다.
				dfs(j);
				cycle += 1;
			}
		}

		cout << cycle << endl;
	}

	return 0;
}