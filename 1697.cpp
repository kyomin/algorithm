#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;	// 최대 좌표 값 지정
bool visited[MAX];	// 좌표 방문 여부 체크

int BFS(int N, int K) {
	for (int i = 0; i < MAX; i++)
		visited[i] = false;

	// first : 좌표, second : 시간
	queue<pair<int, int>> q;

	q.push(make_pair(N, 0));

	visited[N] = true;

	while (!q.empty()) {
		int n = q.front().first;
		int curSec = q.front().second;

		q.pop();

		/*
			목표 좌표에 도달했으면 함수 종료!
			이 짓을 계속해서 큐에 차곡차곡 쌓아
			가장 먼저 목표 좌표에 도달하는 것이 곧
			최소 시간을 리턴하는 것이다.
		*/
		if (n == K)
			return curSec;

		/*
			세 가지 경우의 수
			방문한 것은 큐에 넣지 않는다
		*/
		if (n - 1 >= 0 && visited[n - 1] == false) {
			q.push(make_pair(n - 1, curSec + 1));
			visited[n - 1] = true;
		}

		if (n + 1 < MAX && visited[n + 1] == false) {
			q.push(make_pair(n + 1, curSec + 1));
			visited[n + 1] = true;
		}

		if (n * 2 < MAX && visited[n * 2] == false) {
			q.push(make_pair(n * 2, curSec + 1));
			visited[n * 2] = true;
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	cout << BFS(N, K) << endl;

	return 0;
}