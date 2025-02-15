#include <iostream>
#include <vector>

using namespace std;

vector<int> vc;
int N, M, S;
int arr[21];
int cnt = 0;

void dfs(int count) {
	if (vc.size() == M) {
		int sum = 0;

		for (auto i : vc)
			sum += i;

		if (sum == S)
			cnt++;

		return;
	}

	for (int i = count; i < N; i++) {
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

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		M = i;
		dfs(0);
		vc.clear();
	}

	cout << cnt << endl;

	return 0;
}