#include <iostream>
using namespace std;

typedef unsigned long long ll;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	ll sum = 0;
	ll N;
	cin >> N;

	ll rangeSum = (N*(N - 1)) / 2;

	for (int i = 0; i < N; i++) {
		ll num;
		cin >> num;

		sum += num;
	}

	cout << sum - rangeSum << '\n';

	return 0;
}