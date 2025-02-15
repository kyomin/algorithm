#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v, w;
};

int parent[10001];
Edge e[100001];

// 간선을 가중치 기준으로 오름차순 정렬
bool comp(const Edge &edge1, const Edge &edge2) {
	if (edge1.w < edge2.w)
		return true;
	else
		return false;
}

// Find(x) : x로 들어온 원소의 root 노드를 반환
int Find(int x) {
	// root인 경우 x를 반환
	if (x == parent[x])
		return x;

	// 아니면 root를 찾아감
	int p = Find(parent[x]);
	parent[x] = p;

	return p;
}

// Union(x, y) : x원소와 y원소를 합시는 함수로 y의 root 노드를 x로 한다.
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

	// 유니온 파인드 배열 parent 일단 자기 자신을 root로 초기화
	for (int n = 1; n <= N; n++)
		parent[n] = n;

	// 간선 정보 입력 받음
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		e[i] = { a, b, c };
	}

	// 간선을 가중치 기준으로 오름차순 정렬
	sort(e, e + M, comp);

	int result = 0;		// 가중치 합
	int cnt = 0;		// 뽑은 간선 수
	int idx = 0;		// 간선 인덱스

	while (true) {
		if (Union(e[idx].u, e[idx].v)) {
			result += e[idx].w;
			cnt++;

			// N-1개의 간선을 뽑으면 작업 끝!
			if (cnt == N - 1)
				break;
		}

		idx++;
	}

	cout << result << '\n';

	return 0;
}