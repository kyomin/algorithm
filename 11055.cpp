#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *A = new int[N + 1];
	int *D = new int[N + 1];

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	D[1] = A[1];

	for (int i = 2; i <= N; i++) {
		int temp = A[i];
		D[i] = A[i];

		for (int j = 1; j < i; j++)
			if (A[j]<A[i] && D[j] + temp > D[i])
				D[i] = D[j] + temp;
	}

	int result = D[1];

	for (int i = 2; i <= N; i++)
		if (D[i] > result)
			result = D[i];

	cout << result << endl;

	return 0;
}