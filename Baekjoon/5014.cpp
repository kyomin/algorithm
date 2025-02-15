#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
bool visited[1000001] = { false, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> F >> S >> G >> U >> D;

	// first : ��, second : �ð�
	queue<pair<int, int>> q;

	// ó�� ���� ��!
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
			������ �� ���� ����� ��.
			�湮�� ���� ť�� ���� �ʴ´�.
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

	// Ž���� �� �ߴµ��� �ظ� �� ã������
	cout << "use the stairs" << '\n';

	return 0;
}