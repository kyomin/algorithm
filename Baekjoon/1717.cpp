#include <iostream>

using namespace std;

int parent[1000001];

// x�� ���� ������ root ��带 ��ȯ
int Find(int x) {
	// root�� ��� x�� ��ȯ
	if (x == parent[x]) {
		return x;
	}
	else {
		// �ƴϸ� root�� ã�ư�
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

	// �ʱ⿡�� �ڱ� �ڽ��� �θ�� �����Ѵ�.
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		int command, a, b;
		cin >> command >> a >> b;

		// �������� ���
		if (command == 0) {
			Union(a, b);
		}
		else {
			// �����ִ� ������ root�� ���ٸ� ���� ���տ� �����ִٴ� ���̴�.
			if (Find(a) == Find(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}