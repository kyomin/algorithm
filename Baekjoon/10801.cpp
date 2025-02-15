#include <iostream>

using namespace std;

int check[2];		// 0 : A, 1 : B
int A[10];
int B[10];

int main() {
	for (int i = 0; i < 10; i++)
		cin >> A[i];

	for (int i = 0; i < 10; i++)
		cin >> B[i];

	for (int i = 0; i < 10; i++) {
		if (A[i] > B[i]) {
			check[0]++;
			continue;
		}

		if (B[i] > A[i]) {
			check[1]++;
			continue;
		}
	}

	if (check[0] > check[1])
		cout << 'A' << '\n';
	else if (check[1] > check[0])
		cout << 'B' << '\n';
	else
		cout << 'D' << '\n';

	return 0;
}