#include <iostream>
#include <queue>
using namespace std;

int main() {
	vector<int> stones;
	vector<bool> visited;
	int cnt = 1;
	int start;
	int N;
	cin >> N;

	stones.resize(N);
	visited.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> stones[i];
		visited[i] = false;
	}

	cin >> start;
	start -= 1;	// �ε����� ���߱� ����

	queue<pair<int, int>> q;
	q.push(make_pair(start, stones[start]));	// first: �� �ε���, second: ���� �Ÿ�
	visited[start] = true;	// �湮 üũ

	while (!q.empty()) {
		int position = q.front().first;
		int dist = q.front().second;
		q.pop();

		// ���� ������ ��� ����ϱ� ����
		for (int i = 0; i < 2; i++) {
			dist *= (-1);
			int next_index = position + dist;

			// ���� ���� �����鼭 ���� �湮���� �ʾҴ°�?
			if (-1 < next_index && next_index < N && !visited[next_index]) {
				visited[next_index] = true;
				q.push(make_pair(next_index, stones[next_index]));
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}