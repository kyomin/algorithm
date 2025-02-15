#include <iostream>

typedef unsigned long long ll;

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		ll son, mother;
		cin >> son >> mother;

		if (son == 0 && mother == 0)
			break;

		int q = son / mother;
		int r = son % mother;

		cout << q << ' ' << r << " / " << mother << '\n';
	}

	return 0;
}