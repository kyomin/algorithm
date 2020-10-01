#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int curPoint;		// 해당 영화를 위로 올릴 때의 위치를 가리킨다.
vector<int> arr;		// 크기는 N+M이 된다.
vector<int> idx;		// 해당 영화의 인덱스를 담는다.
vector<int> tree;	// 배열 arr에 대응하는 세그먼트 트리
long long size, tree_size, h;


// 세그먼트 트리의 전체 크기 구하기
void calc_size() {
	h = (long long)ceil(log2(N + M));

	tree_size = (1 << (h + 1));

	tree.resize(tree_size + 1);
}


// 세그먼트 트리 초기화
long long init(int node, int start, int end) {
	// 단말 노드라면
	if (start == end)
		return tree[node] = arr[start];

	long long mid = (start + end) / 2;

	return tree[node] = (
		init(node * 2, start, mid) +
		init(node * 2 + 1, mid + 1, end)
		);
}


// 구간 합 구하는 쿼리
long long query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	// 구간 밖이라면(전혀 안 겹침)
	if (R < nodeL || nodeR < L)
		return 0;

	// 구간 내라면(완전히 포함됨)
	if (L <= nodeL && nodeR <= R)
		return tree[nodeNum];	// 통째로 자기 자신 값 반환

	int mid = (nodeL + nodeR) / 2;

	return (
		query(L, R, nodeNum * 2, nodeL, mid) +
		query(L, R, nodeNum * 2 + 1, mid + 1, nodeR)
		);
}


// 값의 변경 처리. i번째 원소를 val로 갱신! => 그 차이(diff)만큼 더해준다.
void update(int node, int start, int end, int index, long long diff) {
	// start와 end 사이에 바꾸려는 인덱스가 없다면
	if (!(start <= index && index <= end))
		return;	// 함수 종료

	// 변경한 크기만큼 더해 준다.
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

			update(1, 0, M + N - 1, idx[movie], -1);	// 해당 영화가 위로 올려지므로 1 -> 0이 된다.
			update(1, 0, M + N - 1, curPoint, 1);		// 해당 영화고 옮겨진 곳이 채워지므로 0 -> 1이 된다.

			idx[movie] = curPoint;	// 해당 영화의 위치(인덱스) 변화!
			curPoint--;
		}

		cout << '\n';

		arr.clear();
		idx.clear();
		tree.clear();
	}

	return 0;
}