#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	queue<int> q;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() != 1) {
		q.pop();
		int x = q.front();
		q.pop();
		q.push(x);
	}

	cout << q.front() << '\n';

	return 0;
}