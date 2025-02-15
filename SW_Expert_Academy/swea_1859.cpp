#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ll;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<ll> selling_prices;
		int N;
		cin >> N;

		selling_prices.resize(N);

		for (int i = 0; i < N; i++)
			cin >> selling_prices[i];

		ll max_price = selling_prices[N - 1];
		ll max_benefit = 0;

		for (int i = N - 1; i >= 0; i--) {
			ll cur_price = selling_prices[i];

			if (cur_price < max_price) {
				max_benefit += (max_price - cur_price);
				continue;
			}

			max_price = cur_price;
		}

		cout << '#' << t << ' ' << max_benefit << '\n';
	}

	return 0;
}