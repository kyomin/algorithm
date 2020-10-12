#include <iostream>

using namespace std;

int main() {
	int init = 5;
	int sum = 0;
	int N;
	cin >> N;

	while (init <= N) {
		sum += N / init;

		init *= 5;
	}

	cout << sum << endl;

	return 0;
}