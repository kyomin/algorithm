#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool check[101] = { false, };
int dist[101] = { 0, };

/*
	�ش� ��� ����
	first : ����, second : ������ ������ �ɺ� �������� ��
*/
vector<pair<int, int>> answer;
vector<int> vt[101];	// ���� ����Ʈ


bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second < p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

// ���� ���� �ʱ�ȭ �Լ�
void Init() {
	for (int i = 1; i <= 100; i++) {
		check[i] = false;
		dist[i] = 0;
	}
}

// BFS Ž��
void BFS(int node) {
	queue<int> q;
	q.push(node);
	check[node] = true;

	while (!q.empty()) {
		int n = q.front();

		q.pop();

		for (int i = 0; i < vt[n].size(); i++) {
			if (!check[vt[n][i]]) {
				q.push(vt[n][i]);
				dist[vt[n][i]] = dist[n] + 1;
				check[vt[n][i]] = true;
			}
		}
	}

	int sum = 0;

	for (int i = 1; i <= N; i++)
		sum += dist[i];

	answer.push_back(make_pair(node, sum));
}

int main() {
	cin >> N >> M;

	// ���� ����Ʈ �ʱ�ȭ
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		vt[u].push_back(v);
		vt[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		Init();
		BFS(i);
	}

	sort(answer.begin(), answer.end(), comp);

	cout << answer[0].first << endl;

	return 0;
}