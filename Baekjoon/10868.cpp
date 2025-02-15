#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;

long long arr[100001];
long long *min_tree;
long long tree_size;

void calc_size() {
	int h = (int)ceil(log2(N));
	tree_size = (1 << (h + 1));
	min_tree = new long long[tree_size + 1];
}

// ���� �ּڰ��� ��� ���׸�Ʈ Ʈ�� �ʱ�ȭ
long long init_min(int node, int start, int end) {
	// �ܸ� �����
	if (start == end)
		return min_tree[node] = arr[start];

	int mid = (start + end) / 2;

	return min_tree[node] =
		min(
			init_min(node * 2, start, mid),
			init_min(node * 2 + 1, mid + 1, end)
		);
}


// ���� �ּڰ��� ���Ѵ�.
long long search_min(int L, int R, int nodeNum, int nodeL, int nodeR) {
	// ���� ���̶��(���� �� ��ģ�ٸ�)
	if (R < nodeL || nodeR < L)
		return 1000000001;	// ���� ū ���� ������ �ּڰ��� ���� ���� �ʴ´�.

	// ������ ���ԵǴ� ���� �����
	if (L <= nodeL && nodeR <= R)
		return min_tree[nodeNum];

	int mid = (nodeL + nodeR) / 2;

	return min(
		search_min(L, R, nodeNum * 2, nodeL, mid),
		search_min(L, R, nodeNum * 2 + 1, mid + 1, nodeR)
	);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	calc_size();

	init_min(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		cout << search_min(a - 1, b - 1, 1, 0, N - 1) << '\n';
	}

	return 0;
}