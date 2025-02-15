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
		return tree[node] = arr[start];

	long long mid = (start + end) / 2;

	return tree[node] = (
		init(node * 2, start, mid) +
		init(node * 2 + 1, mid + 1, end)
		);
}

// ���� �� ���ϱ�
long long sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	// ���� ���̶��(���� �� ��ħ)
	if (R < nodeL || nodeR < L)
		return 0;

	// ���� �����(������ ���Ե�)
	if (L <= nodeL && nodeR <= R)
		// ��°�� �ڱ� �ڽ� �� ��ȯ
		return tree[nodeNum];

	int mid = (nodeL + nodeR) / 2;

	return (
		sum(L, R, nodeNum * 2, nodeL, mid) +
		sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR)
		);
}

// ���� ���� ó��. i��° ���Ҹ� val�� ����!
void update(int node, int start, int end, int index, long long diff) {
	// start�� end ���̿� �ٲٷ��� �ε����� ���ٸ�
	if (!(start <= index && index <= end))
		return;	// �Լ� ����

	// ������ ũ�⸸ŭ ���� �ش�.
	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;

		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
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
			update(1, 0, N - 1, b - 1, c - arr[b - 1]);

			arr[b - 1] = c;
		}
		else if (a == 2)
			cout << sum(b - 1, c - 1, 1, 0, N - 1) << '\n';
	}

	return 0;
}