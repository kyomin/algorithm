#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<ll> budget_req;
	ll total_budget;
	ll N;
	cin >> N;

	budget_req.resize(N);

	for (int i = 0; i < N; i++)
		cin >> budget_req[i];

	cin >> total_budget;

	sort(budget_req.begin(), budget_req.end());

	ll ans = 1;
	ll start = 1;
	ll end = budget_req[N - 1];
	ll mid = (start + end) / 2;

	while (start <= end) {
		ll sum = 0;

		for (auto budget : budget_req) {
			if (budget < mid)
				sum += budget;
			else
				sum += mid;
		}

		if (sum <= total_budget) {
			ans = max(ans, mid);
			start = mid + 1;
			mid = (start + end) / 2;
		}
		else {
			end = mid - 1;
			mid = (start + end) / 2;
		}
	}

	cout << ans << '\n';

	return 0;
}