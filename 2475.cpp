#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	unsigned int sum = 0;

	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;

		sum += (n*n);
	}

	cout << sum % 10 << endl;

	return 0;
}