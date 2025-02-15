#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ll N, M;
	cin >> N >> M;

	ll ans = N - M;

	if (ans < 0)
		cout << (ans*(-1)) << endl;
	else
		cout << ans << endl;

	return 0;
}