#include <iostream>

using namespace std;

const int MAX = 100001;

int friends[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		friends[u]++;
		friends[v]++;
	}

	for (int n = 1; n <= N; n++)
		cout << friends[n] << '\n';

	return 0;
}