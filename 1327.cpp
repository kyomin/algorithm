#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;

int bfs(string arr) {
	// first : ������� ����, second : �������������� Ƚ��
	queue<pair<string, int>> q;

	q.push({ arr, 0 });

	// �ش� ���ڿ��� ���� ���� �ִ����� ����
	map<string, bool> visited;

	string target = arr;

	// ������������ �����
	sort(target.begin(), target.end());

	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;

		q.pop();

		// �ظ� ã�� ��� �ٷ� �����ϸ� �Լ� ����!
		if (cur == target)
			return cnt;

		// ���� �湮 �� �� ���
		if (!visited[cur]) {
			visited[cur] = true;

			// ��� ��츦 �� �غ���.
			for (int start = 0; start <= N - K; start++) {
				string temp = cur.substr(start, K);

				reverse(temp.begin(), temp.end());

				// start���� K���� ���ڸ� ������ �����´�.
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