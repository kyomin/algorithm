#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int A[6] = { 500, 100, 50, 10, 5, 1 };
	int count = 0;

	N = 1000 - N;

	for (int i = 0; i < 6; i++) {
		if (N == 0)
			break;

		int num = N / A[i];

		N -= (A[i] * num);

		count += num;
	}

	cout << count << endl;

	return 0;
}