#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

set<string> results;
vector<int> vc;

int arr[10];
bool visit[10];

int n, k;

void dfs() {
	if (vc.size() == k) {
		string result = "";

		for (auto num : vc)
			result += to_string(num);

		results.insert(result);

		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			vc.push_back(arr[i]);

			dfs();

			vc.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dfs();

	cout << results.size() << '\n';

	return 0;
}