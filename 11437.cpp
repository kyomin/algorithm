#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 18;	// roundup log(2, 100000)

int N, M;
int parent[50000][MAX];	// parent[i][k] : i�� 2^k��° �θ�
int depth[50000];			// ������ ���� (��Ʈ�� ���̴� 0)
vector<int> adj[50000];	// ���� ����Ʈ

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// dfs�� Ʈ�� �����ϸ� parent[i][0], depth �迭 ä��
void makeTreeByDfs(int cur) {
	for (int next : adj[cur]) {
		if (depth[next] == -1) {
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1;
			makeTreeByDfs(next);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// Ʈ�� ���� �Է�
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;

		u--;
		v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// �迭 �ʱ�ȭ
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	depth[0] = 0;

	// Ʈ�� �����
	makeTreeByDfs(0);

	// parent �迭 ä��
	for (int j = 0; j < MAX - 1; j++)
		for (int i = 1; i < N; i++)	// 0�� ��Ʈ ����̹Ƿ� 1���� ����
			if (parent[i][j] != -1)	// �θ� ä���� �ִٸ� �θ��� �θ� ������ ä���
				parent[i][j + 1] = parent[parent[i][j]][j];

	// ���� �Է¹ޱ�
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		u--;
		v--;

		// depth[u] >= depth[v]�� �ǵ��� �ʿ信 ���� u, v�� ����!
		if (depth[u] < depth[v])
			swap(u, v);

		int diff = depth[u] - depth[v];

		// ���� ��(diff)�� ���ָ� u�� �̵���Ŵ
		for (int j = 0; diff; j++) {
			if (diff % 2)
				u = parent[u][j];

			diff /= 2;
		}

		// u�� v�� �ٸ��� ���ÿ� ���� ���̸�ŭ ���� �̵���Ŵ
		if (u != v) {
			// ���� 2^17, 2^16, .... , 2^2, 2^1, 1 ������ �õ�
			for (int j = MAX - 1; j >= 0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}

			// �������� �� ���� u, v�� �θ� �����Ƿ� �� �� �� �ø�
			u = parent[u][0];
		}

		// LCA ���
		cout << u + 1 << '\n';
	}

	return 0;
}