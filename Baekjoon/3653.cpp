#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int curPoint;		// �ش� ��ȭ�� ���� �ø� ���� ��ġ�� ����Ų��.
vector<int> arr;		// ũ��� N+M�� �ȴ�.
vector<int> idx;		// �ش� ��ȭ�� �ε����� ��´�.
vector<int> tree;	// �迭 arr�� �����ϴ� ���׸�Ʈ Ʈ��
long long size, tree_size, h;


// ���׸�Ʈ Ʈ���� ��ü ũ�� ���ϱ�
void calc_size() {
	h = (long long)ceil(log2(N + M));

	tree_size = (1 << (h + 1));

	tree.resize(tree_size + 1);
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


// ���� �� ���ϴ� ����
long long query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	// ���� ���̶��(���� �� ��ħ)
	if (R < nodeL || nodeR < L)
		return 0;

	// ���� �����(������ ���Ե�)
	if (L <= nodeL && nodeR <= R)
		return tree[nodeNum];	// ��°�� �ڱ� �ڽ� �� ��ȯ

	int mid = (nodeL + nodeR) / 2;

	return (
		query(L, R, nodeNum * 2, nodeL, mid) +
		query(L, R, nodeNum * 2 + 1, mid + 1, nodeR)
		);
}


// ���� ���� ó��. i��° ���Ҹ� val�� ����! => �� ����(diff)��ŭ �����ش�.
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

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		curPoint = M - 1;

		arr.resize(N + M);
		idx.resize(N);

		for (int i = 0; i < M; i++)
			arr[i] = 0;

		for (int i = M, j = 0; i < M + N; i++, j++) {
			arr[i] = 1;
			idx[j] = i;
		}

		calc_size();
		init(1, 0, M + N - 1);

		for (int m = 0; m < M; m++) {
			int movie;
			cin >> movie;
			movie--;

			cout << query(0, idx[movie] - 1, 1, 0, M + N - 1) << ' ';

			update(1, 0, M + N - 1, idx[movie], -1);	// �ش� ��ȭ�� ���� �÷����Ƿ� 1 -> 0�� �ȴ�.
			update(1, 0, M + N - 1, curPoint, 1);		// �ش� ��ȭ�� �Ű��� ���� ä�����Ƿ� 0 -> 1�� �ȴ�.

			idx[movie] = curPoint;	// �ش� ��ȭ�� ��ġ(�ε���) ��ȭ!
			curPoint--;
		}

		cout << '\n';

		arr.clear();
		idx.clear();
		tree.clear();
	}

	return 0;
}