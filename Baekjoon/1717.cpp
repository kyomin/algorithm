#include <iostream>

using namespace std;

int parent[1000001];

// x로 들어온 원소의 root 노드를 반환
int Find(int x) {
	// root인 경우 x를 반환
	if (x == parent[x]) {
		return x;
	}
	else {
		// 아니면 root를 찾아감
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

	int n, m;
	cin >> n >> m;

	// 초기에는 자기 자신을 부모로 설정한다.
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		int command, a, b;
		cin >> command >> a >> b;

		// 합집합인 경우
		if (command == 0) {
			Union(a, b);
		}
		else {
			// 속해있는 집합의 root가 같다면 같은 집합에 속해있다는 것이다.
			if (Find(a) == Find(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}