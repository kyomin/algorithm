#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
bool visited[1000001] = { false, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> F >> S >> G >> U >> D;

	// first : 층, second : 시간
	queue<pair<int, int>> q;

	// 처음 시작 층!
	q.push(make_pair(S, 0));

	visited[S] = true;

	while (!q.empty()) {
		int n = q.front().first;
		int curCount = q.front().second;

		q.pop();

		if (n == G) {
			cout << curCount << '\n';
			return 0;
		}

		/*
			문제의 두 가지 경우의 수.
			방문한 것은 큐에 넣지 않는다.
		*/
		if (n + U <= F && !visited[n + U]) {
			q.push(make_pair(n + U, curCount + 1));
			visited[n + U] = true;
		}

		if (n - D >= 1 && !visited[n - D]) {
			q.push(make_pair(n - D, curCount + 1));
			visited[n - D] = true;
		}
	}

	// 탐색을 다 했는데도 해를 못 찾았으면
	cout << "use the stairs" << '\n';

	return 0;
}