#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;

int bfs(string arr) {
	// first : 만들어진 순열, second : 만들어지기까지의 횟수
	queue<pair<string, int>> q;

	q.push({ arr, 0 });

	// 해당 문자열을 만든 적이 있는지의 여부
	map<string, bool> visited;

	string target = arr;

	// 오름차순으로 만들기
	sort(target.begin(), target.end());

	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;

		q.pop();

		// 해를 찾은 경우 바로 리턴하며 함수 종료!
		if (cur == target)
			return cnt;

		// 아직 방문 안 한 경우
		if (!visited[cur]) {
			visited[cur] = true;

			// 모든 경우를 다 해본다.
			for (int start = 0; start <= N - K; start++) {
				string temp = cur.substr(start, K);

				reverse(temp.begin(), temp.end());

				// start부터 K개의 문자를 선택해 뒤집는다.
				q.push({
					cur.substr(0, start) + temp + cur.substr(start + K, cur.size()),
					cnt + 1
				});
			}

		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	string arr = "";

	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;

		arr += c;
	}

	cout << bfs(arr) << '\n';

	return 0;
}