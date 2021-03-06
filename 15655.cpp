#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

vector<int> arr;
vector<int> vc;

void dfs(int cnt) {
	if (vc.size() == M) {
		for (auto num : vc)
			cout << num << ' ';

		cout << '\n';

		return;
	}

	for (int i = cnt; i < N; i++) {
		if (vc.size() < M) {
			vc.push_back(arr[i]);

			dfs(i + 1);

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