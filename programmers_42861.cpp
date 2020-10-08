#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v, w;
};

int parent[100];
Edge e[5000];

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

// Union(x, y) : x원소와 y원소를 합치는 함수로 y의 root 노드를 x로 한다.
bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;

		return true;
	}

	return false;
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int len = costs.size();

	// parent 배열을 자기 자신 인덱스를 root로 초기화
	for (int i = 0; i < n; i++)
		parent[i] = i;

	// 간선 정보 입력 받음
	for (int i = 0; i < len; i++)
		e[i] = { costs[i][0], costs[i][1], costs[i][2] };

	// 간선을 가중치 기준으로 오름차순 정렬
	sort(e, e + len, comp);

	int cnt = 0;	// 뽑은 간선 수
	int idx = 0;	// 간선 인덱스

	while (true) {
		if (Union(e[idx].u, e[idx].v)) {
			answer += e[idx].w;
			cnt++;

			// n-1개의 간선을 뽑으면 작업 끝!
			if (cnt == n - 1)
				break;
		}

		idx++;
	}

	return answer;
}