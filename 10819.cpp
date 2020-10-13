#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int ans = 0, N;
vector<int> vc;
int arr[8];
bool visit[8];

void solution() {
	int sum = 0;

	for (int i = 0; i < N - 1; i++)
		sum += abs(vc[i] - vc[i + 1]);

	ans = max(ans, sum);
}

void DFS() {
	if (vc.size() == N) {
		solution();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			vc.push_back(arr[i]);

			DFS();

			vc.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	memset(visit, false, sizeof(visit));
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	DFS();

	cout << ans << '\n';

	return 0;
}