#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N, K;
int visited[100001];
queue<int> que;
vector<int> resVec;

void bfs() {
	que.push(N);

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		if (now == K) {
			resVec.push_back(now);
			while (visited[now] != 100001) {
				resVec.push_back(visited[now]);
				now = visited[now];
			}
			return;
		}

		if (visited[now - 1] == -1 && 0 <= now - 1 && now - 1 <= 100000) {
			visited[now - 1] = now;
			que.push(now - 1);
		}

		if (visited[now + 1] == -1 && 0 <= now + 1 && now + 1 <= 100000) {
			visited[now + 1] = now;
			que.push(now + 1);
		}
		
		if (visited[2 * now] == -1 && 0 <= 2 * now && 2 * now <= 100000) {
			visited[2 * now] = now;
			que.push(2 * now);
		}
	}
}

int main() {
	cin >> N >> K;
	memset(visited, -1, sizeof(visited));
	visited[N] = 100001;

	bfs();
	cout << resVec.size() - 1 << "\n";

	for (int i = resVec.size() - 1; i >= 0; i--) {
		printf("%d ", resVec[i]);
	}

	return 0;
}