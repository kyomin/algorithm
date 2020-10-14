#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	unsigned long N;
	cin >> N;

	int *A = new int[10001];

	for (int i = 1; i <= 10000; i++)
		A[i] = 0;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		A[n]++;
	}

	for (int i = 1; i <= 10000; i++)
		if (A[i] > 0)
			for (int j = 0; j < A[i]; j++)
				cout << i << '\n';

	return 0;
}