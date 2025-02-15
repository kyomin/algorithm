#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;

			// 첫 번째 행이라면 그냥 넣어준다
			if (i == 0)
				pq.push(n);
			else {
				// 넣어주고 힙 유지 후에
				pq.push(n);

				// 루트 pop => 수시로 최소값만 걸러진다.
				pq.pop();
			}
		}
	}

	cout << pq.top() << '\n';

	return 0;
}