#include <iostream>

using namespace std;

int main() {
	int L, P;
	int arr[5];

	cin >> L >> P;

	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	int total = L * P;

	for (int i = 0; i < 5; i++)
		cout << arr[i] - total << ' ';

	cout << '\n';

	return 0;
}