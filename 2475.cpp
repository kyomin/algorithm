#include <iostream>

using namespace std;

int main() {
	unsigned int sum = 0;

	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;

		sum += (n*n);
	}

	cout << sum % 10 << endl;

	return 0;
}