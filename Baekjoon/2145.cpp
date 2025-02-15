#include <iostream>

using namespace std;

int makeOneDigit(int num) {
	while (true) {
		if (num / 10 == 0)
			return num;

		int sum = 0;

		while (num / 10 != 0) {
			int q = num / 10;
			int r = num % 10;

			sum += r;
			num = q;
		}

		sum += num;

		num = sum;
	}
}

int main() {
	while (true) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		cout << makeOneDigit(n) << endl;
	}

	return 0;
}