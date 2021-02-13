#include <iostream>

using namespace std;

int coins[8] = {
	50000,
	10000,
	5000,
	1000,
	500,
	100,
	50,
	10
};
int coin_nums[8];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		for (int i = 0; i < 8; i++) {
			int coin = coins[i];
			int q = N / coin;
			int r = N % coin;

			coin_nums[i] = q;
			N = r;
		}

		cout << '#' << t << '\n';

		for (int i = 0; i < 7; i++)
			cout << coin_nums[i] << ' ';

		cout << coin_nums[7] << '\n';
	}

	return 0;
}