#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *A = new int[5];

	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;

		A[i] = n;
	}

	int count = 0;

	for (int i = 0; i < 5; i++)
		if (N == A[i])
			count++;

	cout << count << endl;

	return 0;
}