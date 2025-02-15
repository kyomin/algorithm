#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m = 6;
vector<int> vc;
vector<int> arr;

void dfs(int cnt) {
	if (vc.size() == m) {
		for (auto i : vc)
			printf("%d ", i);

		printf("\n");
		return;
	}

	for (int i = cnt; i < n; i++) {
		if (vc.size() < m) {
			vc.push_back(arr[i]);
			dfs(i + 1);
			vc.pop_back();
		}
	}
}

int main() {
	while (true) {
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			int N;
			cin >> N;

			arr.push_back(N);
		}

		dfs(0);

		cout << '\n';

		arr.clear();
		vc.clear();
	}

	return 0;
}