#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> arr;
vector<int> vc;

void dfs(int cnt) {
	if (vc.size() == M) {
		for (auto i : vc)
			cout << i << ' ';

		cout << '\n';

		return;
	}

	for (int start = cnt; start < N; start++) {
		if (vc.size() < M) {
			vc.push_back(arr[start]);

			dfs(start);

			vc.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	arr.resize(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	dfs(0);

	return 0;
}