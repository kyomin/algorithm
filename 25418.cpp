#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;

int visit[MAX];	// start -> end���� �ʿ��� �ּ� ���� Ƚ��

int main() {
	queue<int> q;
	int ans;
	int start, end;
	cin >> start >> end;

	q.push(start);

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (n == end) {
			ans = visit[n];
			break;
		}
		
		if (n + 1 <= MAX && !visit[n + 1]) {
			q.push(n + 1);
			visit[n + 1] = visit[n] + 1;
		}

		if (n * 2 <= MAX && !visit[n * 2]) {
			q.push(n * 2);
			visit[n * 2] = visit[n] + 1;
		}
	}

	cout << ans << endl;

	return 0;
}