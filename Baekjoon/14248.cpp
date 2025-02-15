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
	start -= 1;	// 인덱스를 맞추기 위함

	queue<pair<int, int>> q;
	q.push(make_pair(start, stones[start]));	// first: 현 인덱스, second: 점프 거리
	visited[start] = true;	// 방문 체크

	while (!q.empty()) {
		int position = q.front().first;
		int dist = q.front().second;
		q.pop();

		// 왼쪽 오른쪽 모두 고려하기 위함
		for (int i = 0; i < 2; i++) {
			dist *= (-1);
			int next_index = position + dist;

			// 범위 내에 있으면서 아직 방문하지 않았는가?
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