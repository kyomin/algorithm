#include <iostream>

using namespace std;

int main() {
	unsigned long long A, B;
	cin >> A >> B;

	if (B > A) {
		cout << B - A - 1 << '\n';

		for (unsigned long long i = A + 1; i < B; i++)
			cout << i << ' ';

		cout << endl;
	}
	else if (B < A) {
		cout << A - B - 1 << '\n';

		for (unsigned long long i = B + 1; i < A; i++)
			cout << i << ' ';

		cout << endl;
	}
	else
		cout << 0 << '\n';

	return 0;
}