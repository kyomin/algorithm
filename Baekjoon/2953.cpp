#include <iostream>

using namespace std;

int arr[6];

int main() {
	for (int i = 1; i <= 5; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[i] = a + b + c + d;
	}

	int max = arr[1], max_idx = 1;

	for (int i = 2; i <= 5; i++) {
		if (max < arr[i]) {
			max = arr[i];
			max_idx = i;
		}
	}

	cout << max_idx << ' ' << max << endl;

	return 0;
}