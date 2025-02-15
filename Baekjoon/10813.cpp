#include <iostream>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int *A = new int[N + 1];

	for (int i = 1; i <= N; i++)
		A[i] = i;

	for (int i = 0; i < M; i++) {
		int n1, n2, temp;
		cin >> n1 >> n2;

		temp = A[n1];

		A[n1] = A[n2];
		A[n2] = temp;
	}

	for (int i = 1; i <= N; i++)
		cout << A[i] << ' ';

	cout << endl;

	return 0;
}