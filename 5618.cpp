#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int *A = new int[n];

	for (int i = 0; i < n; i++)
		cin >> A[i];

	int minimum;

	if (n == 2)
		minimum = min(A[0], A[1]);

	if (n == 3)
		minimum = min(min(A[0], A[1]), A[2]);

	if (n == 2) {
		for (int i = 1; i <= minimum; i++)
			if (A[0] % i == 0 && A[1] % i == 0)
				cout << i << '\n';

		cout << '\n';
	}
	else {
		for (int i = 1; i <= minimum; i++)
			if (A[0] % i == 0 && A[1] % i == 0 && A[2] % i == 0)
				cout << i << '\n';

		cout << '\n';
	}

	return 0;
}