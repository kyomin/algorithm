#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n == 0) {
			// 큐가 비어있다면!
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(n);
	}

	return 0;
}