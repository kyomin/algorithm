#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> arr;
vector<int> vc;

void dfs() {
	if (vc.size() == M) {
		for (auto num : vc)
			cout << num << ' ';

		cout << '\n';

		return;
	}

	for (int i = 0; i < N; i++) {
		vc.push_back(arr[i]);

		dfs();

		vc.pop_back();
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

	dfs();

	return 0;
}