#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		double price;
		cin >> price;
		price = price * (0.8);

		cout << '$' << round(price * 100) / 100 << endl;
	}

	return 0;
}