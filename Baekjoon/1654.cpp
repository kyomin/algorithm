#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll lan[10000];
ll K, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K >> N;
	
	for (int i = 0; i < K; i++)
		cin >> lan[i];

	sort(lan, lan + K);

	ll ans = 1;
	ll start = 1;
	ll end = lan[K - 1];
	ll mid = (start + end) / 2;

	while (start <= end) {
		ll lan_cnt = 0;

		for (int i = 0; i < K; i++)
			lan_cnt += (lan[i] / mid);
		
		if (lan_cnt < N) {
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else if (lan_cnt >= N) {
			ans = max(ans, mid);
			start = mid + 1;
			mid = (start + end) / 2;
		}
	}

	cout << ans << '\n';

	return 0;
}