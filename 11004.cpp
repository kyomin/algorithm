#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int *A = new int[n];

	k -= 1;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		A[i] = num;
	}

	nth_element(A, A + k, A + n);

	cout << A[k] << '\n';

	return 0;
}