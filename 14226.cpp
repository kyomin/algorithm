#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int S;
int visit[1001][1001];
int ans;

void bfs() {
	queue<pair<int, pair<int, int>>> que;
	que.push(make_pair(1, make_pair(0, 0)));
	visit[1][0] = 1;

	while (!que.empty()) {
		int s = que.front().first;
		int sec = que.front().second.first;
		int clip = que.front().second.second;
		que.pop();

		if (s == S) {
			ans = sec;
			return;
		}

		if (s > 0 && s <= 1000) {
			if (visit[s][s] == 0) {
				visit[s][s] = 1;
				que.push(make_pair(s, make_pair(sec + 1, s)));
			}

			if (visit[s - 1][clip] == 0) {
				visit[s - 1][clip] = 1;
				que.push(make_pair(s - 1, make_pair(sec + 1, clip)));
			}
		}

		if (clip > 0 && s + clip <= 1000) {
			if (visit[s + clip][clip] == 0) {
				visit[s + clip][clip] = 1;
				que.push(make_pair(s + clip, make_pair(sec + 1, clip)));
			}
		}
	}
}

int main() {
	cin >> S;

	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			visit[i][j] = 0;
		}
	}

	bfs();
	cout << ans << endl;

	return 0;
}