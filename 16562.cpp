#include <iostream>
#include <algorithm>

using namespace std;

int parent[10001];
int cost[10001];		// �� ���(ģ��)���� ���
int min_cost[10001];	// �ش� ���� �������� �ּ� ���
bool visit[10001];		// �ش� ������ �湮�ߴ°�?

int Find(int x) {
	// root�� ��� x�� ��ȯ
	if (x == parent[x])
		return x;
	else {
		int p = Find(parent[x]);
		parent[x] = p;

		return p;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y)
		parent[y] = x;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		parent[i] = i;
	}

	// ģ�� ��Ʈ��ũ �����
	for (int m = 0; m < M; m++) {
		int f1, f2;
		cin >> f1 >> f2;

		Union(f1, f2);
	}

	for (int n = 1; n <= N; n++) {
		int root_node = Find(n);

		if (!visit[root_node]) {
			min_cost[root_node] = cost[n];
			visit[root_node] = true;
		}
		else {
			min_cost[root_node] = min(min_cost[root_node], cost[n]);
		}
	}

	int ans = 0;

	for (int n = 1; n <= N; n++) {
		ans += min_cost[n];
	}

	if (ans <= K) 
		cout << ans << '\n';
	else 
		cout << "Oh no" << '\n';

	return 0;
}