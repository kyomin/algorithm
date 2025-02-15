#include <iostream>

using namespace std;

typedef unsigned long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	ll ans = 0;

	for (int i = 1; i < N; i++)
		ans += (N*i) + i;

	cout << ans << '\n';

	return 0;
}