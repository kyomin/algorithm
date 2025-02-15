#include <iostream>

using namespace std;

int A[101];
int B[101];
int N;

int main() {
	cin >> N;

	int sum = 0;

	for (int i = 1; i <= N; i++)
		cin >> B[i];

	for (int i = 1; i <= N; i++) {
		A[i] = B[i] * i - sum;
		sum += A[i];
	}

	for (int i = 1; i <= N; i++)
		cout << A[i] << ' ';

	cout << endl;

	return 0;
}