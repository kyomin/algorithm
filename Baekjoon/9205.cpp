#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100 + 2;	// ������ �ִ� 100, �����, ������

int N;
vector<int> graph[MAX];	// ���� ���
bool visited[MAX];

// ����ư �Ÿ�
int getDistance(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

// dfs
void dfs(int node) {
	visited[node] = true;	// �湮 üũ

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		
		if (!visited[next])
			dfs(next);
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		// �ʱ�ȭ
		for (int i = 0; i < MAX; i++)
			graph[i].clear();
		memset(visited, false, sizeof(visited));

		cin >> N;
		vector<pair<int, int>> coordinate;	// ��ǥ(coordinate)

		// �����: 0, ������: N+1
		for (int i = 0; i < N + 2; i++) {
			int x, y;
			cin >> x >> y;

			coordinate.push_back(make_pair(x, y));
		}

		// ���� 20������ �� �� �ִ� �Ÿ� ���� ������ �׷����� �߰�
		for (int i = 0; i < N + 2; i++) {
			for (int j = i + 1; j < N + 2; j++) {
				if (getDistance(coordinate[i], coordinate[j]) <= (50 * 20)) {
					// ����� �׷���
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		// ����� 0��������
		dfs(0);

		// ������ N+1�� �����ߴ°�?
		if (visited[N + 1])
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}

	return 0;
}