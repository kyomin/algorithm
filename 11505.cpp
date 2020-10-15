#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N, M, K;
long long arr[1000001];
long long *tree;
long long size, tree_size, h;

// ���׸�Ʈ Ʈ���� ��ü ũ�� ���ϱ�
void calc_size() {
	h = (long long)ceil(log2(N));
	tree_size = (1 << (h + 1));
	tree = new long long[tree_size + 1];
}

// ���׸�Ʈ Ʈ�� �ʱ�ȭ
long long init(int node, int start, int end) {
	// �ܸ� �����
	if (start == end)
		return tree[node] = arr[start] % 1000000007;

	long long mid = (start + end) / 2;

	return tree[node] = (
		init(node * 2, start, mid) % 1000000007 *
		init(node * 2 + 1, mid + 1, end) % 1000000007
		) % 1000000007;
}

// ���� �� ���ϱ�
long long mul(int L, int R, int nodeNum, int nodeL, int nodeR) {
	// ���� ���̶��(���� �� ��ħ)
	if (R < nodeL || nodeR < L)
		return 1;

	// ���� �����(������ ���Ե�)
	if (L <= nodeL && nodeR <= R) 
		// ��°�� �ڱ� �ڽ� �� ��ȯ
		return tree[nodeNum] % 1000000007;

	int mid = (nodeL + nodeR) / 2;

	return (
		mul(L, R, nodeNum * 2, nodeL, mid) % 1000000007 *
		mul(L, R, nodeNum * 2 + 1, mid + 1, nodeR) % 1000000007
		) % 1000000007;
}

// ���� ���� ó��. i��° ���Ҹ� val�� ����!
long long update(int node, int start, int end, int index, int val) {
	// start�� end ���̿� �ٲٷ��� �ε����� ���ٸ�
	if (!(start <= index && index <= end))
		return tree[node] % 1000000007;	// �Լ� ����

	if (start != end) {
		int mid = (start + end) / 2;

		return tree[node] = (
			(update(node * 2, start, mid, index, val) % 1000000007)*
			(update(node * 2 + 1, mid + 1, end, index, val) % 1000000007)
			) % 1000000007;
	}

	if (start == end) {
		tree[node] = val;

		return tree[node] % 1000000007;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	calc_size();
	init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;

		// update
		if (a == 1) {
			update(1, 0, N - 1, b - 1, c);
			arr[b - 1] = c;
		}
		else if (a == 2)
			cout << mul(b - 1, c - 1, 1, 0, N - 1) % 1000000007 << '\n';
	}

	return 0;
}