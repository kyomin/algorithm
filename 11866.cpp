#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, K;
	queue<int> q;
	vector<int> result;

	cin >> N >> K;

	for (int n = 1; n <= N; n++)
		q.push(n);

	while (!q.empty()) {
		for (int k = 0; k < K - 1; k++) {
			int n = q.front();
			q.pop();
			q.push(n);
		}

		int n = q.front();
		q.pop();
		result.push_back(n);
	}

	cout << '<';

	for (int i = 0; i < N - 1; i++) {
		cout << result[i] << ", ";
	}

	cout << result[N - 1] << '>' << '\n';

	return 0;
}