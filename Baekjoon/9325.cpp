#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int sum = 0;
		int car_price;
		int options;

		cin >> car_price;
		sum += car_price;

		cin >> options;

		for (int i = 0; i < options; i++) {
			int num, price;
			cin >> num >> price;
			sum += (num*price);
		}

		cout << sum << '\n';
	}
}