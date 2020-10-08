#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v, w;
};

int parent[100];
Edge e[5000];

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

// Union(x, y) : x���ҿ� y���Ҹ� ��ġ�� �Լ��� y�� root ��带 x�� �Ѵ�.
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

	// parent �迭�� �ڱ� �ڽ� �ε����� root�� �ʱ�ȭ
	for (int i = 0; i < n; i++)
		parent[i] = i;

	// ���� ���� �Է� ����
	for (int i = 0; i < len; i++)
		e[i] = { costs[i][0], costs[i][1], costs[i][2] };

	// ������ ����ġ �������� �������� ����
	sort(e, e + len, comp);

	int cnt = 0;	// ���� ���� ��
	int idx = 0;	// ���� �ε���

	while (true) {
		if (Union(e[idx].u, e[idx].v)) {
			answer += e[idx].w;
			cnt++;

			// n-1���� ������ ������ �۾� ��!
			if (cnt == n - 1)
				break;
		}

		idx++;
	}

	return answer;
}