#include <iostream>

using namespace std;

typedef unsigned long long ll;

int main() {
	int N;
	cin >> N;

	ll ans = 0;

	for (int i = 1; i < N; i++) {
		ans += (N*i) + i;
	}

	cout << ans << '\n';

	return 0;
}