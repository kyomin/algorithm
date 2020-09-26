#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> vc;
bool c[1121];

vector<int> p;	// 소수 저장
int pn;		// 소수의 개수

int n, k;
long long ans;

void dfs(int cnt) {
	if (vc.size() == k) {
		int sum = 0;
		
		for (auto num : vc)
			sum += num;

		if (sum == n)
			ans++;
		
		return;
	}

	for (int i = cnt; i < pn; i++) {
		if (vc.size() < k) {
			vc.push_back(p[i]);
			dfs(i + 1);
			vc.pop_back();
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n >> k;

		p.clear();
		pn = 0;
		ans = 0;

		memset(c, false, sizeof(c));

		for (int i = 2; i <= n; i++) {
			if (!c[i]) {
				p.push_back(i);
				pn++;

				for (int j = i * i; j <= n; j += i)
					c[j] = true;
			}
		}

		dfs(0);

		cout << ans << '\n';
	}

	return 0;
}