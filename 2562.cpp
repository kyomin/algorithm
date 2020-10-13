#include <iostream>

using namespace std;

int main() {
	int A[9];

	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;

		A[i] = n;
	}

	int max = A[0];
	int idx = 1;

	for (int i = 1; i < 9; i++) {
		if (max < A[i]) {
			max = A[i];
			idx = i + 1;
		}
	}

	cout << max << '\n' << idx << '\n';

	return 0;
}