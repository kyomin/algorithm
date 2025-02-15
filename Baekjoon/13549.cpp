#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int N, K;
int visited[100001] = { 0 };
int ans = 0;

void bfs() {
	deque<pair<int, int>> que;
	que.push_back(make_pair(0, N));
	visited[N] = 1;

	while (!que.empty()) {
		int nowTime = que.front().first;
		int nowLoc = que.front().second;
		que.pop_front();

		if (nowLoc == K) {
			ans = nowTime;
			return;
		}

		// 순간이동 -> 앞/뒤 이동보다 먼저 써줘야한다.
		if (!visited[2 * nowLoc] && 0 <= 2 * nowLoc && 2 * nowLoc <= 100000) {
			visited[2 * nowLoc] = 1;
			que.push_front(make_pair(nowTime, 2 * nowLoc));
		}

		// 뒤로 이동
		if (!visited[nowLoc - 1] && 0 <= nowLoc - 1 && nowLoc - 1 <= 100000) {
			visited[nowLoc - 1] = 1;
			que.push_back(make_pair(nowTime + 1, nowLoc - 1));
		}
		
		// 앞으로 이동
		if (!visited[nowLoc + 1] && 0 <= nowLoc + 1 && nowLoc + 1 <= 100000) {
			visited[nowLoc + 1] = 1;
			que.push_back(make_pair(nowTime + 1, nowLoc + 1));
		}
	}
}

int main() {
	cin >> N >> K;
	bfs();
	cout << ans << endl;

	return 0;
}