#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
long long arr[100001];
long long *max_tree;
long long *min_tree;
long long tree_size;

void calc_size() {
	int h = (int)ceil(log2(N));

	tree_size = (1 << (h + 1));

	max_tree = new long long[tree_size + 1];
	min_tree = new long long[tree_size + 1];
}

// 구간 최댓값을 담는 세그먼트 트리 초기화
long long init_max(int node, int start, int end) {
	// 단말 노드라면
	if (start == end)
		return max_tree[node] = arr[start];

	int mid = (start + end) / 2;

	return max_tree[node] =
		max(
			init_max(node * 2, start, mid),
			init_max(node * 2 + 1, mid + 1, end)
		);
}

// 구간 최솟값을 담는 세그먼트 트리 초기화
long long init_min(int node, int start, int end) {
	// 단말 노드라면
	if (start == end)
		return min_tree[node] = arr[start];

	int mid = (start + end) / 2;

	return min_tree[node] =
		min(
			init_min(node * 2, start, mid),
			init_min(node * 2 + 1, mid + 1, end)
		);
}

// 구간 최댓값을 구한다
long long search_max(int L, int R, int nodeNum, int nodeL, int nodeR) {
	// 구간 밖이라면(전혀 안 겹친다면)
	if (R < nodeL || nodeR < L)
		return 0;

	// 완전히 포함되는 구간 내라면
	if (L <= nodeL && nodeR <= R)
		return max_tree[nodeNum];

	int mid = (nodeL + nodeR) / 2;

	return max(
		search_max(L, R, nodeNum * 2, nodeL, mid),
		search_max(L, R, nodeNum * 2 + 1, mid + 1, nodeR)
	);
}

// 구간 최솟값을 구한다.
long long search_min(int L, int R, int nodeNum, int nodeL, int nodeR) {
	// 구간 밖이라면(전혀 안 겹친다면)
	if (R < nodeL || nodeR < L)
		// 가장 큰 값을 리턴해 최솟값에 영향 주지 않는다.
		return 1000000001;

	// 완전히 포함되는 구간 내라면
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

	init_max(1, 0, N - 1);
	init_min(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		cout << search_min(a - 1, b - 1, 1, 0, N - 1) << ' ' << search_max(a - 1, b - 1, 1, 0, N - 1);

		cout << '\n';
	}

	return 0;
}