#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v, w;
};

int parent[10001];
Edge e[100001];

// ������ ����ġ �������� �������� ����
bool comp(const Edge &edge1, const Edge &edge2) {
	if (edge1.w < edge2.w)
		return true;
	else
		return false;
}

// Find(x) : x�� ���� ������ root ��带 ��ȯ
int Find(int x) {
	// root�� ��� x�� ��ȯ
	if (x == parent[x])
		return x;

	// �ƴϸ� root�� ã�ư�
	int p = Find(parent[x]);
	parent[x] = p;

	return p;
}

// Union(x, y) : x���ҿ� y���Ҹ� �սô� �Լ��� y�� root ��带 x�� �Ѵ�.
bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;

		return true;
	}

	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	// ���Ͽ� ���ε� �迭 parent �ϴ� �ڱ� �ڽ��� root�� �ʱ�ȭ
	for (int n = 1; n <= N; n++)
		parent[n] = n;

	// ���� ���� �Է� ����
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		e[i] = { a, b, c };
	}

	// ������ ����ġ �������� �������� ����
	sort(e, e + M, comp);

	int result = 0;		// ����ġ ��
	int cnt = 0;		// ���� ���� ��
	int idx = 0;		// ���� �ε���

	while (true) {
		if (Union(e[idx].u, e[idx].v)) {
			result += e[idx].w;
			cnt++;

			// N-1���� ������ ������ �۾� ��!
			if (cnt == N - 1)
				break;
		}

		idx++;
	}

	cout << result << '\n';

	return 0;
}