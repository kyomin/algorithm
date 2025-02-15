#include <iostream>
#include <vector>

using namespace std;

vector<int> vc;
int N;
int ans = 0;

void dfs(int cnt) {
	if (vc.size() == 2) {
		int sum = 0;

		for (auto num : vc)
			sum += num;

		ans += sum;

		return;
	}

	for (int i = cnt; i <= N; i++) {
		if (vc.size() < 2) {
			vc.push_back(i);
			dfs(i + 1);
			vc.pop_back();
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		ans += (i * 2);

	dfs(0);

	cout << ans << '\n';

	return 0;
}