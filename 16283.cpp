#include <iostream>

using namespace std;

int main() {
	int a, b, n, w;
	cin >> a >> b >> n >> w;

	int sheep, goat;
	int count = 0;

	for (int i = 1; i < n; i++) {
		if ((i*a) + ((n - i)*b) == w) {
			sheep = i;
			goat = n - i;
			count++;
		}
	}

	if (count == 1)
		cout << sheep << ' ' << goat << endl;
	else
		cout << -1;

	return 0;
}