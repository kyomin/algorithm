#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *A = new int[N];

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		A[i] = n;
	}

	sort(A, A + N);

	for (int i = 0; i < N; i++)
		cout << A[i] << ' ';

	return 0;
}