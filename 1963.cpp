#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

bool prime[10000];	// false면 소수

string start, target;

// 9999까지의 소수를 구한다.
void eratosthenes() {
	for (int i = 2; i <= 9999; i++) {
		if (!prime[i]) {
			for (int j = i * i; j <= 9999; j+=i)
				prime[j] = true;
		}
	}
}

int bfs() {
	queue<pair<string, int>> q;

	q.push({ start, 0 });

	map<string, bool> visited;

	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (cur == target)
			return cnt;

		// 아직 방문 안 한 경우
		if (!visited[cur]) {
			visited[cur] = true;

			// 모든 경우를 다 해본다.
			for (int i = 0; i < 4; i++) {
				string temp = cur;

				for (int n = 0; n <= 9; n++) {
					temp[i] = (char)('0' + n);

					if (temp[0] == '0')
						continue;

					int num = atoi(temp.c_str());

					// 소수라면
					if (!prime[num])
						q.push({ temp, cnt + 1 });
				}
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	eratosthenes();

	for (int t = 0; t < T; t++) {
		cin >> start >> target;

		int ans = bfs();

		if (ans != -1)
			cout << ans << '\n';
		else
			cout << "Impossible" << '\n';
	}

	return 0;
}