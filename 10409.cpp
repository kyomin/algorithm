#include <iostream>

using namespace std;

int main() {
	int count = 0;
	int sum = 0;
	int n, T;
	cin >> n >> T;

	int *A = new int[n];

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		A[i] = num;
	}

	for (int i = 0; i < n; i++) {
		if (sum + A[i] > T)
			break;

		sum += A[i];
		count++;
	}

	cout << count << endl;

	return 0;
}