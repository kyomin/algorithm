#include <iostream>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int arr[3];
	int num = 100;
	int temp = B;

	for (int i = 0; i < 3; i++) {
		arr[i] = B / num;
		B %= num;
		num /= 10;
	}

	for (int i = 2; i >= 0; i--)
		cout << arr[i] * A << '\n';

	cout << A * temp << '\n';

	return 0;
}