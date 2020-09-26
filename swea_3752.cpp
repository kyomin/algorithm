#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;

vector<int> vc;
vector<int> arr;
set<int> possibleNums;

void dfs(int cnt) {
	if (vc.size() == M) {
		int sum = 0;

		for (auto num : vc) {
			sum += num;
		}

		possibleNums.insert(sum);

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
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		arr.clear();
		arr.resize(N);

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		vc.clear();
		possibleNums.clear();

		for (int i = 0; i <= N; i++) {
			M = i;

			dfs(0);
		}

		cout << '#' << t << ' ' << possibleNums.size() << '\n';
	}

	return 0;
}