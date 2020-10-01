#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vc;
int ans = 0;

void dfs(int cnt) {
	if (vc.size() == 2) {
		int a = vc[0];
		int b = vc[1];

		int numerator = (a*a) + (b*b) + m;
		int denominator = a * b;

		if (numerator%denominator == 0)
			ans++;

		return;
	}

	for (int i = cnt; i < n; i++) {
		if (vc.size() < 2) {
			vc.push_back(i);
			dfs(i + 1);
			vc.pop_back();
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n >> m;
		ans = 0;

		dfs(1);

		cout << ans << '\n';
	}

	return 0;
}